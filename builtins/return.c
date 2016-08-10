#include <config.h>

#if defined (HAVE_UNISTD_H)
#  include <unistd.h>
#endif


#include "../shell.h"
#include "common.h"
#include "bashgetopt.h"

extern int last_command_exit_value;
extern int subshell_environment;
extern int return_catch_flag, return_catch_value;
extern int return_builtin(WORD_LIST*);

/* If we are executing a user-defined function then exit with the value
   specified as an argument.  if no argument is given, then the last
   exit status is used. */
int return_builtin(WORD_LIST* list) {
  CHECK_HELPOPT (list);

  return_catch_value = get_exitstat (list);

  if (return_catch_flag)
    siglongjmp(return_catch, 1);
  else
    {
      builtin_error (_("can only `return' from a function or sourced script"));
      return (EXECUTION_FAILURE);
    }
}
