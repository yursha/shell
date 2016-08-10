/* setlinebuf.c - line-buffer a stdio stream. */


#include <config.h>

#include <stdio.h>

#include <xmalloc.h>

#if defined(USING_BASH_MALLOC)
#define LBUF_BUFSIZE 1008
#else
#define LBUF_BUFSIZE BUFSIZ
#endif

/* Cause STREAM to buffer lines as opposed to characters or blocks. */
int sh_setlinebuf(stream) FILE *stream;
{
  char *local_linebuf;

#if !defined(HAVE_SETLINEBUF) && !defined(HAVE_SETVBUF)
  return (0);
#endif

#if defined(USING_BASH_MALLOC)
  local_linebuf = (char *)xmalloc(LBUF_BUFSIZE);
#else
  local_linebuf = (char *)NULL;
#endif

#if defined(HAVE_SETVBUF)

#if defined(SETVBUF_REVERSED)
  return (setvbuf(stream, _IOLBF, local_linebuf, LBUF_BUFSIZE));
#else  /* !SETVBUF_REVERSED */
  return (setvbuf(stream, local_linebuf, _IOLBF, LBUF_BUFSIZE));
#endif /* !SETVBUF_REVERSED */
#else  /* !HAVE_SETVBUF */

  setlinebuf(stream);
  return (0);

#endif /* !HAVE_SETVBUF */
}
