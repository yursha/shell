/* siglist.c -- signal list for those machines that don't have one. */

#include "config.h"

#if !defined(HAVE_SYS_SIGLIST) && !defined(HAVE_UNDER_SYS_SIGLIST) && \
    !defined(HAVE_STRSIGNAL)

#include <stdio.h>
#include "bashtypes.h"
#include <signal.h>

#include "siglist.h"

#if !defined(NSIG)
#include "trap.h"
#endif

#include "xmalloc.h"

char *sys_siglist[NSIG];

void initialize_siglist() {
  register int i;

  for (i = 0; i < NSIG; i++) sys_siglist[i] = (char *)0x0;

  sys_siglist[0] = "Bogus signal";

#if defined(SIGHUP)
  sys_siglist[SIGHUP] = "Hangup";
#endif

#if defined(SIGINT)
  sys_siglist[SIGINT] = "Interrupt";
#endif

#if defined(SIGQUIT)
  sys_siglist[SIGQUIT] = "Quit";
#endif

#if defined(SIGILL)
  sys_siglist[SIGILL] = "Illegal instruction";
#endif

#if defined(SIGTRAP)
  sys_siglist[SIGTRAP] = "BPT trace/trap";
#endif

#if defined(SIGIOT) && !defined(SIGABRT)
#define SIGABRT SIGIOT
#endif

#if defined(SIGABRT)
  sys_siglist[SIGABRT] = "ABORT instruction";
#endif

#if defined(SIGEMT)
  sys_siglist[SIGEMT] = "EMT instruction";
#endif

#if defined(SIGFPE)
  sys_siglist[SIGFPE] = "Floating point exception";
#endif

#if defined(SIGKILL)
  sys_siglist[SIGKILL] = "Killed";
#endif

#if defined(SIGBUS)
  sys_siglist[SIGBUS] = "Bus error";
#endif

#if defined(SIGSEGV)
  sys_siglist[SIGSEGV] = "Segmentation fault";
#endif

#if defined(SIGSYS)
  sys_siglist[SIGSYS] = "Bad system call";
#endif

#if defined(SIGPIPE)
  sys_siglist[SIGPIPE] = "Broken pipe";
#endif

#if defined(SIGALRM)
  sys_siglist[SIGALRM] = "Alarm clock";
#endif

#if defined(SIGTERM)
  sys_siglist[SIGTERM] = "Terminated";
#endif

#if defined(SIGURG)
  sys_siglist[SIGURG] = "Urgent IO condition";
#endif

#if defined(SIGSTOP)
  sys_siglist[SIGSTOP] = "Stopped (signal)";
#endif

#if defined(SIGTSTP)
  sys_siglist[SIGTSTP] = "Stopped";
#endif

#if defined(SIGCONT)
  sys_siglist[SIGCONT] = "Continue";
#endif

#if !defined(SIGCHLD) && defined(SIGCLD)
#define SIGCHLD SIGCLD
#endif

#if defined(SIGCHLD)
  sys_siglist[SIGCHLD] = "Child death or stop";
#endif

#if defined(SIGTTIN)
  sys_siglist[SIGTTIN] = "Stopped (tty input)";
#endif

#if defined(SIGTTOU)
  sys_siglist[SIGTTOU] = "Stopped (tty output)";
#endif

#if defined(SIGIO)
  sys_siglist[SIGIO] = "I/O ready";
#endif

#if defined(SIGXCPU)
  sys_siglist[SIGXCPU] = "CPU limit";
#endif

#if defined(SIGXFSZ)
  sys_siglist[SIGXFSZ] = "File limit";
#endif

#if defined(SIGVTALRM)
  sys_siglist[SIGVTALRM] = "Alarm (virtual)";
#endif

#if defined(SIGPROF)
  sys_siglist[SIGPROF] = "Alarm (profile)";
#endif

#if defined(SIGWINCH)
  sys_siglist[SIGWINCH] = "Window changed";
#endif

#if defined(SIGLOST)
  sys_siglist[SIGLOST] = "Record lock";
#endif

#if defined(SIGUSR1)
  sys_siglist[SIGUSR1] = "User signal 1";
#endif

#if defined(SIGUSR2)
  sys_siglist[SIGUSR2] = "User signal 2";
#endif

#if defined(SIGMSG)
  sys_siglist[SIGMSG] = "HFT input data pending";
#endif

#if defined(SIGPWR)
  sys_siglist[SIGPWR] = "power failure imminent";
#endif

#if defined(SIGDANGER)
  sys_siglist[SIGDANGER] = "system crash imminent";
#endif

#if defined(SIGMIGRATE)
  sys_siglist[SIGMIGRATE] = "migrate process to another CPU";
#endif

#if defined(SIGPRE)
  sys_siglist[SIGPRE] = "programming error";
#endif

#if defined(SIGGRANT)
  sys_siglist[SIGGRANT] = "HFT monitor mode granted";
#endif

#if defined(SIGRETRACT)
  sys_siglist[SIGRETRACT] = "HFT monitor mode retracted";
#endif

#if defined(SIGSOUND)
  sys_siglist[SIGSOUND] = "HFT sound sequence has completed";
#endif

#if defined(SIGINFO)
  sys_siglist[SIGINFO] = "Information request";
#endif

  for (i = 0; i < NSIG; i++) {
    if (!sys_siglist[i]) {
      sys_siglist[i] = (char *)xmalloc(10 + strlen("Unknown Signal #"));

      sprintf(sys_siglist[i], "Unknown Signal #%d", i);
    }
  }
}
#endif /* !HAVE_SYS_SIGLIST && !HAVE_UNDER_SYS_SIGLIST && !HAVE_STRSIGNAL */
