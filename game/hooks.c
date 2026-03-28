/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:23:15 by zanikin           #+#    #+#             */
/*   Updated: 2024/10/13 21:37:28 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <unistd.h>

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
void		door_handle(t_game *game);

int	loop_hook(t_game *game)
{
	bool	need_update = mouse_look(game);
	if (game->door_hit.type == 'D' && \
	game->states.m[game->door_hit.idx.y][game->door_hit.idx.x] != 9 && \
	game->states.m[game->door_hit.idx.y][game->door_hit.idx.x] != 0)
	{
		game->timer++;
		if (game->timer % 200 == 0)
		{
			game->states.m[game->door_hit.idx.y][game->door_hit.idx.x]++;
			need_update = true;
		}
	}
	else if (game->door_hit.type == '0' && \
	game->states.m[game->door_hit.idx.y][game->door_hit.idx.x] != 0)
	{
		game->timer--;
		if (game->timer % 200 == 0)
		{
			game->states.m[game->door_hit.idx.y][game->door_hit.idx.x]--;
			need_update = true;
		}
	}
	if (need_update || game->moved) {
		render(game);
		draw_minimap(game);
		game->moved = false;
	}
	return (0);
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
			camera_updated = true;
			rotate(game, cos(x * MOUSE_SENSIVITY), -sin(x * MOUSE_SENSIVITY));
			mlx_mouse_move(game->r.mlx, game->r.win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		}
	}
	return (camera_updated);
}

int	key_hook(int keycode, t_game *game)
{
	game->moved = true;
	if (keycode == ESCAPE)
		exit_game(game);
	else if (keycode == LEFT_ARROW)
		rotate(game, ROTATION_RESOLUTION_COS, ROTATION_RESOLUTION_SIN);
	else if (keycode == RIGHT_ARROW)
		rotate(game, ROTATION_RESOLUTION_COS, -ROTATION_RESOLUTION_SIN);
	else if (keycode == ANSI_W)
		move(game, game->prot.x, game->prot.y);
	else if (keycode == ANSI_S)
		move(game, -game->prot.x, -game->prot.y);
	else if (keycode == ANSI_A)
		move(game, -game->prot.y, game->prot.x);
	else if (keycode == ANSI_D)
		move(game, game->prot.y, -game->prot.x);
	else {
		game->moved = false;
		if (keycode == ANSI_P)
			switch_pointer(game);
		else if (keycode == ANSI_E)
			door_handle(game);
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
