/*
 * shmatch.c -- shell interface to posix regular expression matching.
 */


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#if defined(HAVE_POSIX_REGEXP)

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "bashansi.h"

#include <stdio.h>
#include <regex.h>

#include "shell.h"
#include "variables.h"
#include "externs.h"

extern int glob_ignore_case, match_ignore_case;

int sh_regmatch(string, pattern, flags) const char *string;
const char *pattern;
int flags;
{
  regex_t regex = {0};
  regmatch_t *matches;
  int rflags;
#if defined(ARRAY_VARS)
  SHELL_VAR *rematch;
  ARRAY *amatch;
  int subexp_ind;
  char *subexp_str;
  int subexp_len;
#endif
  int result;

#if defined(ARRAY_VARS)
  rematch = (SHELL_VAR *)NULL;
#endif

  rflags = REG_EXTENDED;
  if (glob_ignore_case || match_ignore_case) rflags |= REG_ICASE;
#if !defined(ARRAY_VARS)
  rflags |= REG_NOSUB;
#endif

  if (regcomp(&regex, pattern, rflags))
    return 2; /* flag for printing a warning here. */

#if defined(ARRAY_VARS)
  matches = (regmatch_t *)malloc(sizeof(regmatch_t) * (regex.re_nsub + 1));
#else
  matches = NULL;
#endif

  /* man regexec: NULL PMATCH ignored if NMATCH == 0 */
  if (regexec(&regex, string, matches ? regex.re_nsub + 1 : 0, matches, 0))
    result = EXECUTION_FAILURE;
  else
    result = EXECUTION_SUCCESS; /* match */

#if defined(ARRAY_VARS)
  subexp_len = strlen(string) + 10;
  subexp_str = malloc(subexp_len + 1);

  /* Store the parenthesized subexpressions in the array BASH_REMATCH.
     Element 0 is the portion that matched the entire regexp.  Element 1
     is the part that matched the first subexpression, and so on. */
  unbind_variable_noref("BASH_REMATCH");
  rematch = make_new_array_variable("BASH_REMATCH");
  amatch = array_cell(rematch);

  if (matches && (flags & SHMAT_SUBEXP) && result == EXECUTION_SUCCESS &&
      subexp_str) {
    for (subexp_ind = 0; subexp_ind <= regex.re_nsub; subexp_ind++) {
      memset(subexp_str, 0, subexp_len);
      strncpy(subexp_str, string + matches[subexp_ind].rm_so,
              matches[subexp_ind].rm_eo - matches[subexp_ind].rm_so);
      array_insert(amatch, subexp_ind, subexp_str);
    }
  }

  VSETATTR(rematch, att_readonly);

  free(subexp_str);
  free(matches);
#endif /* ARRAY_VARS */

  regfree(&regex);

  return result;
}

#endif /* HAVE_POSIX_REGEXP */
