#ifndef PARSING_H
# define PARSING_H

# include "game/t_game.h"
# include "t_cub.h"
# include "error/t_err.h"

int		validation(char *filename, t_cub *cubed, t_err *err);
int		is_cub(char *filename);
void	get_orientation_pos(t_cub *cub);
int		set_imgs(t_game *game);

#endif
