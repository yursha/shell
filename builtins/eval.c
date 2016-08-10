#include <config.h>
#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include "../shell.h"
#include "bashgetopt.h"
#include "common.h"

extern int eval_builtin(WORD_LIST* list);

/* Parse the string that these words make, and execute the command found. */
int eval_builtin(WORD_LIST* list) {
  if (no_options(list)) return (EX_USAGE);
  list = loptend; /* skip over possible `--' */

  return (list ? evalstring(string_list(list), "eval", SEVAL_NOHIST)
               : EXECUTION_SUCCESS);
}
