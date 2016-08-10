/* rlshell.h -- utility functions normally provided by bash. */


#if !defined(_RL_SHELL_H_)
#define _RL_SHELL_H_

#include "rlstdc.h"

extern char *sh_single_quote PARAMS((char *));
extern void sh_set_lines_and_columns PARAMS((int, int));
extern char *sh_get_env_value PARAMS((const char *));
extern char *sh_get_home_dir PARAMS((void));
extern int sh_unset_nodelay_mode PARAMS((int));

#endif /* _RL_SHELL_H_ */
