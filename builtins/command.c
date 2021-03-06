
#include <config.h>

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include "../bashansi.h"

#include "../shell.h"
#include "../execute_cmd.h"
#include "../flags.h"
#include "bashgetopt.h"
#include "common.h"

#if defined(_CS_PATH) && defined(HAVE_CONFSTR) && !HAVE_DECL_CONFSTR
extern size_t confstr(int, char *, size_t);
#endif

extern int subshell_environment;

static void restore_path(char *);
extern int command_builtin(WORD_LIST *list);

/* Run the commands mentioned in LIST without paying attention to shell
   functions. */
int command_builtin(WORD_LIST *list) {
  int result, verbose, use_standard_path, opt;
  char *old_path, *standard_path;
  COMMAND *command;

  verbose = use_standard_path = 0;
  reset_internal_getopt();
  while ((opt = internal_getopt(list, "pvV")) != -1) {
    switch (opt) {
      case 'p':
        use_standard_path = CDESC_STDPATH;
        break;
      case 'V':
        verbose = CDESC_SHORTDESC |
                  CDESC_ABSPATH; /* look in common.h for constants */
        break;
      case 'v':
        verbose = CDESC_REUSABLE; /* ditto */
        break;
        CASE_HELPOPT;
      default:
        builtin_usage();
        return (EX_USAGE);
    }
  }
  list = loptend;

  if (list == 0) return (EXECUTION_SUCCESS);

  if (verbose) {
    int found, any_found;

    for (any_found = 0; list; list = list->next) {
      found = describe_command(list->word->word, verbose | use_standard_path);

      if (found == 0 && verbose != CDESC_REUSABLE)
        sh_notfound(list->word->word);

      any_found += found;
    }

    return (any_found ? EXECUTION_SUCCESS : EXECUTION_FAILURE);
  }

  begin_unwind_frame("command_builtin");

#define COMMAND_BUILTIN_FLAGS                                       \
  (CMD_NO_FUNCTIONS | CMD_INHIBIT_EXPANSION | CMD_COMMAND_BUILTIN | \
   (use_standard_path ? CMD_STDPATH : 0))

  /* We don't want this to be reparsed (consider command echo 'foo &'), so
     just make a simple_command structure and call execute_command with it. */
  command = make_bare_simple_command();
  command->value.Simple->words = (WORD_LIST *)copy_word_list(list);
  command->value.Simple->redirects = (REDIRECT *)NULL;
  command->flags |= COMMAND_BUILTIN_FLAGS;
  command->value.Simple->flags |= COMMAND_BUILTIN_FLAGS;

  add_unwind_protect((char *)dispose_command, command);
  result = execute_command(command);

  run_unwind_frame("command_builtin");

  return (result);
}

/* Restore the value of the $PATH variable after replacing it when
   executing `command -p'. */
static void restore_path(var) char *var;
{
  if (var) {
    bind_variable("PATH", var, 0);
    free(var);
  } else
    unbind_variable("PATH");

  stupidly_hack_special_variables("PATH");
}
