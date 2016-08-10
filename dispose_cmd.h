/* dispose_cmd.h -- Functions appearing in dispose_cmd.c. */


#if !defined(_DISPOSE_CMD_H_)
#define _DISPOSE_CMD_H_

#include "stdc.h"

extern void dispose_command(COMMAND *);
extern void dispose_word_desc(WORD_DESC *);
extern void dispose_word(WORD_DESC *);
extern void dispose_words(WORD_LIST *);
extern void dispose_word_array(char **);
extern void dispose_redirects(REDIRECT *);

#if defined(COND_COMMAND)
extern void dispose_cond_node(COND_COM *);
#endif

extern void dispose_function_def_contents(FUNCTION_DEF *);
extern void dispose_function_def(FUNCTION_DEF *);

#endif /* !_DISPOSE_CMD_H_ */
