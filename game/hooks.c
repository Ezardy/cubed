#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>

#include "hooks.h"
#include "game/game.h"
#include "raycast/t_rayhit.h"
#include "t_game.h"
#include "c3d_math/t_vec.h"
#include "error/error.h"
#include "mlx.h"
#include "config.h"

void		free_game(t_render *r, t_mat *map, t_mat *states);
int			exit_game(t_game *game);
void		rotate(t_game *game, double cos_v, double sin_v);
void		move(t_game *game, double mdx, double mdy);

static void	switch_pointer(t_game *game);
static bool	mouse_look(t_game *game);
static long	get_time();
void		door_handle(t_game *game);

int	loop_hook(t_game *game)
{
	const int	frame_time = 1000000 / FPS_LIMIT;
	const int	door_frame_time = 1000 * DOOR_ANIM_TIME_MS / frame_time / DOOR_FRAMES_COUNT + 1;

	static long		last = 0;
	long	elapsed = get_time() - last;
	if (elapsed < frame_time)
		usleep(frame_time - elapsed);
	long time = get_time();
	game->deltaTime = time - last;
	last = time;
	bool	need_update = mouse_look(game);
	if (game->door_hit.type == 'D' && \
	game->states.m[game->door_hit.idx.y][game->door_hit.idx.x] != 9 && \
	game->states.m[game->door_hit.idx.y][game->door_hit.idx.x] != 0)
	{
		game->timer++;
		if (game->timer % door_frame_time == 0)
		{
			game->states.m[game->door_hit.idx.y][game->door_hit.idx.x]++;
			need_update = true;
		}
	}
	else if (game->door_hit.type == '0' && \
	game->states.m[game->door_hit.idx.y][game->door_hit.idx.x] != 0)
	{
		game->timer--;
		if (game->timer % door_frame_time == 0)
		{
			game->states.m[game->door_hit.idx.y][game->door_hit.idx.x]--;
			need_update = true;
		}
	}
	char	hor = game->inputs.right - game->inputs.left;
	char	ver = game->inputs.forward - game->inputs.backward;
	need_update |= hor || ver;
	if (ver) {
		if (hor) {
			if (hor > 0) {
				if (ver > 0)
					move(game, (game->prot.x + game->prot.y) * DIAGONAL_COS, (game->prot.y - game->prot.x) * DIAGONAL_COS);
				else
					move(game, (game->prot.y - game->prot.x) * DIAGONAL_COS, -(game->prot.x + game->prot.y) * DIAGONAL_COS);
			} else if (ver > 0)
				move(game, (game->prot.x - game->prot.y) * DIAGONAL_COS, (game->prot.x + game->prot.y) * DIAGONAL_COS);
			else
				move(game, -(game->prot.x + game->prot.y) * DIAGONAL_COS, (game->prot.x - game->prot.y) * DIAGONAL_COS);
		} else if (ver > 0)
			move(game, game->prot.x, game->prot.y);
		else
			move(game, -game->prot.x, -game->prot.y);
	} else if (hor > 0)
		move(game, game->prot.y, -game->prot.x);
	else if (hor < 0)
		move(game, -game->prot.y, game->prot.x);
	if (need_update) {
		render(game);
		draw_minimap(game);
	}
	return (0);
}

static long	get_time() {
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

static bool	mouse_look(t_game *game)
{
	bool	camera_updated;
	int		x;
	int		y;

	camera_updated = false;
	if (!game->p_on)
	{
		mlx_mouse_get_pos(game->r.mlx, game->r.win, &x, &y);
		x -= WIN_WIDTH / 2;
		if (x)
		{
			double	shift = x * MOUSE_SENSIVITY * game->deltaTime / 1000000;
			if (shift > 0 && shift > MAX_ANGLE_SHIFT)
				shift = MAX_ANGLE_SHIFT;
			else if (shift < 0 && shift < -MAX_ANGLE_SHIFT)
				shift = -MAX_ANGLE_SHIFT;
			camera_updated = true;
			rotate(game, cos(shift), -sin(shift));
			mlx_mouse_move(game->r.mlx, game->r.win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		}
	}
	return (camera_updated);
}

int	key_hook_press(int keycode, t_game *game)
{
	switch (keycode) {
		case ESCAPE:
			exit_game(game);
			break;
		case LEFT_ARROW:
			rotate(game, ROTATION_RESOLUTION_COS, ROTATION_RESOLUTION_SIN);
			break;
		case RIGHT_ARROW:
			rotate(game, ROTATION_RESOLUTION_COS, -ROTATION_RESOLUTION_SIN);
			break;
		case ANSI_W:
			game->inputs.forward = true;
			break;
		case ANSI_S:
			game->inputs.backward = true;
			break;
		case ANSI_A:
			game->inputs.left = true;
			break;
		case ANSI_D:
			game->inputs.right = true;
			break;
		case ANSI_P:
			switch_pointer(game);
			break;
		case ANSI_E:
			door_handle(game);
			break;
		default:
			break;
	}
	return (0);
}

int	key_hook_release(int keycode, t_game *game)
{
	switch (keycode) {
		case LEFT_ARROW:
			game->inputs.rotate_left = false;
			break;
		case RIGHT_ARROW:
			game->inputs.rotate_right = false;
			break;
		case ANSI_W:
			game->inputs.forward = false;
			break;
		case ANSI_S:
			game->inputs.backward = false;
			break;
		case ANSI_A:
			game->inputs.left = false;
			break;
		case ANSI_D:
			game->inputs.right = false;
			break;
		default:
			break;
	}
	return (0);
}

static void	switch_pointer(t_game *game)
{
	if (game->p_on)
	{
		mlx_mouse_move(game->r.mlx, game->r.win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		mlx_mouse_hide(game->r.mlx, game->r.win);
		game->p_on = false;
	}
	else
	{
		mlx_mouse_show(game->r.mlx, game->r.win);
		game->p_on = true;
	}
}

int	exit_game(t_game *game)
{
	free_game(&game->r, game->map, &game->states);
	print_trace(&game->e);
	exit(game->e.error);
}
