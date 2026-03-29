#ifndef T_COLOR_SIDES_H
# define T_COLOR_SIDES_H

# include "t_rgb.h"

typedef struct s_color_sides
{
	int		north_found : 1;
	int		south_found : 1;
	int		west_found : 1;
	int		east_found : 1;
	int		floor_found : 1;
	int		ceiling_found : 1;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	t_rgb	floor_color;
	t_rgb	ceiling_color;
}			t_color_sides;
#endif