/* bashline.h -- interface to the bash readline functions in bashline.c. */


#if !defined(_BASHLINE_H_)
#define _BASHLINE_H_

#include "stdc.h"

extern int bash_readline_initialized;

extern void posix_readline_initialize(int);
extern void reset_completer_word_break_chars(void);
extern int enable_hostname_completion(int);
extern void initialize_readline(void);
extern void bashline_reset(void);
extern void bashline_reinitialize(void);
extern int bash_re_edit(char *);

extern void bashline_set_event_hook(void);
extern void bashline_reset_event_hook(void);

extern int bind_keyseq_to_unix_command(char *);
extern int print_unix_command_map(void);

extern char **bash_default_completion(const char *, int, int, int, int);

void set_directory_hook(void);

/* Used by programmable completion code. */
extern char *command_word_completion_function(const char *, int);
extern char *bash_groupname_completion_function(const char *, int);
extern char *bash_servicename_completion_function(const char *, int);

extern char **get_hostname_list(void);
extern void clear_hostname_list(void);

extern char **bash_directory_completion_matches(const char *);
extern char *bash_dequote_text(const char *);

#endif /* _BASHLINE_H_ */
