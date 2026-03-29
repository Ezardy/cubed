#ifndef T_GAME_H
# define T_GAME_H

# include "c3d_math/t_vec.h"
# include "c3d_math/t_mat.h"
# include "error/t_err.h"
# include "raycast/t_rayhit.h"
# include "t_render.h"
# include "t_input.h"

typedef struct s_game
{
	bool		p_on;
	t_input		inputs;
	t_vec		ppos;
	t_vec		prot;
	t_vec		cam;
	long		timer;
	long		deltaTime;
	t_rayhit	door_hit;
	t_mat		*map;
	t_mat		states;
	t_render	r;
	t_err		e;
}	t_game;
#endif
