
#include <config.h>

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include "../shell.h"
#include "common.h"
#include "bashgetopt.h"

extern char *this_command_name;
extern int builtin_builtin(WORD_LIST *list);

/* Run the command mentioned in list directly, without going through the
   normal alias/function/builtin/filename lookup process. */
int builtin_builtin(WORD_LIST *list) {
  sh_builtin_func_t *function;
  register char *command;

  if (no_options(list)) return (EX_USAGE);
  list = loptend; /* skip over possible `--' */

  if (list == 0) return (EXECUTION_SUCCESS);

  command = list->word->word;
  function = find_shell_builtin(command);

  if (!function) {
    sh_notbuiltin(command);
    return (EXECUTION_FAILURE);
  } else {
    this_command_name = command;
    list = list->next;
    return ((*function)(list));
  }
}
