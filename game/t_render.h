#ifndef T_RENDER_H
# define T_RENDER_H

# include "config.h"
# include "t_texture.h"

typedef struct s_render
{
	void		*mlx;
	void		*win;
	void		*img;
	t_texture	img_block;
	t_texture	img_bg;
	t_texture	img_pl;
	t_texture	img_door;
	t_texture	img_open;
	int			*img_buff;
	t_texture	wall_sides[4];
	t_texture	door_frames[DOOR_FRAMES_COUNT];
	int			ceil_color;
	int			floor_color;
}	t_render;
#endif
