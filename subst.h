/* subst.h -- Names of externally visible functions in subst.c. */

#if !defined(_SUBST_H_)
#define _SUBST_H_

#include "stdc.h"

/* Constants which specify how to handle backslashes and quoting in
   expand_word_internal ().  Q_DOUBLE_QUOTES means to use the function
   slashify_in_quotes () to decide whether the backslash should be
   retained.  Q_HERE_DOCUMENT means slashify_in_here_document () to
   decide whether to retain the backslash.  Q_KEEP_BACKSLASH means
   to unconditionally retain the backslash.  Q_PATQUOTE means that we're
   expanding a pattern ${var%#[#%]pattern} in an expansion surrounded
   by double quotes. Q_DOLBRACE means we are expanding a ${...} word, so
   backslashes should also escape { and } and be removed. */
#define Q_DOUBLE_QUOTES 0x001
#define Q_HERE_DOCUMENT 0x002
#define Q_KEEP_BACKSLASH 0x004
#define Q_PATQUOTE 0x008
#define Q_QUOTED 0x010
#define Q_ADDEDQUOTES 0x020
#define Q_QUOTEDNULL 0x040
#define Q_DOLBRACE 0x080
#define Q_ARITH 0x100    /* expanding string for arithmetic evaluation */
#define Q_ARRAYSUB 0x200 /* expanding indexed array subscript */

/* Flag values controlling how assignment statements are treated. */
#define ASS_APPEND 0x0001
#define ASS_MKLOCAL 0x0002
#define ASS_MKASSOC 0x0004
#define ASS_MKGLOBAL 0x0008 /* force global assignment */
#define ASS_NAMEREF 0x0010  /* assigning to nameref variable */
#define ASS_FORCE 0x0020    /* force assignment even to readonly variable */

/* Flags for the string extraction functions. */
#define SX_NOALLOC 0x0001     /* just skip; don't return substring */
#define SX_VARNAME 0x0002     /* variable name; for string_extract () */
#define SX_REQMATCH 0x0004    /* closing/matching delimiter required */
#define SX_COMMAND 0x0008     /* extracting a shell script/command */
#define SX_NOCTLESC 0x0010    /* don't honor CTLESC quoting */
#define SX_NOESCCTLNUL 0x0020 /* don't let CTLESC quote CTLNUL */
#define SX_NOLONGJMP 0x0040   /* don't longjmp on fatal error */
#define SX_ARITHSUB 0x0080    /* extracting $(( ... )) (currently unused) */
#define SX_POSIXEXP                                                          \
  0x0100               /* extracting new Posix pattern removal expansions in \
                          extract_dollar_brace_string */
#define SX_WORD 0x0200 /* extracting word in ${param op word} */
#define SX_COMPLETE 0x0400 /* extracting word for completion */

/* Remove backslashes which are quoting backquotes from STRING.  Modifies
   STRING, and returns a pointer to it. */
extern char *de_backslash(char *);

/* Replace instances of \! in a string with !. */
extern void unquote_bang(char *);

/* Extract the $( construct in STRING, and return a new string.
   Start extracting at (SINDEX) as if we had just seen "$(".
   Make (SINDEX) get the position just after the matching ")".
   XFLAGS is additional flags to pass to other extraction functions, */
extern char *extract_command_subst(char *, int *, int);

/* Extract the $[ construct in STRING, and return a new string.
   Start extracting at (SINDEX) as if we had just seen "$[".
   Make (SINDEX) get the position just after the matching "]". */
extern char *extract_arithmetic_subst(char *, int *);

#if defined(PROCESS_SUBSTITUTION)
/* Extract the <( or >( construct in STRING, and return a new string.
   Start extracting at (SINDEX) as if we had just seen "<(".
   Make (SINDEX) get the position just after the matching ")". */
extern char *extract_process_subst(char *, char *, int *, int);
#endif /* PROCESS_SUBSTITUTION */

/* Extract the name of the variable to bind to from the assignment string. */
extern char *assignment_name(char *);

/* Return a single string of all the words present in LIST, separating
   each word with SEP. */
extern char *string_list_internal(WORD_LIST *, char *);

/* Return a single string of all the words present in LIST, separating
   each word with a space. */
extern char *string_list(WORD_LIST *);

/* Turn $* into a single string, obeying POSIX rules. */
extern char *string_list_dollar_star(WORD_LIST *);

/* Expand $@ into a single string, obeying POSIX rules. */
extern char *string_list_dollar_at(WORD_LIST *, int, int);

/* Turn the positional paramters into a string, understanding quoting and
   the various subtleties of using the first character of $IFS as the
   separator.  Calls string_list_dollar_at, string_list_dollar_star, and
   string_list as appropriate. */
extern char *string_list_pos_params(int, WORD_LIST *, int);

/* Perform quoted null character removal on each element of LIST.
   This modifies LIST. */
extern void word_list_remove_quoted_nulls(WORD_LIST *);

/* This performs word splitting and quoted null character removal on
   STRING. */
extern WORD_LIST *list_string(char *, char *, int);

extern char *ifs_firstchar(int *);
extern char *get_word_from_string(char **, char *, char **);
extern char *strip_trailing_ifs_whitespace(char *, char *, int);

/* Given STRING, an assignment string, get the value of the right side
   of the `=', and bind it to the left side.  If EXPAND is true, then
   perform tilde expansion, parameter expansion, command substitution,
   and arithmetic expansion on the right-hand side.  Do not perform word
   splitting on the result of expansion. */
extern int do_assignment(char *);
extern int do_assignment_no_expand(char *);
extern int do_word_assignment(WORD_DESC *, int);

/* Append SOURCE to TARGET at INDEX.  SIZE is the current amount
   of space allocated to TARGET.  SOURCE can be NULL, in which
   case nothing happens.  Gets rid of SOURCE by free ()ing it.
   Returns TARGET in case the location has changed. */
extern char *sub_append_string(char *, char *, int *, int *);

/* Append the textual representation of NUMBER to TARGET.
   INDEX and SIZE are as in SUB_APPEND_STRING. */
extern char *sub_append_number(intmax_t, char *, int *, int *);

/* Return the word list that corresponds to `$*'. */
extern WORD_LIST *list_rest_of_args(void);

/* Make a single large string out of the dollar digit variables,
   and the rest_of_args.  If DOLLAR_STAR is 1, then obey the special
   case of "$*" with respect to IFS. */
extern char *string_rest_of_args(int);

extern int number_of_args(void);

/* Expand STRING by performing parameter expansion, command substitution,
   and arithmetic expansion.  Dequote the resulting WORD_LIST before
   returning it, but do not perform word splitting.  The call to
   remove_quoted_nulls () is made here because word splitting normally
   takes care of quote removal. */
extern WORD_LIST *expand_string_unsplit(char *, int);

/* Expand the rhs of an assignment statement. */
extern WORD_LIST *expand_string_assignment(char *, int);

/* Expand a prompt string. */
extern WORD_LIST *expand_prompt_string(char *, int, int);

/* Expand STRING just as if you were expanding a word.  This also returns
   a list of words.  Note that filename globbing is *NOT* done for word
   or string expansion, just when the shell is expanding a command.  This
   does parameter expansion, command substitution, arithmetic expansion,
   and word splitting.  Dequote the resultant WORD_LIST before returning. */
extern WORD_LIST *expand_string(char *, int);

/* Convenience functions that expand strings to strings, taking care of
   converting the WORD_LIST * returned by the expand_string* functions
   to a string and deallocating the WORD_LIST *. */
extern char *expand_string_to_string(char *, int);
extern char *expand_string_unsplit_to_string(char *, int);
extern char *expand_assignment_string_to_string(char *, int);

/* Expand an arithmetic expression string */
extern char *expand_arith_string(char *, int);

/* De-quote quoted characters in STRING. */
extern char *dequote_string(char *);

/* De-quote CTLESC-escaped CTLESC or CTLNUL characters in STRING. */
extern char *dequote_escapes(char *);

/* De-quote quoted characters in each word in LIST. */
extern WORD_LIST *dequote_list(WORD_LIST *);

/* Expand WORD, performing word splitting on the result.  This does
   parameter expansion, command substitution, arithmetic expansion,
   word splitting, and quote removal. */
extern WORD_LIST *expand_word(WORD_DESC *, int);

/* Expand WORD, but do not perform word splitting on the result.  This
   does parameter expansion, command substitution, arithmetic expansion,
   and quote removal. */
extern WORD_LIST *expand_word_unsplit(WORD_DESC *, int);
extern WORD_LIST *expand_word_leave_quoted(WORD_DESC *, int);

/* Return the value of a positional parameter.  This handles values > 10. */
extern char *get_dollar_var_value(intmax_t);

/* Quote a string to protect it from word splitting. */
extern char *quote_string(char *);

/* Quote escape characters (characters special to interals of expansion)
   in a string. */
extern char *quote_escapes(char *);

/* And remove such quoted special characters. */
extern char *remove_quoted_escapes(char *);

/* Remove CTLNUL characters from STRING unless they are quoted with CTLESC. */
extern char *remove_quoted_nulls(char *);

/* Perform quote removal on STRING.  If QUOTED > 0, assume we are obeying the
   backslash quoting rules for within double quotes. */
extern char *string_quote_removal(char *, int);

/* Perform quote removal on word WORD.  This allocates and returns a new
   WORD_DESC *. */
extern WORD_DESC *word_quote_removal(WORD_DESC *, int);

/* Perform quote removal on all words in LIST.  If QUOTED is non-zero,
   the members of the list are treated as if they are surrounded by
   double quotes.  Return a new list, or NULL if LIST is NULL. */
extern WORD_LIST *word_list_quote_removal(WORD_LIST *, int);

/* Called when IFS is changed to maintain some private variables. */
extern void setifs(SHELL_VAR *);

/* Return the value of $IFS, or " \t\n" if IFS is unset. */
extern char *getifs(void);

/* This splits a single word into a WORD LIST on $IFS, but only if the word
   is not quoted.  list_string () performs quote removal for us, even if we
   don't do any splitting. */
extern WORD_LIST *word_split(WORD_DESC *, char *);

/* Take the list of words in LIST and do the various substitutions.  Return
   a new list of words which is the expanded list, and without things like
   variable assignments. */
extern WORD_LIST *expand_words(WORD_LIST *);

/* Same as expand_words (), but doesn't hack variable or environment
   variables. */
extern WORD_LIST *expand_words_no_vars(WORD_LIST *);

/* Perform the `normal shell expansions' on a WORD_LIST.  These are
   brace expansion, tilde expansion, parameter and variable substitution,
   command substitution, arithmetic expansion, and word splitting. */
extern WORD_LIST *expand_words_shellexp(WORD_LIST *);

extern WORD_DESC *command_substitute(char *, int);
extern char *pat_subst(char *, char *, char *, int);

extern int fifos_pending(void);
extern int num_fifos(void);
extern void unlink_fifo_list(void);
extern void unlink_fifo(int);

extern char *copy_fifo_list(int *);
extern void unlink_new_fifos(char *, int);
extern void close_new_fifos(char *, int);

extern void clear_fifo_list(void);

extern WORD_LIST *list_string_with_quotes(char *);

#if defined(ARRAY_VARS)
extern char *extract_array_assignment_list(char *, int *);
#endif

#if defined(COND_COMMAND)
extern char *remove_backslashes(char *);
extern char *cond_expand_word(WORD_DESC *, int);
#endif

/* Flags for skip_to_delim */
#define SD_NOJMP 0x001  /* don't longjmp on fatal error. */
#define SD_INVERT 0x002 /* look for chars NOT in passed set */
#define SD_NOQUOTEDELIM \
  0x004 /* don't let single or double quotes act as delimiters */
#define SD_NOSKIPCMD                                                         \
  0x008 /* don't skip over $(, <(, or >( command/process substitution; parse \
           them as commands */
#define SD_EXTGLOB \
  0x010 /* skip over extended globbing patterns if appropriate */
#define SD_IGNOREQUOTE 0x020 /* single and double quotes are not special */
#define SD_GLOB 0x040 /* skip over glob patterns like bracket expressions */
#define SD_NOPROCSUB 0x080 /* don't parse process substitutions as commands */
#define SD_COMPLETE 0x100  /* skip_to_delim during completion */
#define SD_HISTEXP 0x200   /* skip_to_delim during history expansion */
#define SD_ARITHEXP 0x400  /* skip_to_delim during arithmetic expansion */

extern int skip_to_delim(char *, int, char *, int);

#if defined(BANG_HISTORY)
extern int skip_to_histexp(char *, int, char *, int);
#endif

#if defined(READLINE)
extern int char_is_quoted(char *, int);
extern int unclosed_pair(char *, int, char *);
extern WORD_LIST *split_at_delims(char *, int, char *, int, int, int *, int *);
#endif

/* Variables used to keep track of the characters in IFS. */
extern SHELL_VAR *ifs_var;
extern char *ifs_value;
extern unsigned char ifs_cmap[];

#if defined(HANDLE_MULTIBYTE)
extern unsigned char ifs_firstc[];
extern size_t ifs_firstc_len;
#else
extern unsigned char ifs_firstc;
#endif

/* Evaluates to 1 if C is a character in $IFS. */
#define isifs(c) (ifs_cmap[(unsigned char)(c)] != 0)

/* How to determine the quoted state of the character C. */
#define QUOTED_CHAR(c) ((c) == CTLESC)

/* Is the first character of STRING a quoted NULL character? */
#define QUOTED_NULL(string) ((string)[0] == CTLNUL && (string)[1] == '\0')

extern void invalidate_cached_quoted_dollar_at(void);

#endif /* !_SUBST_H_ */
