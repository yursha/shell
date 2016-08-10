/* clock.c - operations on struct tms and clock_t's */

#include <config.h>

#if defined(HAVE_TIMES)

#include <sys/types.h>
#include <posixtime.h>

#if defined(HAVE_SYS_TIMES_H)
#include <sys/times.h>
#endif

#include <stdio.h>
#include <stdc.h>

extern long get_clk_tck(void);

void clock_t_to_secs(t, sp, sfp) clock_t t;
time_t *sp;
int *sfp;
{
  static long clk_tck = -1;

  if (clk_tck == -1) clk_tck = get_clk_tck();

  *sfp = t % clk_tck;
  *sfp = (*sfp * 1000) / clk_tck;

  *sp = t / clk_tck;

  /* Sanity check */
  if (*sfp >= 1000) {
    *sp += 1;
    *sfp -= 1000;
  }
}

/* Print the time defined by a clock_t (returned by the `times' and `time'
   system calls) in a standard way to stdio stream FP.  This is scaled in
   terms of the value of CLK_TCK, which is what is returned by the
   `times' call. */
void print_clock_t(fp, t) FILE *fp;
clock_t t;
{
  time_t timestamp;
  long minutes;
  int seconds, seconds_fraction;

  clock_t_to_secs(t, &timestamp, &seconds_fraction);

  minutes = timestamp / 60;
  seconds = timestamp % 60;

  fprintf(fp, "%ldm%d.%03ds", minutes, seconds, seconds_fraction);
}
#endif /* HAVE_TIMES */
