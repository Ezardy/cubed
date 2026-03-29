#ifndef T_TRACE_H
# define T_TRACE_H

typedef struct s_trace
{
	const char		*name;
	struct s_trace	*next;
}	t_trace;
#endif
