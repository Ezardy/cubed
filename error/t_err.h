#ifndef T_ERR_H
# define T_ERR_H
# include <stdbool.h>

# include "t_trace.h"

typedef struct s_err
{
	int		error;
	t_trace	*trace;
}	t_err;
#endif
