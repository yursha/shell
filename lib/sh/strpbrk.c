/* strpbrk.c - locate multiple characters in a string */


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#if !defined(HAVE_STRPBRK)

#include <stdc.h>

/* Find the first occurrence in S of any character in ACCEPT.  */
char *strpbrk(s, accept) register const char *s;
register const char *accept;
{
  while (*s != '\0') {
    const char *a = accept;
    while (*a != '\0')
      if (*a++ == *s) return (char *)s;
    ++s;
  }

  return 0;
}
#endif
