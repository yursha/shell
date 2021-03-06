
#include <config.h>

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include "../shell.h"
#include "common.h"

extern int let_builtin(WORD_LIST* list);
extern int exp_builtin(WORD_LIST* list);

/* Arithmetic LET function. */
int let_builtin(WORD_LIST* list) {
  intmax_t ret;
  int expok;

  CHECK_HELPOPT(list);

  /* Skip over leading `--' argument. */
  if (list && list->word && ISOPTION(list->word->word, '-')) list = list->next;

  if (list == 0) {
    builtin_error("expression expected");
    return (EXECUTION_FAILURE);
  }

  for (; list; list = list->next) {
    ret = evalexp(list->word->word, &expok);
    if (expok == 0) return (EXECUTION_FAILURE);
  }

  return ((ret == 0) ? EXECUTION_FAILURE : EXECUTION_SUCCESS);
}

#ifdef INCLUDE_UNUSED
int exp_builtin(WORD_LIST* list) {
  char* exp;
  intmax_t ret;
  int expok;

  if (list == 0) {
    builtin_error("expression expected");
    return (EXECUTION_FAILURE);
  }

  exp = string_list(list);
  ret = evalexp(exp, &expok);
  (void)free(exp);
  return (((ret == 0) || (expok == 0)) ? EXECUTION_FAILURE : EXECUTION_SUCCESS);
}
#endif
