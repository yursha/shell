/* findcmd.h - functions from findcmd.c. */


#if !defined(_FINDCMD_H_)
#define _FINDCMD_H_

#include "stdc.h"

/* Flags for search_for_command */
#define CMDSRCH_HASH 0x01
#define CMDSRCH_STDPATH 0x02
#define CMDSRCH_TEMPENV 0x04

extern int file_status(const char *);
extern int executable_file(const char *);
extern int is_directory(const char *);
extern int executable_or_directory(const char *);
extern char *find_user_command(const char *);
extern char *find_in_path(const char *, char *, int);
extern char *find_path_file(const char *);
extern char *search_for_command(const char *, int);
extern char *user_command_matches(const char *, int, int);
extern void setup_exec_ignore(char *);

#endif /* _FINDCMD_H_ */
