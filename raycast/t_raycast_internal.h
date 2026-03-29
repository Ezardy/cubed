#ifndef T_RAYCAST_INTERNAL_H
# define T_RAYCAST_INTERNAL_H

# include <stdbool.h>

# include "c3d_math/t_segment.h"
# include "c3d_math/t_ivec.h"

typedef struct s_raycast_internal
{
	t_ivec	step;
	char	symb;
	t_vec	cross;
	t_vec	cx;
	t_vec	cy;
	t_vec	k;
	double	sdx;
	double	sdy;
	int		i;
}	t_raycast_internal;
#endif
