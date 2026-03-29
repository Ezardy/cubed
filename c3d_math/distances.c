#include <math.h>

#include "t_vec.h"

double	square_distance(const t_vec *p1, const t_vec *p2)
{
	double	x;
	double	y;

	x = p1->x - p2->x;
	y = p1->y - p2->y;
	return (x * x + y * y);
}

double	distance(const t_vec *p1, const t_vec *p2)
{
	return (sqrtf(square_distance(p1, p2)));
}
