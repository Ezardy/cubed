#ifndef T_TEXTURE_H
# define T_TEXTURE_H

typedef struct s_texture
{
	int		w;
	int		h;
	void	*img;
	int		*buff;
}	t_texture;
#endif
