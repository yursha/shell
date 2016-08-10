/* histlib.h -- internal definitions for the history library. */

#if !defined(_HISTLIB_H_)
#define _HISTLIB_H_

#if defined(HAVE_STRING_H)
#include <string.h>
#else
#include <strings.h>
#endif /* !HAVE_STRING_H */

#if !defined(STREQ)
#define STREQ(a, b) (((a)[0] == (b)[0]) && (strcmp((a), (b)) == 0))
#define STREQN(a, b, n) \
  (((n) == 0) ? (1) : ((a)[0] == (b)[0]) && (strncmp((a), (b), (n)) == 0))
#endif

#ifndef savestring
#define savestring(x) strcpy(xmalloc(1 + strlen(x)), (x))
#endif

#ifndef whitespace
#define whitespace(c) (((c) == ' ') || ((c) == '\t'))
#endif

#ifndef _rl_digit_p
#define _rl_digit_p(c) ((c) >= '0' && (c) <= '9')
#endif

#ifndef _rl_digit_value
#define _rl_digit_value(c) ((c) - '0')
#endif

#ifndef member
#ifndef strchr
extern char *strchr();
#endif
#define member(c, s) ((c) ? ((char *)strchr((s), (c)) != (char *)NULL) : 0)
#endif

#ifndef FREE
#define FREE(x) \
  if (x) free(x)
#endif

/* Possible history errors passed to hist_error. */
#define EVENT_NOT_FOUND 0
#define BAD_WORD_SPEC 1
#define SUBST_FAILED 2
#define BAD_MODIFIER 3
#define NO_PREV_SUBST 4

/* Possible definitions for history starting point specification. */
#define ANCHORED_SEARCH 1
#define NON_ANCHORED_SEARCH 0

/* Possible definitions for what style of writing the history file we want. */
#define HISTORY_APPEND 0
#define HISTORY_OVERWRITE 1

#endif /* !_HISTLIB_H_ */
