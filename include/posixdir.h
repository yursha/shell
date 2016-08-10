/* posixdir.h -- Posix directory reading includes and defines. */

/* This file should be included instead of <dirent.h> or <sys/dir.h>. */

#if !defined(_POSIXDIR_H_)
#define _POSIXDIR_H_

#if defined(HAVE_DIRENT_H)
#include <dirent.h>
#if defined(HAVE_STRUCT_DIRENT_D_NAMLEN)
#define D_NAMLEN(d) ((d)->d_namlen)
#else
#define D_NAMLEN(d) (strlen((d)->d_name))
#endif /* !HAVE_STRUCT_DIRENT_D_NAMLEN */
#else
#if defined(HAVE_SYS_NDIR_H)
#include <sys/ndir.h>
#endif
#if defined(HAVE_SYS_DIR_H)
#include <sys/dir.h>
#endif
#if defined(HAVE_NDIR_H)
#include <ndir.h>
#endif
#if !defined(dirent)
#define dirent direct
#endif /* !dirent */
#define D_NAMLEN(d) ((d)->d_namlen)
#endif /* !HAVE_DIRENT_H */

/* The bash code fairly consistenly uses d_fileno; make sure it's available */
#if defined(HAVE_STRUCT_DIRENT_D_INO) && !defined(HAVE_STRUCT_DIRENT_D_FILENO)
#define d_fileno d_ino
#endif

/* Posix does not require that the d_ino field be present, and some
   systems do not provide it. */
#if !defined(HAVE_STRUCT_DIRENT_D_INO) || defined(BROKEN_DIRENT_D_INO)
#define REAL_DIR_ENTRY(dp) 1
#else
#define REAL_DIR_ENTRY(dp) (dp->d_ino != 0)
#endif /* _POSIX_SOURCE */

#if defined(HAVE_STRUCT_DIRENT_D_INO) && !defined(BROKEN_DIRENT_D_INO)
#define D_INO_AVAILABLE
#endif

/* Signal the rest of the code that it can safely use dirent.d_fileno */
#if defined(D_INO_AVAILABLE) || defined(HAVE_STRUCT_DIRENT_D_FILENO)
#define D_FILENO_AVAILABLE 1
#endif

#endif /* !_POSIXDIR_H_ */
