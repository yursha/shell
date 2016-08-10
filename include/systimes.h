
/*
 *	POSIX Standard: 4.5.2 Process Times	<sys/times.h>
 */

/*
 * If we don't have a standard system clock_t type, this must be included
 * after config.h
 */

#ifndef _BASH_SYSTIMES_H
#define _BASH_SYSTIMES_H 1

#if defined(HAVE_SYS_TIMES_H)
#include <sys/times.h>
#else /* !HAVE_SYS_TIMES_H */

#include <stdc.h>

/* Structure describing CPU time used by a process and its children.  */
struct tms {
  clock_t tms_utime; /* User CPU time.  */
  clock_t tms_stime; /* System CPU time.  */

  clock_t tms_cutime; /* User CPU time of dead children.  */
  clock_t tms_cstime; /* System CPU time of dead children.  */
};

/* Store the CPU time used by this process and all its
   dead descendants in BUFFER.
   Return the elapsed real time from an arbitrary point in the
   past (the bash emulation uses the epoch), or (clock_t) -1 for
   errors.  All times are in CLK_TCKths of a second.  */
extern clock_t times(struct tms *buffer);

#endif /* !HAVE_SYS_TIMES_H */
#endif /* _BASH_SYSTIMES_H */
