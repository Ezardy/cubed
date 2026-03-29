#ifndef T_INPUT_H
# define T_INPUT_H

typedef struct s_input
{
	bool	forward : 1;
	bool	backward : 1;
	bool	left : 1;
	bool	right : 1;
	bool	rotate_left : 1;
	bool	rotate_right : 1;
}	t_input;
#endif