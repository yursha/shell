/* redir.h - functions from redir.c. */


#if !defined(_REDIR_H_)
#define _REDIR_H_

#include "stdc.h"

/* Values for flags argument to do_redirections */
#define RX_ACTIVE 0x01   /* do it; don't just go through the motions */
#define RX_UNDOABLE 0x02 /* make a list to undo these redirections */
#define RX_CLEXEC 0x04   /* set close-on-exec for opened fds > 2 */
#define RX_INTERNAL 0x08
#define RX_USER 0x10
#define RX_SAVCLEXEC                                                          \
  0x20 /* set close-on-exec off in restored fd even though saved on has it on \
          */
#define RX_SAVEFD 0x40 /* fd used to save another even if < SHELL_FD_BASE */

extern void redirection_error(REDIRECT *, int);
extern int do_redirections(REDIRECT *, int);
extern char *redirection_expand(WORD_DESC *);
extern int stdin_redirects(REDIRECT *);

#endif /* _REDIR_H_ */
