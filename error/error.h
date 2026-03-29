#ifndef ERROR_H
# define ERROR_H
# include "t_err.h"

bool	track(t_err *err, const char *name);
void	untrack(t_err *err);
bool	check_err(t_err *err, bool pred, int code);
void	print_trace(t_err *err);
bool	no_err(t_err *err);
#endif
