#ifndef T_CUB_H
# define T_CUB_H

# include "c3d_math/t_ivec.h"
# include "c3d_math/t_mat.h"
# include "common/t_color_sides.h"
# include "game/config.h"

typedef struct s_cub
{
	t_color_sides	col_sides;
	int				fd;
	char			*name;
	char			orientation;
	char			**map;
	t_ivec			init_pos;
	t_mat			mat;
}			t_cub;
#endif