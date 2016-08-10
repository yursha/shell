/* strdup - return a copy of a string in newly-allocated memory. */


#include <config.h>

/* Get specification.  */
#include <string.h>
#include <stdlib.h>

/* Duplicate S, returning an identical malloc'd string.  */
char *strdup(s) const char *s;
{
  size_t len;
  void *new;

  len = strlen(s) + 1;
  if ((new = malloc(len)) == NULL) return NULL;

  memcpy(new, s, len);
  return ((char *)new);
}
