/* strcasecmp.c - functions for case-insensitive string comparison. */

#include <config.h>

#if !defined(HAVE_STRCASECMP)

#include <stdc.h>
#include <bashansi.h>
#include <chartypes.h>

/* Compare at most COUNT characters from string1 to string2.  Case
   doesn't matter. */
int strncasecmp(string1, string2, count) const char *string1;
const char *string2;
int count;
{
  register const char *s1;
  register const char *s2;
  register int r;

  if (count <= 0 || (string1 == string2)) return 0;

  s1 = string1;
  s2 = string2;
  do {
    if ((r = TOLOWER((unsigned char)*s1) - TOLOWER((unsigned char)*s2)) != 0)
      return r;
    if (*s1++ == '\0') break;
    s2++;
  } while (--count != 0);

  return (0);
}

/* strcmp (), but caseless. */
int strcasecmp(string1, string2) const char *string1;
const char *string2;
{
  register const char *s1;
  register const char *s2;
  register int r;

  s1 = string1;
  s2 = string2;

  if (s1 == s2) return (0);

  while ((r = TOLOWER((unsigned char)*s1) - TOLOWER((unsigned char)*s2)) == 0) {
    if (*s1++ == '\0') return 0;
    s2++;
  }

  return (r);
}
#endif /* !HAVE_STRCASECMP */
