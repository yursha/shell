/* wcsnwidth.c - compute display width of wide character string, up to max
                 specified width, return length. */


#include <config.h>

#if defined(HANDLE_MULTIBYTE)

#include <stdc.h>
#include <wchar.h>
#include <bashansi.h>

/* Return the number of wide characters that will be displayed from wide string
   PWCS.  If the display width exceeds MAX, return the number of wide chars
   from PWCS required to display MAX characters on the screen. */
int wcsnwidth(pwcs, n, max) const wchar_t *pwcs;
size_t n, max;
{
  wchar_t wc, *ws;
  int len, l;

  len = 0;
  ws = (wchar_t *)pwcs;
  while (n-- > 0 && (wc = *ws++) != L'\0') {
    l = wcwidth(wc);
    if (l < 0)
      return (-1);
    else if (l == max - len)
      return (ws - pwcs);
    else if (l > max - len)
      return (--ws - pwcs);
    len += l;
  }
  return (ws - pwcs);
}
#endif
