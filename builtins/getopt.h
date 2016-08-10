/* getopt.h - declarations for getopt. */


/* XXX THIS HAS BEEN MODIFIED FOR INCORPORATION INTO BASH XXX */

#ifndef _SH_GETOPT_H
#define _SH_GETOPT_H 1

#include "stdc.h"

/* For communication from `getopt' to the caller.
   When `getopt' finds an option that takes an argument,
   the argument value is returned here.
   Also, when `ordering' is RETURN_IN_ORDER,
   each non-option ARGV-element is returned here.  */

extern char *sh_optarg;

/* Index in ARGV of the next element to be scanned.
   This is used for communication to and from the caller
   and for communication between successive calls to `getopt'.

   On entry to `getopt', zero means this is the first call; initialize.

   When `getopt' returns EOF, this is the index of the first of the
   non-option elements that the caller should itself scan.

   Otherwise, `sh_optind' communicates from one call to the next
   how much of ARGV has been scanned so far.  */

extern int sh_optind;

/* Callers store zero here to inhibit the error message `getopt' prints
   for unrecognized options.  */

extern int sh_opterr;

/* Set to an option character which was unrecognized.  */

extern int sh_optopt;

/* Set to 1 when an unrecognized option is encountered. */
extern int sh_badopt;

extern int sh_getopt(int, char *const *, const char *);

typedef struct sh_getopt_state {
  char *gs_optarg;
  int gs_optind;
  int gs_curopt;
  char *gs_nextchar;
  int gs_charindex;
  int gs_flags;
} sh_getopt_state_t;

extern void sh_getopt_restore_state(char **);

extern sh_getopt_state_t *sh_getopt_alloc_istate(void);
extern void sh_getopt_dispose_istate(sh_getopt_state_t *);

extern sh_getopt_state_t *sh_getopt_save_istate(void);
extern void sh_getopt_restore_istate(sh_getopt_state_t *);

#endif /* _SH_GETOPT_H */
