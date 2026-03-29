#ifndef T_RAYHIT_H
# define T_RAYHIT_H

# include "c3d_math/t_ivec.h"
# include "c3d_math/t_vec.h"

typedef struct s_rayhit
{
	t_ivec	idx;
	t_vec	pos;
	double	dist;
	double	v_cord;
	char	type;
	char	side;
}	t_rayhit;
#endif
