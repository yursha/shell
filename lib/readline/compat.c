/* compat.c -- backwards compatibility functions. */

#define READLINE_LIBRARY

#if defined(HAVE_CONFIG_H)
#include <config.h>
#endif

#include <stdio.h>

#include "rlstdc.h"
#include "rltypedefs.h"

extern void rl_free_undo_list PARAMS((void));
extern int rl_maybe_save_line PARAMS((void));
extern int rl_maybe_unsave_line PARAMS((void));
extern int rl_maybe_replace_line PARAMS((void));

extern int rl_crlf PARAMS((void));
extern int rl_ding PARAMS((void));
extern int rl_alphabetic PARAMS((int));

extern char **rl_completion_matches PARAMS((const char *,
                                            rl_compentry_func_t *));
extern char *rl_username_completion_function PARAMS((const char *, int));
extern char *rl_filename_completion_function PARAMS((const char *, int));

/* Provide backwards-compatible entry points for old function names. */

void free_undo_list() { rl_free_undo_list(); }

int maybe_replace_line() { return rl_maybe_replace_line(); }

int maybe_save_line() { return rl_maybe_save_line(); }

int maybe_unsave_line() { return rl_maybe_unsave_line(); }

int ding() { return rl_ding(); }

int crlf() { return rl_crlf(); }

int alphabetic(c) int c;
{ return rl_alphabetic(c); }

char **completion_matches(s, f) const char *s;
rl_compentry_func_t *f;
{ return rl_completion_matches(s, f); }

char *username_completion_function(s, i) const char *s;
int i;
{ return rl_username_completion_function(s, i); }

char *filename_completion_function(s, i) const char *s;
int i;
{ return rl_filename_completion_function(s, i); }
