#include "t_vec.h"
#include "t_ivec.h"
#include "t_mat.h"

void	set_vec(t_vec *v, double x, double y)
{
	v->x = x;
	v->y = y;
}

void	set_ivec(t_ivec *v, int x, int y)
{
	v->x = x;
	v->y = y;
}

void	set_mat(t_mat *mat, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < mat->h)
	{
		j = 0;
		while (j < mat->w)
		{
			mat->m[i][j] = c;
			j += 1;
		}
		i += 1;
	}
}
