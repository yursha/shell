/* common.h -- extern declarations for functions defined in common.c. */

/* Copyright (C) 1993-2015 Free Software Foundation, Inc.

   This file is part of GNU Bash, the Bourne Again SHell.

   Bash is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Bash is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Bash.  If not, see <http://www.gnu.org/licenses/>.
*/

#if  !defined (__COMMON_H)
#  define __COMMON_H

#include "stdc.h"

#define ISOPTION(s, c)	(s[0] == '-' && !s[2] && s[1] == c)
#define ISHELP(s)	(STREQ ((s), "--help"))

#define CHECK_HELPOPT(l) \
do { \
  if ((l) && (l)->word && ISHELP((l)->word->word)) \
    { \
      builtin_help (); \
      return (EX_USAGE); \
    } \
} while (0)

#define CASE_HELPOPT \
  case GETOPT_HELP: \
    builtin_help (); \
    return (EX_USAGE)

/* Flag values for parse_and_execute () */
#define SEVAL_NONINT	0x001
#define SEVAL_INTERACT	0x002
#define SEVAL_NOHIST	0x004
#define SEVAL_NOFREE	0x008
#define SEVAL_RESETLINE	0x010
#define SEVAL_PARSEONLY	0x020
#define SEVAL_NOLONGJMP 0x040
#define SEVAL_FUNCDEF	0x080		/* only allow function definitions */
#define SEVAL_ONECMD	0x100		/* only allow a single command */
#define SEVAL_NOHISTEXP	0x200		/* inhibit history expansion */

/* Flags for describe_command, shared between type.def and command.def */
#define CDESC_ALL		0x001	/* type -a */
#define CDESC_SHORTDESC		0x002	/* command -V */
#define CDESC_REUSABLE		0x004	/* command -v */
#define CDESC_TYPE		0x008	/* type -t */
#define CDESC_PATH_ONLY		0x010	/* type -p */
#define CDESC_FORCE_PATH	0x020	/* type -ap or type -P */
#define CDESC_NOFUNCS		0x040	/* type -f */
#define CDESC_ABSPATH		0x080	/* convert to absolute path, no ./ */
#define CDESC_STDPATH		0x100	/* command -p */

/* Flags for get_job_by_name */
#define JM_PREFIX		0x01	/* prefix of job name */
#define JM_SUBSTRING		0x02	/* substring of job name */
#define JM_EXACT		0x04	/* match job name exactly */
#define JM_STOPPED		0x08	/* match stopped jobs only */
#define JM_FIRSTMATCH		0x10	/* return first matching job */

/* Flags for remember_args and value of changed_dollar_vars */
#define ARGS_NONE		0x0
#define ARGS_INVOC		0x01
#define ARGS_FUNC		0x02
#define ARGS_SETBLTIN		0x04

/* Maximum number of attribute letters */
#define MAX_ATTRIBUTES		16

/* Functions from common.c */
extern void builtin_error(const char *, ...)  __attribute__((__format__ (printf, 1, 2)));
extern void builtin_warning(const char *, ...)  __attribute__((__format__ (printf, 1, 2)));
extern void builtin_usage(void);
extern void no_args(WORD_LIST *);
extern int no_options(WORD_LIST *);

/* common error message functions */
extern void sh_needarg(char *);
extern void sh_neednumarg(char *);
extern void sh_notfound(char *);
extern void sh_invalidopt(char *);
extern void sh_invalidoptname(char *);
extern void sh_invalidid(char *);
extern void sh_invalidnum(char *);
extern void sh_invalidsig(char *);
extern void sh_erange(char *, char *);
extern void sh_badpid(char *);
extern void sh_badjob(char *);
extern void sh_readonly(const char *);
extern void sh_nojobs(char *);
extern void sh_restricted(char *);
extern void sh_notbuiltin(char *);
extern void sh_wrerror(void);
extern void sh_ttyerror(int);
extern int sh_chkwrite(int);

extern char **make_builtin_argv(WORD_LIST *, int *);
extern void remember_args(WORD_LIST *, int);

extern int dollar_vars_changed(void);
extern void set_dollar_vars_unchanged(void);
extern void set_dollar_vars_changed(void);

extern int get_numeric_arg(WORD_LIST *, int, intmax_t *);
extern int get_exitstat(WORD_LIST *);
extern int read_octal(char *);

/* Keeps track of the current working directory. */
extern char *the_current_working_directory;
extern char *get_working_directory(char *);
extern void set_working_directory(char *);

#if defined (JOB_CONTROL)
extern int get_job_by_name(const char *, int);
extern int get_job_spec(WORD_LIST *);
#endif
extern int display_signal_list(WORD_LIST *, int);

/* It's OK to declare a function as returning a Function * without
   providing a definition of what a `Function' is. */
extern struct builtin *builtin_address_internal(char *, int);
extern sh_builtin_func_t *find_shell_builtin(char *);
extern sh_builtin_func_t *builtin_address(char *);
extern sh_builtin_func_t *find_special_builtin(char *);
extern void initialize_shell_builtins(void);

/* Functions from exit.def */
extern void bash_logout(void);

/* Functions from getopts.def */
extern void getopts_reset(int);

/* Functions from help.def */
extern void builtin_help(void);

/* Functions from read.def */
extern void read_tty_cleanup(void);
extern int read_tty_modified(void);

/* Functions from set.def */
extern int minus_o_option_value(char *);
extern void list_minus_o_opts(int, int);
extern char **get_minus_o_opts(void);
extern int set_minus_o_option(int, char *);

extern void set_shellopts(void);
extern void parse_shellopts(char *);
extern void initialize_shell_options(int);

extern void reset_shell_options(void);

extern char *get_current_options(void);
extern void set_current_options(const char *);

/* Functions from shopt.def */
extern void reset_shopt_options(void);
extern char **get_shopt_options(void);

extern int shopt_setopt(char *, int);
extern int shopt_listopt(char *, int);

extern int set_login_shell(char *, int);

extern void set_bashopts(void);
extern void parse_bashopts(char *);
extern void initialize_bashopts(int);

extern void set_compatibility_opts(void);

/* Functions from type.def */
extern int describe_command(char *, int);

/* Functions from setattr.def */
extern int set_or_show_attributes(WORD_LIST *, int, int);
extern int show_all_var_attributes(int, int);
extern int show_var_attributes(SHELL_VAR *, int, int);
extern int show_name_attributes(char *, int);
extern int show_func_attributes(char *, int);
extern void set_var_attribute(char *, int, int);
extern int var_attribute_string(SHELL_VAR *, int, char *);

/* Functions from pushd.def */
extern char *get_dirstack_from_string(char *);
extern char *get_dirstack_element(intmax_t, int);
extern void set_dirstack_element(intmax_t, int, char *);
extern WORD_LIST *get_directory_stack(int);

/* Functions from evalstring.c */
extern int parse_and_execute(char *, const char *, int);
extern int evalstring(char *, const char *, int);
extern void parse_and_execute_cleanup(void);
extern int parse_string(char *, const char *, int, char **);
extern int should_suppress_fork(COMMAND *);
extern void optimize_fork(COMMAND *);

/* Functions from evalfile.c */
extern int maybe_execute_file(const char *, int);
extern int force_execute_file(const char *, int);
extern int source_file(const char *, int);
extern int fc_execute_file(const char *);

#endif /* !__COMMON_H */
