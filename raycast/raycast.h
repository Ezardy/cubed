#ifndef RAYCAST_H
# define RAYCAST_H

# include "game/t_game.h"
# include "c3d_math/t_vec.h"
# include "t_rayhit.h"

void	raycast(const t_game *game, const t_vec *pos, const t_vec *dir,
			t_rayhit *hit);
#endif
