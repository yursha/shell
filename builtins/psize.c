/* psize.c - Find pipe size. */

/*  Write output in 128-byte chunks until we get a sigpipe or write gets an
    EPIPE.  Then report how many bytes we wrote.  We assume that this is the
    pipe size. */
#include <config.h>

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include <stdio.h>
#include "../bashtypes.h"
#include <signal.h>
#include <errno.h>

#include "../command.h"
#include "../general.h"
#include "../sig.h"

#ifndef errno
extern int errno;
#endif

int nw;

sighandler sigpipe(sig) int sig;
{
  fprintf(stderr, "%d\n", nw);
  exit(0);
}

int main(argc, argv) int argc;
char **argv;
{
  char buf[128];
  register int i;

  for (i = 0; i < 128; i++) buf[i] = ' ';

  signal(SIGPIPE, sigpipe);

  nw = 0;
  for (;;) {
    int n;
    n = write(1, buf, 128);
    nw += n;
  }
  return (0);
}
