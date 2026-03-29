#ifndef COMMON_H
# define COMMON_H

int		free_return(char *var);
int		free_arr(char **av);
int		check_file(int *fd);
int		split_count(char **s);
int		ft_str_is_numeric(char *str);
int		get_map_width(char **map);
int		get_map_height(char **map);
#endif