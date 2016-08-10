/* wcswidth.c - compute display width of wide character string */

#include <config.h>

#if defined(HANDLE_MULTIBYTE) && !defined(HAVE_WCSWIDTH)

#include <stdc.h>
#include <wchar.h>
#include <bashansi.h>

int wcswidth(pwcs, n) const wchar_t *pwcs;
size_t n;
{
  wchar_t wc;
  int len, l;

  len = 0;
  while (n-- > 0 && (wc = *pwcs++) != L'\0') {
    if ((l = wcwidth(wc)) < 0) return (-1);
    len += l;
  }
  return (len);
}
#endif
