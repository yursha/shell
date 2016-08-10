/* make_cmd.h -- Declarations of functions found in make_cmd.c */


#if !defined(_MAKE_CMD_H_)
#define _MAKE_CMD_H_

#include "stdc.h"

extern void cmd_init(void);

extern WORD_DESC *alloc_word_desc(void);
extern WORD_DESC *make_bare_word(const char *);
extern WORD_DESC *make_word_flags(WORD_DESC *, const char *);
extern WORD_DESC *make_word(const char *);
extern WORD_DESC *make_word_from_token(int);

extern WORD_LIST *make_word_list(WORD_DESC *, WORD_LIST *);

#define add_string_to_list(s, l) make_word_list(make_word(s), (l))

extern COMMAND *make_command(enum command_type, SIMPLE_COM *);
extern COMMAND *command_connect(COMMAND *, COMMAND *, int);
extern COMMAND *make_for_command(WORD_DESC *, WORD_LIST *, COMMAND *, int);
extern COMMAND *make_group_command(COMMAND *);
extern COMMAND *make_case_command(WORD_DESC *, PATTERN_LIST *, int);
extern PATTERN_LIST *make_pattern_list(WORD_LIST *, COMMAND *);
extern COMMAND *make_if_command(COMMAND *, COMMAND *, COMMAND *);
extern COMMAND *make_while_command(COMMAND *, COMMAND *);
extern COMMAND *make_until_command(COMMAND *, COMMAND *);
extern COMMAND *make_bare_simple_command(void);
extern COMMAND *make_simple_command(ELEMENT, COMMAND *);
extern void make_here_document(REDIRECT *, int);
extern REDIRECT *make_redirection(REDIRECTEE, enum r_instruction, REDIRECTEE,
                                  int);
extern COMMAND *make_function_def(WORD_DESC *, COMMAND *, int, int);
extern COMMAND *clean_simple_command(COMMAND *);

extern COMMAND *make_arith_command(WORD_LIST *);

extern COMMAND *make_select_command(WORD_DESC *, WORD_LIST *, COMMAND *, int);

#if defined(COND_COMMAND)
extern COND_COM *make_cond_node(int, WORD_DESC *, COND_COM *, COND_COM *);
extern COMMAND *make_cond_command(COND_COM *);
#endif

extern COMMAND *make_arith_for_command(WORD_LIST *, COMMAND *, int);

extern COMMAND *make_subshell_command(COMMAND *);
extern COMMAND *make_coproc_command(char *, COMMAND *);

extern COMMAND *connect_async_list(COMMAND *, COMMAND *, int);

#endif /* !_MAKE_CMD_H */
