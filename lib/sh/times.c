/* times.c - times(3) library function */


#include <config.h>

#if !defined(HAVE_TIMES)

#include <sys/types.h>
#include <posixtime.h>
#include <systimes.h>

#if defined(HAVE_SYS_RESOURCE_H) && defined(HAVE_GETRUSAGE)
#include <sys/resource.h>
#endif /* HAVE_SYS_RESOURCE_H && HAVE_GETRUSAGE */

extern long get_clk_tck(void);

#define CONVTCK(r) (r.tv_sec * clk_tck + r.tv_usec / (1000000 / clk_tck))

clock_t times(tms) struct tms *tms;
{
  clock_t rv;
  static long clk_tck = -1;

#if defined(HAVE_GETRUSAGE)
  struct timeval tv;
  struct rusage ru;

  if (clk_tck == -1) clk_tck = get_clk_tck();

  if (getrusage(RUSAGE_SELF, &ru) < 0) return ((clock_t)-1);
  tms->tms_utime = CONVTCK(ru.ru_utime);
  tms->tms_stime = CONVTCK(ru.ru_stime);

  if (getrusage(RUSAGE_CHILDREN, &ru) < 0) return ((clock_t)-1);
  tms->tms_cutime = CONVTCK(ru.ru_utime);
  tms->tms_cstime = CONVTCK(ru.ru_stime);

  if (gettimeofday(&tv, (struct timezone *)0) < 0) return ((clock_t)-1);
  rv = (clock_t)(CONVTCK(tv));
#else  /* !HAVE_GETRUSAGE */
  if (clk_tck == -1) clk_tck = get_clk_tck();

  /* We can't do anything. */
  tms->tms_utime = tms->tms_stime = (clock_t)0;
  tms->tms_cutime = tms->tms_cstime = (clock_t)0;

  rv = (clock_t)time((time_t *)0) * clk_tck;
#endif /* HAVE_GETRUSAGE */

  return rv;
}
#endif /* !HAVE_TIMES */
