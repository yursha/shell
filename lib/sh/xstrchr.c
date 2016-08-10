/* xstrchr.c - strchr(3) that handles multibyte characters. */


#include <config.h>

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#include "bashansi.h"
#include "shmbutil.h"

#undef xstrchr

/* In some locales, the non-first byte of some multibyte characters have
   the same value as some ascii character.  Faced with these strings, a
   legacy strchr() might return the wrong value. */

char *
#if defined(PROTOTYPES)
xstrchr(const char *s, int c)
#else
    xstrchr(s, c) const char *s;
int c;
#endif
{
#if HANDLE_MULTIBYTE
  char *pos;
  mbstate_t state;
  size_t strlength, mblength;

  /* The locale encodings with said weird property are BIG5, BIG5-HKSCS,
     GBK, GB18030, SHIFT_JIS, and JOHAB.  They exhibit the problem only
     when c >= 0x30.  We can therefore use the faster bytewise search if
     c <= 0x30. */
  if ((unsigned char)c >= '0' && MB_CUR_MAX > 1) {
    pos = (char *)s;
    memset(&state, '\0', sizeof(mbstate_t));
    strlength = strlen(s);

    while (strlength > 0) {
      mblength = mbrlen(pos, strlength, &state);
      if (mblength == (size_t)-2 || mblength == (size_t)-1 ||
          mblength == (size_t)0)
        mblength = 1;

      if (c == (unsigned char)*pos) return pos;

      strlength -= mblength;
      pos += mblength;
    }

    return ((char *)NULL);
  } else
#endif
    return (strchr(s, c));
}
