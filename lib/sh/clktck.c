/* clktck.c - get the value of CLK_TCK. */

#include <config.h>

#include <bashtypes.h>
#if defined(HAVE_SYS_PARAM_H)
#include <sys/param.h>
#endif

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#if defined(HAVE_LIMITS_H)
#include <limits.h>
#endif

#if !defined(HAVE_SYSCONF) || !defined(_SC_CLK_TCK)
#if !defined(CLK_TCK)
#if defined(HZ)
#define CLK_TCK HZ
#else
#define CLK_TCK 60
#endif
#endif /* !CLK_TCK */
#endif /* !HAVE_SYSCONF && !_SC_CLK_TCK */

long get_clk_tck() {
  static long retval = 0;

  if (retval != 0) return (retval);

#if defined(HAVE_SYSCONF) && defined(_SC_CLK_TCK)
  retval = sysconf(_SC_CLK_TCK);
#else  /* !SYSCONF || !_SC_CLK_TCK */
  retval = CLK_TCK;
#endif /* !SYSCONF || !_SC_CLK_TCK */

  return (retval);
}
