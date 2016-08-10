
static int INTERNAL_GLOB_PATTERN_P(const CHAR *);

/* Return nonzero if PATTERN has any special globbing chars in it.
   Compiled twice, once each for single-byte and multibyte characters. */
static int INTERNAL_GLOB_PATTERN_P(pattern) const CHAR *pattern;
{
  register const CHAR *p;
  register CHAR c;
  int bopen;

  p = pattern;
  bopen = 0;

  while ((c = *p++) != L('\0')) switch (c) {
      case L('?'):
      case L('*'):
        return 1;

      case L('['): /* Only accept an open brace if there is a close */
        bopen++;   /* brace to match it.  Bracket expressions must be */
        continue;  /* complete, according to Posix.2 */
      case L(']'):
        if (bopen) return 1;
        continue;

      case L('+'): /* extended matching operators */
      case L('@'):
      case L('!'):
        if (*p == L('(')) /*) */
          return 1;
        continue;

      case L('\\'):
        if (*p++ == L('\0')) return 0;
    }

  return 0;
}

#undef INTERNAL_GLOB_PATTERN_P
#undef L
#undef INT
#undef CHAR
