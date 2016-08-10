
#include <config.h>

#if defined(HANDLE_MULTIBYTE)
#include <stdlib.h>
#include <limits.h>

#include <shmbutil.h>
#include <shmbchar.h>

#if IS_BASIC_ASCII

/* Bit table of characters in the ISO C "basic character set".  */
const unsigned int is_basic_table[UCHAR_MAX / 32 + 1] = {
    0x00001a00, /* '\t' '\v' '\f' */
    0xffffffef, /* ' '...'#' '%'...'?' */
    0xfffffffe, /* 'A'...'Z' '[' '\\' ']' '^' '_' */
    0x7ffffffe  /* 'a'...'z' '{' '|' '}' '~' */
                /* The remaining bits are 0.  */
};

#endif /* IS_BASIC_ASCII */

size_t mbstrlen(s) const char *s;
{
  size_t clen, nc;
  mbstate_t mbs = {0}, mbsbak = {0};
  int f, mb_cur_max;

  nc = 0;
  mb_cur_max = MB_CUR_MAX;
  while (*s &&
         (clen = (f = is_basic(*s)) ? 1 : mbrlen(s, mb_cur_max, &mbs)) != 0) {
    if (MB_INVALIDCH(clen)) {
      clen = 1; /* assume single byte */
      mbs = mbsbak;
    }

    if (f == 0) mbsbak = mbs;

    s += clen;
    nc++;
  }
  return nc;
}

/* Return pointer to first multibyte char in S, or NULL if none. */
char *mbsmbchar(s) const char *s;
{
  char *t;
  size_t clen;
  mbstate_t mbs = {0};
  int mb_cur_max;

  mb_cur_max = MB_CUR_MAX;
  for (t = (char *)s; *t; t++) {
    if (is_basic(*t)) continue;

    clen = mbrlen(t, mb_cur_max, &mbs);

    if (clen == 0) return 0;
    if (MB_INVALIDCH(clen)) continue;

    if (clen > 1) return t;
  }
  return 0;
}

int sh_mbsnlen(src, srclen, maxlen) const char *src;
size_t srclen;
int maxlen;
{
  int count;
  int sind;
  DECLARE_MBSTATE;

  for (sind = count = 0; src[sind];) {
    count++; /* number of multibyte characters */
    ADVANCE_CHAR(src, srclen, sind);
    if (sind > maxlen) break;
  }

  return count;
}
#endif
