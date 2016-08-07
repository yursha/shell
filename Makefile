all: .made

PACKAGE = shell
VERSION = 0.1.0-SNAPSHOT

PACKAGE_NAME = shell
PACKAGE_STRING = shell 0.1.0-SNAPSHOT
PACKAGE_VERSION = 0.1.0-SNAPSHOT

PACKAGE_TARNAME = shell

# Include some boilerplate Gnu makefile definitions.
prefix = /usr/local

exec_prefix = ${prefix}

datarootdir = ${prefix}/share

bindir = ${exec_prefix}/bin
libdir = ${exec_prefix}/lib
infodir = ${datarootdir}/info
includedir = ${prefix}/include
datadir = ${datarootdir}
localedir = ${datarootdir}/locale

loadablesdir = ${libdir}/bash
headersdir = $(includedir)/$(PACKAGE_NAME)

docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}

mandir = ${datarootdir}/man
manpfx = man

man1ext = .1
man1dir = $(mandir)/$(manpfx)1
man3ext = .3
man3dir = $(mandir)/$(manpfx)3

htmldir = ${docdir}

# Support an alternate destination root directory for package building
DESTDIR =

topdir = .
BUILD_DIR = /home/ayursha/code/shell
top_builddir = /home/ayursha/code/shell
srcdir = .

CC = gcc
CC_FOR_BUILD = $(CC)
YACC = bison -y
SHELL = /bin/sh
CP = cp
RM = rm -f
AR = ar
ARFLAGS = cr
RANLIB = ranlib
SIZE = size

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALLMODE= -m 0755
INSTALLMODE2 = -m 0555

TESTSCRIPT = run-all

DEBUGGER_START_FILE = ${datadir}/bashdb/bashdb-main.inc

#If you have purify, and want to use it, run the make as `make PURIFY=purify'
#PURIFY = @PURIFY@

# Here is a rule for making .o files from .c files that does not
# force the type of the machine (like -M_MACHINE) into the flags.
.c.o:
	rm -f $@
	$(CC) $(CCFLAGS) -c $<

# The name of this program and some version information.
VERSPROG = bashversion
VERSOBJ = bashversion.o

Program = bash
PatchLevel = `$(BUILD_DIR)/$(VERSPROG) -p`
RELSTATUS = "development"
Version = 0.1.0-SNAPSHOT

Machine = x86_64
OS = linux-gnu
VENDOR = Fedora
MACHTYPE = x86_64-Fedora-linux-gnu

# comment out for release
DEBUG = -DDEBUG
MALLOC_DEBUG = -DMALLOC_DEBUG

THIS_SH = $(BUILD_DIR)/bash

# PROFILE_FLAGS is either -pg, to generate profiling info for use
# with gprof, or nothing (the default).
PROFILE_FLAGS= 

CFLAGS = -g -O2 -Wno-parentheses -Wno-format-security -Wfatal-errors
CFLAGS_FOR_BUILD = -g -O2 -Wno-parentheses -Wno-format-security 
CPPFLAGS = 
CPPFLAGS_FOR_BUILD = 
LOCAL_CFLAGS =  ${DEBUG} ${MALLOC_DEBUG}
DEFS = -DHAVE_CONFIG_H
LOCAL_DEFS = -DSHELL

LOCALE_DEFS = -DLOCALEDIR='"$(localedir)"' -DPACKAGE='"$(PACKAGE)"'

LOCAL_LIBS = 
LIBS = $(BUILTINS_LIB) $(LIBRARIES) -ldl 
LIBS_FOR_BUILD = 

STATIC_LD = 
LOCAL_LDFLAGS = -rdynamic

SYSTEM_FLAGS = -DPROGRAM='"bash"' -DCONF_HOSTTYPE='"$(Machine)"' -DCONF_OSTYPE='"$(OS)"' -DCONF_MACHTYPE='"$(MACHTYPE)"' -DCONF_VENDOR='"$(VENDOR)"' $(LOCALE_DEFS)

BASE_CCFLAGS = $(PROFILE_FLAGS) $(SYSTEM_FLAGS) $(LOCAL_DEFS) \
	  $(DEFS) $(LOCAL_CFLAGS) $(INCLUDES)

CCFLAGS = $(BASE_CCFLAGS) $(CPPFLAGS) $(CFLAGS)

CCFLAGS_FOR_BUILD = $(BASE_CCFLAGS) $(CPPFLAGS_FOR_BUILD) $(CFLAGS_FOR_BUILD)

LDFLAGS =  $(STATIC_LD) $(LOCAL_LDFLAGS) $(PROFILE_FLAGS) $(CFLAGS)
LDFLAGS_FOR_BUILD = $(LDFLAGS) $(LOCAL_LDFLAGS) $(CFLAGS_FOR_BUILD)

INCLUDES = -I.  -I$(srcdir) -I$(BASHINCDIR) -I$(LIBSRC) $(INTL_INC)

# Maybe add: -Wextra
GCC_LINT_FLAGS = -O -Wall -Wshadow -Wpointer-arith -Wcast-qual -Wno-parentheses \
		 -Wcast-align -Wstrict-prototypes -Wconversion -Wformat \
		 -Wformat-nonliteral -Wmissing-braces -Wuninitialized \
		 -Wmissing-declarations  -Winline \
		 -Wmissing-prototypes -Wtraditional -Wredundant-decls -pedantic

GCC_LINT_CFLAGS = $(BASE_CCFLAGS) $(CPPFLAGS) $(GCC_LINT_FLAGS)

#
# Support libraries
# 

LIBSUBDIR = lib
LIBSRC = $(srcdir)/$(LIBSUBDIR)

LIBBUILD = ${BUILD_DIR}/${LIBSUBDIR}

SUBDIR_INCLUDES = -I.  -I$(topdir) -I$(topdir)/$(LIBSUBDIR)

BUILD_INCLUDED_LIBINTL = no
USE_INCLUDED_LIBINTL = no

# the bash library
# the library is a mix of functions that the C library does not provide on
# some platforms and general shell utility functions
SH_LIBSRC = $(LIBSRC)/sh
SH_LIBDIR = ./${LIBSUBDIR}/sh
SH_ABSSRC = ${topdir}/${SH_LIBSRC}

SHLIB_SOURCE =	${SH_LIBSRC}/clktck.c ${SH_LIBSRC}/getcwd.c \
		${SH_LIBSRC}/getenv.c ${SH_LIBSRC}/oslib.c \
		${SH_LIBSRC}/setlinebuf.c ${SH_LIBSRC}/strchrnul.c \
		${SH_LIBSRC}/strcasecmp.c ${SH_LIBSRC}/strdup.c \
		${SH_LIBSRC}/strerror.c \
		${SH_LIBSRC}/strtod.c ${SH_LIBSRC}/strtol.c \
		${SH_LIBSRC}/strtoul.c ${SH_LIBSRC}/vprint.c \
		${SH_LIBSRC}/itos.c ${SH_LIBSRC}/rename.c \
		${SH_LIBSRC}/zread.c ${SH_LIBSRC}/zwrite.c \
		${SH_LIBSRC}/shtty.c ${SH_LIBSRC}/inet_aton.c \
		${SH_LIBSRC}/netopen.c ${SH_LIBSRC}/strpbrk.c \
		${SH_LIBSRC}/timeval.c ${SH_LIBSRC}/clock.c \
		${SH_LIBSRC}/makepath.c ${SH_LIBSRC}/pathcanon.c \
		${SH_LIBSRC}/pathphys.c ${SH_LIBSRC}/stringlist.c \
		${SH_LIBSRC}/stringvec.c ${SH_LIBSRC}/tmpfile.c \
		${SH_LIBSRC}/spell.c ${SH_LIBSRC}/strtrans.c \
		${SH_LIBSRC}/strcasestr.c ${SH_LIBSRC}/shquote.c \
		${SH_LIBSRC}/snprintf.c ${SH_LIBSRC}/mailstat.c \
		${SH_LIBSRC}/fmtulong.c ${SH_LIBSRC}/fmtullong.c \
		${SH_LIBSRC}/strtoll.c ${SH_LIBSRC}/strtoull.c \
		${SH_LIBSRC}/strtoimax.c ${SH_LIBSRC}/strtoumax.c \
		${SH_LIBSRC}/fmtumax.c ${SH_LIBSRC}/netconn.c \
		${SH_LIBSRC}/mktime.c ${SH_LIBSRC}/strftime.c \
		${SH_LIBSRC}/memset.c ${SH_LIBSRC}/mbschr.c \
		${SH_LIBSRC}/zcatfd.c ${SH_LIBSRC}/shmatch.c \
		${SH_LIBSRC}/strnlen.c ${SH_LIBSRC}/winsize.c \
		${SH_LIBSRC}/eaccess.c ${SH_LIBSRC}/wcsdup.c \
		${SH_LIBSRC}/zmapfd.c ${SH_LIBSRC}/fpurge.c \
		${SH_LIBSRC}/zgetline.c ${SH_LIBSRC}/mbscmp.c \
		${SH_LIBSRC}/casemod.c ${SH_LIBSRC}/uconvert.c \
		${SH_LIBSRC}/ufuncs.c ${SH_LIBSRC}/dprintf.c \
		${SH_LIBSRC}/input_avail.c ${SH_LIBSRC}/mbscasecmp.c \
		${SH_LIBSRC}/fnxform.c ${SH_LIBSRC}/unicode.c \
		${SH_LIBSRC}/wcswidth.c ${SH_LIBSRC}/wcsnwidth.c \
		${SH_LIBSRC}/shmbchar.c

SHLIB_LIB = -lsh
SHLIB_LIBNAME = libsh.a
SHLIB_LIBRARY = ${SH_LIBDIR}/${SHLIB_LIBNAME}
SHLIB_LDFLAGS = -L${SH_LIBDIR}
SHLIB_DEP = ${SHLIB_LIBRARY}

# we assume for now that readline source is being shipped with bash
RL_LIBSRC = $(LIBSRC)/readline
RL_LIBDOC = $(RL_LIBSRC)/doc
RL_LIBDIR = ./$(LIBSUBDIR)/readline
RL_ABSSRC = ${topdir}/$(RL_LIBDIR)

RL_INCLUDEDIR = 

READLINE_LIB = -lreadline
READLINE_LIBRARY = $(RL_LIBDIR)/libreadline.a
READLINE_LDFLAGS = -L${RL_LIBDIR}
READLINE_DEP = $(READLINE_LIBRARY)

# The source, object and documentation of the GNU Readline library.
READLINE_SOURCE	= $(RL_LIBSRC)/rldefs.h $(RL_LIBSRC)/rlconf.h \
		  $(RL_LIBSRC)/readline.h $(RL_LIBSRC)/tcap.h \
		  $(RL_LIBSRC)/chardefs.h $(RL_LIBSRC)/keymaps.h \
		  $(RL_LIBSRC)/history.h $(RL_LIBSRC)/histlib.h \
		  $(RL_LIBSRC)/posixstat.h $(RL_LIBSRC)/tilde.h \
		  $(RL_LIBSRC)/rlstdc.h ${RL_LIBSRC}/xmalloc.h \
		  $(RL_LIBSRC)/rlshell.h ${RL_LIBSRC}/rlprivate.h \
		  $(RL_LIBSRC)/colors.h  $(RL_LIBSRC)/parse-colors.h \
		  $(RL_LIBSRC)/funmap.c $(RL_LIBSRC)/emacs_keymap.c \
		  $(RL_LIBSRC)/search.c $(RL_LIBSRC)/vi_keymap.c \
		  $(RL_LIBSRC)/keymaps.c $(RL_LIBSRC)/parens.c \
		  $(RL_LIBSRC)/vi_mode.c $(RL_LIBSRC)/callback.c \
		  $(RL_LIBSRC)/readline.c $(RL_LIBSRC)/tilde.c \
		  $(RL_LIBSRC)/rltty.c $(RL_LIBSRC)/complete.c \
		  $(RL_LIBSRC)/bind.c $(RL_LIBSRC)/isearch.c \
		  $(RL_LIBSRC)/display.c $(RL_LIBSRC)/signals.c \
		  $(RL_LIBSRC)/util.c $(RL_LIBSRC)/kill.c $(RL_LIBSRC)/text.c \
		  $(RL_LIBSRC)/undo.c $(RL_LIBSRC)/macro.c \
		  $(RL_LIBSRC)/terminal.c $(RL_LIBSRC)/nls.c \
		  $(RL_LIBSRC)/input.c $(RL_LIBSRC)/xmalloc.c \
		  $(RL_LIBSRC)/shell.c $(RL_LIBSRC)/savestring.c \
		  $(RL_LIBSRC)/colors.c $(RL_LIBSRC)/parse-colors.c \
		  $(RL_LIBSRC)/misc.c $(RL_LIBSRC)/mbutil.c $(RL_LIBSRC)/compat.c \
		  $(RL_LIBSRC)/histexpand.c $(RL_LIBSRC)/history.c \
		  $(RL_LIBSRC)/histsearch.c $(RL_LIBSRC)/histfile.c

READLINE_OBJ	= $(RL_LIBDIR)/readline.o $(RL_LIBDIR)/funmap.o \
		  $(RL_LIBDIR)/parens.o $(RL_LIBDIR)/search.o \
		  $(RL_LIBDIR)/keymaps.o $(RL_LIBDIR)/xmalloc.o \
		  $(RL_LIBDIR)/rltty.o $(RL_LIBDIR)/complete.o \
		  $(RL_LIBDIR)/bind.o $(RL_LIBDIR)/isearch.o \
		  $(RL_LIBDIR)/display.o $(RL_LIBDIR)/signals.o \
		  $(RL_LIBDIR)/tilde.o $(RL_LIBDIR)/util.o \
		  $(RL_LIBDIR)/kill.o $(RL_LIBDIR)/undo.o $(RL_LIBDIR)/nls.o \
		  $(RL_LIBDIR)/macro.o $(RL_LIBDIR)/input.o \
		  $(RL_LIBDIR)/terminal.o $(RL_LIBDIR)/callback.o \
		  $(RL_LIBDIR)/shell.o $(RL_LIBDIR)/savestring.o \
		  $(RL_LIBDIR)/mbutil.o $(RL_LIBDIR)/compat.o \
		  $(RL_LIBDIR)/history.o $(RL_LIBDIR)/histexpand.o \
		  $(RL_LIBDIR)/histsearch.o $(RL_LIBDIR)/histfile.o \
		  $(RL_LIBDIR)/colors.o $(RL_LIBDIR)/parse-colors.o

HIST_LIBSRC = $(LIBSRC)/readline
HIST_LIBDIR = ./$(LIBSUBDIR)/readline
HIST_ABSSRC = ${topdir}/$(HIST_LIBDIR)

HISTORY_LIB = -lhistory
HISTORY_LIBRARY = $(HIST_LIBDIR)/libhistory.a
HISTORY_LDFLAGS = -L$(HIST_LIBDIR)
HISTORY_DEP = $(HISTORY_LIBRARY)

# The source, object and documentation of the history library.
HISTORY_SOURCE	= $(HIST_LIBSRC)/history.c $(HIST_LIBSRC)/histexpand.c \
		  $(HIST_LIBSRC)/histsearch.c $(HIST_LIBSRC)/histfile.c \
		  $(HIST_LIBSRC)/shell.c \
		  $(HIST_LIBSRC)/history.h $(HIST_LIBSRC)/histlib.h
HISTORY_OBJ	= $(HIST_LIBDIR)/history.o $(HIST_LIBDIR)/histexpand.o \
		  $(HIST_LIBDIR)/histsearch.o $(HIST_LIBDIR)/histfile.o \
		  $(HIST_LIBDIR)/shell.o

# You only need termcap (or curses) if you are linking with GNU Readline.
TERM_LIBSRC = $(LIBSRC)/termcap
TERM_LIBDIR = ./$(LIBSUBDIR)/termcap
TERM_ABSSRC = ${topdir}/$(TERM_LIBDIR)

TERMCAP_LIB = -ltermcap
TERMCAP_LIBRARY = $(TERM_LIBDIR)/libtermcap.a
TERMCAP_LDFLAGS = -L$(TERM_LIBDIR)
TERMCAP_DEP = 

TERMCAP_SOURCE	= $(TERM_LIBSRC)/termcap.c $(TERM_LIBSRC)/tparam.c
TERMCAP_OBJ	= $(TERM_LIBDIR)/termcap.o $(TERM_LIBDIR)/tparam.o

GLOB_LIBSRC = $(LIBSRC)/glob
GLOB_LIBDIR = ./$(LIBSUBDIR)/glob
GLOB_ABSSRC = ${topdir}/$(GLOB_LIBDIR)

GLOB_LIB     = -lglob
GLOB_LIBRARY = $(GLOB_LIBDIR)/libglob.a
GLOB_LDFLAGS = -L$(GLOB_LIBDIR)
GLOB_DEP = $(GLOB_LIBRARY)

GLOB_SOURCE = $(GLOB_LIBSRC)/glob.c $(GLOB_LIBSRC)/strmatch.c \
	      $(GLOB_LIBSRC)/smatch.c $(GLOB_LIBSRC)/xmbsrtowcs.c \
	      $(GLOB_LIBSRC)/glob_loop.c $(GLOB_LIBSRC)/sm_loop.c \
	      $(GLOB_LIBSRC)/gmisc.c \
	      $(GLOB_LIBSRC)/glob.h $(GLOB_LIBSRC)/strmatch.h
GLOB_OBJ    = $(GLOB_LIBDIR)/glob.o $(GLOB_LIBDIR)/strmatch.o \
	      $(GLOB_LIBDIR)/smatch.o $(GLOB_LIBDIR)/xmbsrtowcs.o \
	      $(GLOB_LIBDIR)/gmisc.o

# The source, object and documentation for the GNU Tilde library.
TILDE_LIBSRC = $(LIBSRC)/tilde
TILDE_LIBDIR = ./$(LIBSUBDIR)/tilde
TILDE_ABSSRC = ${topdir}/$(TILDE_LIBDIR)

TILDE_LIB = -ltilde
TILDE_LIBRARY = $(TILDE_LIBDIR)/libtilde.a
TILDE_LDFLAGS = -L$(TILDE_LIBDIR)
TILDE_DEP = $(TILDE_LIBRARY)

TILDE_SOURCE	= $(TILDE_LIBSRC)/tilde.c $(TILDE_LIBSRC)/tilde.h
TILDE_OBJ	= $(TILDE_LIBDIR)/tilde.o

# libintl
INTL_LIBSRC = $(LIBSRC)/intl
INTL_LIBDIR = ./$(LIBSUBDIR)/intl
INTL_ABSSRC = ${topdir}/$(INTL_LIB)
INTL_BUILDDIR = ${LIBBUILD}/intl

INTL_LIB     = 
INTL_LIBRARY = $(INTL_LIBDIR)/libintl.a
INTL_DEP = 
INTL_INC = 

LIBINTL_H = 

# libiconv
LIBICONV = 

# tests
LIBINTL = 
LTLIBINTL = 
INTLLIBS = 
INTLOBJS = 

# Our malloc.
MALLOC_TARGET = malloc

# set to alloca.o if we are using the C alloca in lib/malloc
ALLOCA = 

ALLOC_LIBSRC = $(LIBSRC)/malloc
ALLOC_LIBDIR = ./$(LIBSUBDIR)/malloc
ALLOC_ABSSRC = ${topdir}/$(ALLOC_LIBDIR)

MALLOC_SRC = malloc.c
MALLOC_OTHERSRC = ${ALLOC_LIBSRC}/trace.c ${ALLOC_LIBSRC}/stats.c \
		  ${ALLOC_LIBSRC}/table.c ${ALLOC_LIBSRC}/watch.c
MALLOC_SOURCE = ${ALLOC_LIBSRC}/${MALLOC_SRC} ${MALLOC_OTHERSRC}
MALLOC_CFLAGS = -DRCHECK -Dbotch=programming_error ${MALLOC_DEBUG}

MALLOC_LIB     = -lmalloc
MALLOC_LIBRARY = $(ALLOC_LIBDIR)/libmalloc.a
MALLOC_LDFLAGS = -L$(ALLOC_LIBDIR)
MALLOC_DEP = $(MALLOC_LIBRARY)

ALLOC_HEADERS = $(ALLOC_LIBSRC)/getpagesize.h $(ALLOC_LIBSRC)/shmalloc.h \
		$(ALLOC_LIBSRC)/imalloc.h $(ALLOC_LIBSRC)/mstats.h \
		$(ALLOC_LIBSRC)/table.h $(ALLOC_LIBSRC)/watch.h

$(MALLOC_LIBRARY):	${MALLOC_SOURCE} ${ALLOC_HEADERS} config.h
		@(cd $(ALLOC_LIBDIR) && \
		 $(MAKE) $(MFLAGS) \
		 MALLOC_CFLAGS="$(MALLOC_CFLAGS)" ${MALLOC_TARGET} ) || exit 1

BASHINCDIR = ${srcdir}/include
BASHINCFILES =	 $(BASHINCDIR)/posixstat.h $(BASHINCDIR)/ansi_stdlib.h \
		 $(BASHINCDIR)/filecntl.h $(BASHINCDIR)/posixdir.h \
		 $(BASHINCDIR)/memalloc.h $(BASHINCDIR)/stdc.h \
		 $(BASHINCDIR)/posixjmp.h $(BASHINCDIR)/posixwait.h \
		 $(BASHINCDIR)/posixtime.h $(BASHINCDIR)/systimes.h \
		 $(BASHINCDIR)/unionwait.h $(BASHINCDIR)/maxpath.h \
		 $(BASHINCDIR)/shtty.h $(BASHINCDIR)/typemax.h \
		 $(BASHINCDIR)/ocache.h

LIBRARIES = $(GLOB_LIB) $(SHLIB_LIB) $(READLINE_LIB) $(HISTORY_LIB) $(TERMCAP_LIB) \
	    $(TILDE_LIB) $(MALLOC_LIB) $(INTL_LIB) $(LIBICONV) $(LOCAL_LIBS)

LIBDEP = $(GLOB_DEP) $(SHLIB_DEP) $(INTL_DEP) $(READLINE_DEP) $(HISTORY_DEP) $(TERMCAP_DEP) \
	 $(TILDE_DEP) $(MALLOC_DEP)

LIBRARY_LDFLAGS = $(READLINE_LDFLAGS) $(HISTORY_LDFLAGS) $(GLOB_LDFLAGS) \
		  $(TILDE_LDFLAGS) $(MALLOC_LDFLAGS) $(SHLIB_LDFLAGS)

#
# The shell itself
#

# The main source code for the Bourne Again SHell.
CSOURCES = shell.c eval.c parse.y general.c make_cmd.c print_cmd.c y.tab.c \
	dispose_cmd.c execute_cmd.c variables.c version.c \
	expr.c copy_cmd.c flags.c subst.c hashcmd.c hashlib.c mailcheck.c \
	test.c trap.c alias.c jobs.c nojobs.c braces.c \
	input.c bashhist.c array.c arrayfunc.c assoc.c sig.c pathexp.c \
	unwind_prot.c siglist.c bashline.c bracecomp.c error.c \
	list.c stringlib.c locale.c findcmd.c redir.c \
	pcomplete.c pcomplib.c syntax.c xmalloc.c

HSOURCES = shell.h flags.h trap.h hashcmd.h hashlib.h jobs.h builtins.h \
	general.h variables.h config.h $(ALLOC_HEADERS) alias.h \
	quit.h unwind_prot.h syntax.h ${GRAM_H} \
	command.h input.h error.h bashansi.h dispose_cmd.h make_cmd.h \
	subst.h externs.h siglist.h bashhist.h bashline.h bashtypes.h \
	array.h arrayfunc.h sig.h mailcheck.h bashintl.h bashjmp.h \
	execute_cmd.h parser.h pathexp.h pathnames.h pcomplete.h assoc.h \
	$(BASHINCFILES)

SOURCES = $(CSOURCES) $(HSOURCES) $(BUILTIN_DEFS)

# headers in top-level source directory that get installed by install-headers
INSTALLED_HEADERS = shell.h bashjmp.h command.h syntax.h general.h error.h \
		    variables.h array.h assoc.h arrayfunc.h quit.h dispose_cmd.h \
		    make_cmd.h subst.h sig.h externs.h builtins.h \
		    bashtypes.h xmalloc.h config-top.h config-bot.h \
		    bashintl.h bashansi.h bashjmp.h alias.h hashlib.h \
		    conftypes.h unwind_prot.h jobs.h siglist.h
INSTALLED_BUILTINS_HEADERS = bashgetopt.h common.h getopt.h
INSTALLED_INCFILES =	 posixstat.h ansi_stdlib.h filecntl.h posixdir.h \
	memalloc.h stdc.h posixjmp.h posixwait.h posixtime.h systimes.h \
	unionwait.h maxpath.h shtty.h typemax.h ocache.h chartypes.h gettext.h \
	posixstat.h shmbchar.h shmbutil.h stat-time.h

SIGNAMES_H = lsignames.h

JOBS_O = jobs.o
SIGLIST_O = 
SIGNAMES_O = 

# Matching object files.
OBJECTS	 = shell.o eval.o y.tab.o general.o make_cmd.o print_cmd.o $(GLOBO) \
	   dispose_cmd.o execute_cmd.o variables.o copy_cmd.o error.o \
	   expr.o flags.o $(JOBS_O) subst.o hashcmd.o hashlib.o mailcheck.o \
	   trap.o input.o unwind_prot.o pathexp.o sig.o test.o version.o \
	   alias.o array.o arrayfunc.o assoc.o braces.o bracecomp.o bashhist.o \
	   bashline.o $(SIGLIST_O) list.o stringlib.o locale.o findcmd.o redir.o \
	   pcomplete.o pcomplib.o syntax.o xmalloc.o $(SIGNAMES_O)

# Where the source code of the shell builtins resides.
BUILTIN_SRCDIR=$(srcdir)/builtins
DEFSRC=$(BUILTIN_SRCDIR)
BUILTIN_ABSSRC=${topdir}/builtins
DEFDIR = ./builtins
DEBUGGER_DIR = ./debugger

BUILTIN_DEFS = $(DEFSRC)/alias.def $(DEFSRC)/bind.def $(DEFSRC)/break.def \
	       $(DEFSRC)/builtin.def $(DEFSRC)/cd.def $(DEFSRC)/colon.def \
	       $(DEFSRC)/command.def ${DEFSRC}/complete.def \
	       $(DEFSRC)/caller.def $(DEFSRC)/declare.def \
	       $(DEFSRC)/echo.def $(DEFSRC)/enable.def $(DEFSRC)/eval.def \
	       $(DEFSRC)/exec.def $(DEFSRC)/exit.def $(DEFSRC)/fc.def \
	       $(DEFSRC)/fg_bg.def $(DEFSRC)/hash.def $(DEFSRC)/help.def \
	       $(DEFSRC)/history.def $(DEFSRC)/jobs.def $(DEFSRC)/kill.def \
	       $(DEFSRC)/let.def $(DEFSRC)/read.def $(DEFSRC)/return.def \
	       $(DEFSRC)/set.def $(DEFSRC)/setattr.def $(DEFSRC)/shift.def \
	       $(DEFSRC)/source.def $(DEFSRC)/suspend.def $(DEFSRC)/test.def \
	       $(DEFSRC)/times.def $(DEFSRC)/trap.def $(DEFSRC)/type.def \
	       $(DEFSRC)/ulimit.def $(DEFSRC)/umask.def $(DEFSRC)/wait.def \
	       $(DEFSRC)/getopts.def $(DEFSRC)/reserved.def \
	       $(DEFSRC)/pushd.def $(DEFSRC)/shopt.def $(DEFSRC)/printf.def \
	       $(DEFSRC)/mapfile.def
BUILTIN_C_SRC  = $(DEFSRC)/mkbuiltins.c $(DEFSRC)/common.c \
		 $(DEFSRC)/evalstring.c $(DEFSRC)/evalfile.c \
		 $(DEFSRC)/bashgetopt.c $(GETOPT_SOURCE)
BUILTIN_C_OBJ  = $(DEFDIR)/common.o $(DEFDIR)/evalstring.o \
		 $(DEFDIR)/evalfile.o $(DEFDIR)/bashgetopt.o
BUILTIN_OBJS = $(DEFDIR)/alias.o $(DEFDIR)/bind.o $(DEFDIR)/break.o \
	       $(DEFDIR)/builtin.o $(DEFDIR)/cd.o $(DEFDIR)/colon.o \
	       $(DEFDIR)/command.o $(DEFDIR)/caller.o $(DEFDIR)/declare.o \
	       $(DEFDIR)/echo.o $(DEFDIR)/enable.o $(DEFDIR)/eval.o \
	       $(DEFDIR)/exec.o $(DEFDIR)/exit.o $(DEFDIR)/fc.o \
	       $(DEFDIR)/fg_bg.o $(DEFDIR)/hash.o $(DEFDIR)/help.o \
	       $(DEFDIR)/history.o $(DEFDIR)/jobs.o $(DEFDIR)/kill.o \
	       $(DEFDIR)/let.o $(DEFDIR)/pushd.o $(DEFDIR)/read.o \
	       $(DEFDIR)/return.o $(DEFDIR)/shopt.o $(DEFDIR)/printf.o \
	       $(DEFDIR)/set.o $(DEFDIR)/setattr.o $(DEFDIR)/shift.o \
	       $(DEFDIR)/source.o $(DEFDIR)/suspend.o $(DEFDIR)/test.o \
	       $(DEFDIR)/times.o $(DEFDIR)/trap.o $(DEFDIR)/type.o \
	       $(DEFDIR)/ulimit.o $(DEFDIR)/umask.o $(DEFDIR)/wait.o \
	       $(DEFDIR)/getopts.o $(DEFDIR)/mapfile.o $(BUILTIN_C_OBJ)
GETOPT_SOURCE   = $(DEFSRC)/getopt.c $(DEFSRC)/getopt.h
PSIZE_SOURCE	= $(DEFSRC)/psize.sh $(DEFSRC)/psize.c

BUILTINS_LIBRARY = $(DEFDIR)/libbuiltins.a
BUILTINS_LIB = -lbuiltins
BUILTINS_LDFLAGS = -L$(DEFDIR)
BUILTINS_DEP = $(BUILTINS_LIBRARY)

# Documentation for the shell.
DOCSRC = $(srcdir)/doc
DOCDIR = ./doc

# Translations and other i18n support files
PO_SRC = $(srcdir)/po/
PO_DIR = ./po/

SIGNAMES_SUPPORT = $(SUPPORT_SRC)mksignames.c

SUPPORT_SRC = $(srcdir)/support/
SDIR = ./support

TESTS_SUPPORT = recho zecho printenv xcase
CREATED_SUPPORT = signames.h recho zecho printenv \
		  tests/recho tests/zecho \
		  tests/printenv xcase tests/xcase \
		  mksignames lsignames.h \
		  mksyntax${EXEEXT} syntax.c $(VERSPROG) $(VERSOBJ) \
		  buildversion.o mksignames.o signames.o buildsignames.o
CREATED_MAKEFILES = Makefile builtins/Makefile doc/Makefile \
		    lib/readline/Makefile lib/glob/Makefile \
		    lib/sh/Makefile lib/tilde/Makefile lib/malloc/Makefile \
		    lib/termcap/Makefile examples/loadables/Makefile \
		    examples/loadables/Makefile.inc \
		    examples/loadables/perl/Makefile support/Makefile \
		    lib/intl/Makefile po/Makefile po/Makefile.in
CREATED_HEADERS = signames.h config.h pathnames.h version.h y.tab.h \
		  ${DEFDIR}/builtext.h

OTHER_DOCS = $(srcdir)/CHANGES $(srcdir)/COMPAT $(srcdir)/NEWS $(srcdir)/POSIX \
	$(srcdir)/RBASH $(srcdir)/README
OTHER_INSTALLED_DOCS = CHANGES COMPAT NEWS POSIX RBASH README

LOADABLES_DIR = ${top_builddir}/examples/loadables

# Keep GNU Make from exporting the entire environment for small machines.
.NOEXPORT:

.made: bash $(SDIR)/man2html
	@echo "bash last made for a $(Machine) running $(OS)" >.made

bash:  .build $(OBJECTS) $(BUILTINS_DEP) $(LIBDEP)
	rm -f $@
	$(PURIFY) $(CC) $(BUILTINS_LDFLAGS) $(LIBRARY_LDFLAGS) $(LDFLAGS) -o bash $(OBJECTS) $(LIBS)
	ls -l bash
	-$(SIZE) bash

.build:	$(SOURCES) config.h Makefile version.h $(VERSPROG)
	@echo
	@echo "	  ***********************************************************"
	@echo "	  *                                                         *"
	@echo "	  * `$(BUILD_DIR)/$(VERSPROG) -l`"
	@echo "	  *                                                         *"
	@echo "	  ***********************************************************"
	@echo

strip:	bash .made
	strip bash
	ls -l bash
	-$(SIZE) bash

lint:
	${MAKE} ${MFLAGS} CFLAGS='${GCC_LINT_FLAGS}' .made

version.h:  $(SOURCES) config.h Makefile patchlevel.h

bashversion:	patchlevel.h conftypes.h version.h buildversion.o $(SUPPORT_SRC)bashversion.c
	$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ $(SUPPORT_SRC)bashversion.c buildversion.o ${LIBS_FOR_BUILD}

buildversion.o: version.h conftypes.h patchlevel.h $(srcdir)/version.c
	$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) -DBUILDTOOL -c -o $@ $(srcdir)/version.c

# old rules
GRAM_H = parser-built
y.tab.o: y.tab.h y.tab.c ${GRAM_H} command.h ${BASHINCDIR}/stdc.h input.h
${GRAM_H}:	y.tab.h
	@-if test -f y.tab.h ; then \
		cmp -s $@ y.tab.h 2>/dev/null || cp -p y.tab.h $@; \
	fi

y.tab.c: parse.y
#	-if test -f y.tab.h; then mv -f y.tab.h old-y.tab.h; fi
	$(YACC) -d $(srcdir)/parse.y
	touch parser-built
#	-if cmp -s old-y.tab.h y.tab.h; then mv old-y.tab.h y.tab.h; else cp -p y.tab.h ${GRAM_H}; fi

y.tab.h: y.tab.c
	@true

 
# Subdirs will often times want version.h, so they'll change back up to
# the top level and try to create it.  This causes parallel build issues
# so just force top level sanity before we descend.
$(LIBDEP): .build
#$(LIBDEP): version.h

$(READLINE_LIBRARY): config.h $(READLINE_SOURCE)
	@echo making $@ in ${RL_LIBDIR}
	@( { test "${RL_LIBDIR}" = "${libdir}" && exit 0; } || \
		cd ${RL_LIBDIR} && $(MAKE) $(MFLAGS) DEBUG=${DEBUG} libreadline.a) || exit 1

$(HISTORY_LIBRARY): config.h $(HISTORY_SOURCE) $(READLINE_DEP)
	@echo making $@ in ${HIST_LIBDIR}
	@( { test "${HIST_LIBDIR}" = "${libdir}" && exit 0; } || \
		cd ${HIST_LIBDIR} && $(MAKE) $(MFLAGS) DEBUG=${DEBUG} libhistory.a) || exit 1

$(GLOB_LIBRARY): config.h $(GLOB_SOURCE)
	@echo making $@ in ${GLOB_LIBDIR}
	@(cd ${GLOB_LIBDIR} && \
		$(MAKE) $(MFLAGS) DEBUG=${DEBUG} libglob.a) || exit 1

$(TILDE_LIBRARY): config.h $(TILDE_SOURCE)
	@echo making $@ in ${TILDE_LIBDIR}
	@(cd ${TILDE_LIBDIR} && \
		$(MAKE) $(MFLAGS) libtilde.a) || exit 1

$(TERMCAP_LIBRARY): config.h ${TERMCAP_SOURCE}
	@echo making $@ in ${TERM_LIBDIR}	
	@(cd ${TERM_LIBDIR} && \
		$(MAKE) $(MFLAGS) libtermcap.a) || exit 1

$(SHLIB_LIBRARY): config.h ${SHLIB_SOURCE}
	@echo making $@ in ${SH_LIBDIR}
	@(cd ${SH_LIBDIR} && \
		$(MAKE) $(MFLAGS) DEBUG=${DEBUG} ${SHLIB_LIBNAME}) || exit 1

${INTL_LIBRARY}: config.h ${INTL_LIBDIR}/Makefile
	@echo making $@ in ${INTL_LIBDIR}
	@(cd ${INTL_LIBDIR} && \
		$(MAKE) $(MFLAGS) all) || exit 1

${LIBINTL_H}:	${INTL_DEP}

signames.o: $(SUPPORT_SRC)signames.c
	rm -f $@
	$(CC) $(CCFLAGS) -c $(SUPPORT_SRC)signames.c

buildsignames.o:	$(SUPPORT_SRC)signames.c
	rm -f $@
	$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) -DBUILDTOOL -o $@ -c $(SUPPORT_SRC)signames.c

mksignames.o:	$(SUPPORT_SRC)mksignames.c
	rm -f $@
	$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) -DBUILDTOOL -c $(SUPPORT_SRC)mksignames.c

mksignames:	mksignames.o buildsignames.o
	rm -f $@
	$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ mksignames.o buildsignames.o ${LIBS_FOR_BUILD}

mksyntax:	${srcdir}/mksyntax.c config.h syntax.h ${BASHINCDIR}/chartypes.h
	rm -f $@
	${CC_FOR_BUILD} ${CCFLAGS_FOR_BUILD} ${LDFLAGS_FOR_BUILD} -o $@ ${srcdir}/mksyntax.c ${LIBS_FOR_BUILD}

# make a list of signals for the local system -- this is done when we're
# *not* cross-compiling
lsignames.h:   mksignames
	rm -f $@
	./mksignames $@

# copy the correct signames header file to signames.h
signames.h: $(SIGNAMES_H)
	-if cmp -s $(SIGNAMES_H) $@ ; then :; else rm -f $@ ; $(CP) $(SIGNAMES_H) $@ ; fi

syntax.c:	mksyntax${EXEEXT} $(srcdir)/syntax.h 
	rm -f $@
	./mksyntax -o $@

$(BUILTINS_LIBRARY): $(BUILTIN_DEFS) $(BUILTIN_C_SRC) config.h ${BASHINCDIR}/memalloc.h $(DEFDIR)/builtext.h version.h
	@(cd $(DEFDIR) && $(MAKE) $(MFLAGS) DEBUG=${DEBUG} targets ) || exit 1

# these require special rules to circumvent make builtin rules
${DEFDIR}/common.o:	$(BUILTIN_SRCDIR)/common.c
	@(cd $(DEFDIR) && $(MAKE) $(MFLAGS) DEBUG=${DEBUG} common.o) || exit 1

${DEFDIR}/bashgetopt.o:	$(BUILTIN_SRCDIR)/bashgetopt.c
	@(cd $(DEFDIR) && $(MAKE) $(MFLAGS) DEBUG=${DEBUG} bashgetopt.o) || exit 1

${DEFDIR}/builtext.h: $(BUILTIN_DEFS)
	@(cd $(DEFDIR) && $(MAKE) $(MFLAGS) builtext.h ) || exit 1

$(SDIR)/man2html:	${SUPPORT_SRC}/man2html.c
	@(cd $(SDIR) && $(MAKE) $(MFLAGS) all ) || exit 1

# For the justification of the following Makefile rules, see node
# `Automatic Remaking' in GNU Autoconf documentation.

config.h:	stamp-h 

pathnames.h:		Makefile $(srcdir)/pathnames.h.in
	@sed -e 's|@DEBUGGER_START_FILE\@|${DEBUGGER_START_FILE}|g' $(srcdir)/pathnames.h.in > pathnames.tmp
	@if test -f $@; then \
		cmp -s pathnames.tmp $@ || mv pathnames.tmp $@; \
	else \
		mv pathnames.tmp $@; \
	fi
	@${RM} pathnames.tmp

loadables:
	cd $(LOADABLES_DIR) && $(MAKE) $(MFLAGS) all

#newversion:	mkversion
#	rm -f .build
#	./mkversion -dir $(srcdir) -dist
#	mv -f newversion.h version.h
#	$(MAKE) -f $(srcdir)/Makefile $(MFLAGS) srcdir=$(srcdir)

doc documentation:  force
	@(cd $(DOCDIR) ; $(MAKE) $(MFLAGS) )

info dvi ps: force
	@(cd $(DOCDIR) ; $(MAKE) $(MFLAGS) CFLAGS='$(CCFLAGS)' $@ )

force:

# unused
TAGS:	$(SOURCES) $(BUILTIN_C_SRC) $(LIBRARY_SOURCE)
	etags $(SOURCES) $(BUILTIN_C_SRC) $(LIBRARY_SOURCE)

tags:	$(SOURCES) $(BUILTIN_C_SRC) $(LIBRARY_SOURCE)
	ctags -x $(SOURCES) $(BUILTIN_C_SRC) $(LIBRARY_SOURCE) > $@

# Targets that actually do things not part of the build

installdirs:
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(bindir)
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(man1dir)
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(infodir)
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(docdir)
	-( cd $(PO_DIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )

install:	.made installdirs
	$(INSTALL_PROGRAM) $(INSTALLMODE) bash $(DESTDIR)$(bindir)/bash
	$(INSTALL_SCRIPT) $(INSTALLMODE2)
	$(INSTALL_DATA) $(OTHER_DOCS) $(DESTDIR)$(docdir)
	-( cd $(DOCDIR) ; $(MAKE) $(MFLAGS) \
		man1dir=$(man1dir) man1ext=$(man1ext) \
		man3dir=$(man3dir) man3ext=$(man3ext) \
		infodir=$(infodir) htmldir=$(htmldir) DESTDIR=$(DESTDIR) $@ )
	-( cd $(DEFDIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	-( cd $(PO_DIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	-( cd $(LOADABLES_DIR) && $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )

install-strip:
	$(MAKE) $(MFLAGS) INSTALL_PROGRAM='$(INSTALL_PROGRAM) -s' \
		prefix=${prefix} exec_prefix=${exec_prefix} \
		DESTDIR=$(DESTDIR) install

install-headers-dirs:
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(headersdir)
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(headersdir)/builtins
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(headersdir)/include
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(libdir)/pkgconfig

install-headers: install-headers-dirs
	@for hf in $(INSTALLED_HEADERS) ; do \
		${INSTALL_DATA} $(srcdir)/"$$hf" $(DESTDIR)$(headersdir)/$$hf; \
	done
	@for hf in $(INSTALLED_INCFILES) ; do \
		${INSTALL_DATA} $(BASHINCDIR)/"$$hf" $(DESTDIR)$(headersdir)/include/$$hf; \
	done
	@for hf in $(INSTALLED_BUILTINS_HEADERS) ; do \
		${INSTALL_DATA} $(BUILTIN_SRCDIR)/"$$hf" $(DESTDIR)$(headersdir)/builtins/$$hf; \
	done
	@for hf in $(CREATED_HEADERS) ; do \
		${INSTALL_DATA} $(BUILD_DIR)/"$$hf" $(DESTDIR)$(headersdir)/$$hf; \
	done
	$(INSTALL_DATA) $(SDIR)/bash.pc $(DESTDIR)$(libdir)/pkgconfig/bash.pc

uninstall-headers:
	-( cd $(DESTDIR)$(headersdir) && rm -f $(INSTALLED_HEADERS) )
	-( cd $(DESTDIR)$(headersdir)/include && rm -f $(INSTALLED_INCFILES) )
	-( cd $(DESTDIR)$(headersdir)/builtins && rm -f $(INSTALLED_BUILTINS_HEADERS) )
	-( cd $(DESTDIR)$(headersdir) && rm -f $(CREATED_HEADERS) )
	-( rm -f $(DESTDIR)$(libdir)/pkgconfig/bash.pc )

uninstall:	.made
	rm -f $(DESTDIR)$(bindir)/bash
	-( cd $(DESTDIR)$(docdir) && ${RM} ${OTHER_INSTALLED_DOCS} )
	-( cd $(DOCDIR) ; $(MAKE) $(MFLAGS) \
		man1dir=$(man1dir) man1ext=$(man1ext) \
		man3dir=$(man3dir) man3ext=$(man3ext) \
		infodir=$(infodir) htmldir=$(htmldir) DESTDIR=$(DESTDIR) $@ )
	-( cd $(PO_DIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	-( cd $(LOADABLES_DIR) && $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )

.PHONY: clean

LIB_SUBDIRS = ${RL_LIBDIR}  ${HIST_LIBDIR} ${TERM_LIBDIR} ${GLOB_LIBDIR} \
		${INTL_LIBDIR} ${TILDE_LIBDIR} ${ALLOC_LIBDIR} ${SH_LIBDIR}

clean:
	rm -f $(OBJECTS) bash

recho:		$(SUPPORT_SRC)recho.c
	@$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ $(SUPPORT_SRC)recho.c ${LIBS_FOR_BUILD}

zecho:		$(SUPPORT_SRC)zecho.c
	@$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ $(SUPPORT_SRC)zecho.c ${LIBS_FOR_BUILD}

printenv:	$(SUPPORT_SRC)printenv.c
	@$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ $(SUPPORT_SRC)printenv.c ${LIBS_FOR_BUILD}

xcase:	$(SUPPORT_SRC)xcase.c
	@$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ $(SUPPORT_SRC)xcase.c ${LIBS_FOR_BUILD}

test tests check:	force bash $(TESTS_SUPPORT)
	@-test -d tests || mkdir tests
	@cp $(TESTS_SUPPORT) tests
	@( cd $(srcdir)/tests && \
		PATH=$(BUILD_DIR)/tests:$$PATH THIS_SH=$(THIS_SH) $(SHELL) ${TESTSCRIPT} )

symlinks:
	$(SHELL) $(SUPPORT_SRC)fixlinks -s $(srcdir)

dist:	force
	@echo Bash distributions are created using $(srcdir)/support/mkdist.
	@echo Here is a sample of the necessary commands:
	@echo bash $(srcdir)/support/mkdist -m $(srcdir)/MANIFEST -s $(srcdir) -r ${PACKAGE} -t $(PACKAGE_VERSION)

xdist:	force
	( cd $(DOCDIR) && $(MAKE) $(MFLAGS) $@ )
	( cd po && $(MAKE) $(MFLAGS) $@ )

depend:	depends

depends: force
	bash $(SUPPORT_SRC)mkdep -c ${CC} -- ${CCFLAGS} ${CSOURCES}

#### PRIVATE TARGETS ####
hashtest:	hashlib.c
	$(CC) -DTEST_HASHING $(CCFLAGS) $(TEST_NBUCKETS) -o $@ $(srcdir)/hashlib.c xmalloc.o $(INTL_LIB)

############################ DEPENDENCIES ###############################

# Files that depend on the definitions in config-top.h, which are not meant
# to be changed
bashhist.o: config-top.h
shell.o: config-top.h
input.o: config-top.h
y.tab.o: config-top.h
jobs.o: config-top.h
nojobs.o: config-top.h
execute_cmd.o: config-top.h
variables.o: config-top.h
builtins/command.o: config-top.h
builtins/common.o: config-top.h
builtins/break.o: config-top.h
builtins/echo.o: config-top.h
builtins/evalstring.o: config-top.h
builtins/exit.o: config-top.h
builtins/kill.o: config-top.h

# shell basics
copy_cmd.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
copy_cmd.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
copy_cmd.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
copy_cmd.o: make_cmd.h subst.h sig.h pathnames.h externs.h
dispose_cmd.o: bashansi.h ${BASHINCDIR}/ansi_stdlib.h
dispose_cmd.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h
dispose_cmd.o: error.h general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
dispose_cmd.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
dispose_cmd.o: make_cmd.h subst.h sig.h pathnames.h externs.h
dispose_cmd.o: ${BASHINCDIR}/ocache.h
error.o: config.h bashtypes.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h flags.h ${BASHINCDIR}/stdc.h error.h
error.o: command.h general.h xmalloc.h externs.h input.h bashhist.h
error.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
error.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
error.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
error.o: make_cmd.h subst.h sig.h pathnames.h externs.h
error.o: input.h execute_cmd.h 
eval.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h trap.h flags.h ${DEFSRC}/common.h
eval.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
eval.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
eval.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
eval.o: make_cmd.h subst.h sig.h pathnames.h externs.h
eval.o: input.h execute_cmd.h 
execute_cmd.o: config.h bashtypes.h ${BASHINCDIR}/filecntl.h ${BASHINCDIR}/posixstat.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
execute_cmd.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
execute_cmd.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
execute_cmd.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
execute_cmd.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
execute_cmd.o: ${BASHINCDIR}/memalloc.h ${GRAM_H} flags.h builtins.h jobs.h quit.h siglist.h
execute_cmd.o: execute_cmd.h findcmd.h redir.h trap.h test.h pathexp.h
execute_cmd.o: $(DEFSRC)/common.h ${DEFDIR}/builtext.h ${GLOB_LIBSRC}/strmatch.h
execute_cmd.o: ${BASHINCDIR}/posixtime.h ${BASHINCDIR}/chartypes.h
execute_cmd.o: $(DEFSRC)/getopt.h
expr.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h 
expr.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
expr.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
expr.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
expr.o: make_cmd.h subst.h sig.h pathnames.h externs.h
expr.o: ${BASHINCDIR}/chartypes.h
findcmd.o: config.h bashtypes.h ${BASHINCDIR}/filecntl.h ${BASHINCDIR}/posixstat.h bashansi.h
findcmd.o: ${BASHINCDIR}/ansi_stdlib.h ${BASHINCDIR}/memalloc.h shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h
findcmd.o: ${BASHINCDIR}/stdc.h error.h general.h xmalloc.h variables.h arrayfunc.h conftypes.h quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h
findcmd.o: dispose_cmd.h make_cmd.h subst.h sig.h pathnames.h externs.h
findcmd.o: flags.h hashlib.h pathexp.h hashcmd.h 
findcmd.o: ${BASHINCDIR}/chartypes.h
flags.o: config.h flags.h 
flags.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
flags.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
flags.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
flags.o: make_cmd.h subst.h sig.h pathnames.h externs.h bashhist.h
general.o: config.h bashtypes.h ${BASHINCDIR}/posixstat.h ${BASHINCDIR}/filecntl.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
general.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
general.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
general.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
general.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
general.o: ${BASHINCDIR}/maxpath.h ${BASHINCDIR}/posixtime.h
general.o: ${BASHINCDIR}/chartypes.h
hashcmd.o: config.h ${BASHINCDIR}/posixstat.h bashtypes.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
hashcmd.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
hashcmd.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashcmd.h
hashcmd.o: execute_cmd.h findcmd.h ${BASHINCDIR}/stdc.h pathnames.h hashlib.h
hashcmd.o: quit.h sig.h
hashlib.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
hashlib.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
hashlib.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
hashlib.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
hashlib.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
input.o: config.h bashtypes.h ${BASHINCDIR}/filecntl.h ${BASHINCDIR}/posixstat.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
input.o: command.h ${BASHINCDIR}/stdc.h general.h xmalloc.h input.h error.h externs.h
input.o: quit.h
list.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
list.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
list.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
list.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
locale.o: config.h bashtypes.h bashintl.h ${LIBINTL_H} bashansi.h ${BASHINCDIR}/ansi_stdlib.h
locale.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
locale.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
locale.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
locale.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
locale.o: ${BASHINCDIR}/chartypes.h
mailcheck.o: config.h bashtypes.h ${BASHINCDIR}/posixstat.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
mailcheck.o: ${BASHINCDIR}/posixtime.h
mailcheck.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
mailcheck.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
mailcheck.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
mailcheck.o: make_cmd.h subst.h sig.h pathnames.h externs.h
mailcheck.o: execute_cmd.h mailcheck.h 
make_cmd.o: config.h bashtypes.h ${BASHINCDIR}/filecntl.h bashansi.h
make_cmd.o: command.h ${BASHINCDIR}/stdc.h general.h xmalloc.h error.h flags.h make_cmd.h
make_cmd.o: variables.h arrayfunc.h conftypes.h array.h hashlib.h subst.h input.h externs.h
make_cmd.o: jobs.h quit.h sig.h siglist.h syntax.h dispose_cmd.h parser.h
make_cmd.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h ${BASHINCDIR}/ocache.h
y.tab.o: config.h bashtypes.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h ${BASHINCDIR}/memalloc.h
y.tab.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
y.tab.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
y.tab.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
y.tab.o: make_cmd.h subst.h sig.h pathnames.h externs.h test.h
y.tab.o: trap.h flags.h parser.h input.h mailcheck.h $(DEFSRC)/common.h
y.tab.o: $(DEFDIR)/builtext.h bashline.h bashhist.h jobs.h siglist.h alias.h
pathexp.o: config.h bashtypes.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
pathexp.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
pathexp.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
pathexp.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
pathexp.o: make_cmd.h subst.h sig.h pathnames.h externs.h
pathexp.o: pathexp.h flags.h 
pathexp.o: $(GLOB_LIBSRC)/glob.h $(GLOB_LIBSRC)/strmatch.h
pathexp.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h
print_cmd.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
print_cmd.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
print_cmd.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
print_cmd.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
print_cmd.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
print_cmd.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h
print_cmd.o: ${GRAM_H} $(DEFSRC)/common.h
redir.o: config.h bashtypes.h ${BASHINCDIR}/posixstat.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h ${BASHINCDIR}/filecntl.h
redir.o: ${BASHINCDIR}/memalloc.h shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
redir.o: general.h xmalloc.h variables.h arrayfunc.h conftypes.h array.h hashlib.h quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h
redir.o: dispose_cmd.h make_cmd.h subst.h sig.h pathnames.h externs.h 
redir.o: flags.h execute_cmd.h redir.h input.h
shell.o: config.h bashtypes.h ${BASHINCDIR}/posixstat.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h ${BASHINCDIR}/filecntl.h
shell.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
shell.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
shell.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
shell.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
shell.o: flags.h trap.h mailcheck.h builtins.h $(DEFSRC)/common.h
shell.o: jobs.h siglist.h input.h execute_cmd.h findcmd.h bashhist.h bashline.h
shell.o: ${GLOB_LIBSRC}/strmatch.h ${BASHINCDIR}/posixtime.h
sig.o: config.h bashtypes.h
sig.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
sig.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
sig.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
sig.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
sig.o: jobs.h siglist.h trap.h $(DEFSRC)/common.h bashline.h bashhist.h
sig.o: ${DEFDIR}/builtext.h
siglist.o: config.h bashtypes.h siglist.h trap.h 
stringlib.o: bashtypes.h ${BASHINCDIR}/chartypes.h
stringlib.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
stringlib.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
stringlib.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
stringlib.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
stringlib.o: ${GLOB_LIBSRC}/glob.h ${GLOB_LIBSRC}/strmatch.h
subst.o: config.h bashtypes.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h ${BASHINCDIR}/posixstat.h
subst.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
subst.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
subst.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
subst.o: make_cmd.h subst.h sig.h pathnames.h externs.h parser.h
subst.o: flags.h jobs.h siglist.h execute_cmd.h ${BASHINCDIR}/filecntl.h trap.h pathexp.h
subst.o: mailcheck.h input.h $(DEFSRC)/getopt.h $(DEFSRC)/common.h
subst.o: bashline.h bashhist.h ${GLOB_LIBSRC}/strmatch.h
subst.o: ${BASHINCDIR}/chartypes.h
subst.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h
subst.o: ${DEFDIR}/builtext.h
test.o: bashtypes.h ${BASHINCDIR}/posixstat.h ${BASHINCDIR}/filecntl.h
test.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
test.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
test.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
test.o: make_cmd.h subst.h sig.h pathnames.h externs.h test.h
test.o: ${DEFSRC}/common.h 
trap.o: config.h bashtypes.h trap.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
trap.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
trap.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
trap.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
trap.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
trap.o: signames.h $(DEFSRC)/common.h
trap.o: ${DEFDIR}/builtext.h jobs.h
unwind_prot.o: config.h bashtypes.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h command.h ${BASHINCDIR}/stdc.h
unwind_prot.o: general.h xmalloc.h unwind_prot.h quit.h sig.h
variables.o: config.h bashtypes.h ${BASHINCDIR}/posixstat.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
variables.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
variables.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
variables.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
variables.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
variables.o: flags.h execute_cmd.h mailcheck.h input.h $(DEFSRC)/common.h
variables.o: findcmd.h bashhist.h hashcmd.h pathexp.h
variables.o: pcomplete.h  ${BASHINCDIR}/chartypes.h
variables.o: ${BASHINCDIR}/posixtime.h assoc.h
variables.o: version.h $(DEFDIR)/builtext.h
version.o:  conftypes.h patchlevel.h version.h
xmalloc.o: config.h bashtypes.h ${BASHINCDIR}/ansi_stdlib.h error.h

# job control

jobs.o: config.h bashtypes.h trap.h ${BASHINCDIR}/filecntl.h input.h ${BASHINCDIR}/shtty.h
jobs.o: bashansi.h ${BASHINCDIR}/ansi_stdlib.h
jobs.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
jobs.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
jobs.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
jobs.o: execute_cmd.h make_cmd.h subst.h sig.h pathnames.h externs.h 
jobs.o: jobs.h flags.h $(DEFSRC)/common.h $(DEFDIR)/builtext.h
jobs.o: ${BASHINCDIR}/posixwait.h ${BASHINCDIR}/unionwait.h
jobs.o: ${BASHINCDIR}/posixtime.h
nojobs.o: config.h bashtypes.h ${BASHINCDIR}/filecntl.h bashjmp.h ${BASHINCDIR}/posixjmp.h
nojobs.o: command.h ${BASHINCDIR}/stdc.h general.h xmalloc.h jobs.h quit.h siglist.h externs.h
nojobs.o: sig.h error.h ${BASHINCDIR}/shtty.h input.h
nojobs.o: $(DEFDIR)/builtext.h

# shell features that may be compiled in

array.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
array.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
array.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
array.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
array.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
array.o: $(DEFSRC)/common.h
arrayfunc.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
arrayfunc.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
arrayfunc.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
arrayfunc.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
arrayfunc.o: make_cmd.h subst.h sig.h pathnames.h externs.h pathexp.h
arrayfunc.o: $(DEFSRC)/common.h
arrayfunc.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h
assoc.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
assoc.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h
assoc.o: command.h ${BASHINCDIR}/stdc.h error.h
assoc.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h
assoc.o: assoc.h hashlib.h
assoc.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
assoc.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
assoc.o: $(DEFSRC)/common.h
braces.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
braces.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
braces.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
braces.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
braces.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
braces.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h
alias.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h command.h ${BASHINCDIR}/stdc.h
alias.o: general.h xmalloc.h bashtypes.h externs.h alias.h
alias.o: pcomplete.h 
alias.o: ${BASHINCDIR}/chartypes.h

pcomplib.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h bashtypes.h
pcomplib.o: ${BASHINCDIR}/stdc.h hashlib.h pcomplete.h shell.h syntax.h
pcomplib.o: bashjmp.h command.h general.h xmalloc.h error.h variables.h arrayfunc.h conftypes.h quit.h
pcomplib.o: unwind_prot.h dispose_cmd.h make_cmd.h subst.h sig.h pathnames.h
pcomplib.o: externs.h ${BASHINCDIR}/maxpath.h

pcomplete.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h bashtypes.h
pcomplete.o: ${BASHINCDIR}/stdc.h hashlib.h pcomplete.h shell.h syntax.h
pcomplete.o: bashjmp.h command.h general.h xmalloc.h error.h variables.h arrayfunc.h conftypes.h quit.h
pcomplete.o: unwind_prot.h dispose_cmd.h make_cmd.h subst.h sig.h pathnames.h
pcomplete.o: externs.h ${BASHINCDIR}/maxpath.h execute_cmd.h 
pcomplete.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h
pcomplete.o: ${DEFDIR}/builtext.h

# library support files

bashhist.o: config.h bashtypes.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h ${BASHINCDIR}/posixstat.h
bashhist.o: ${BASHINCDIR}/filecntl.h
bashhist.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
bashhist.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
bashhist.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
bashhist.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
bashhist.o: flags.h input.h parser.h pathexp.h $(DEFSRC)/common.h bashline.h
bashhist.o: $(GLOB_LIBSRC)/strmatch.h
bashline.o: config.h bashtypes.h ${BASHINCDIR}/posixstat.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
bashline.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h command.h ${BASHINCDIR}/stdc.h error.h
bashline.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h array.h hashlib.h
bashline.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
bashline.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
bashline.o: builtins.h bashhist.h bashline.h execute_cmd.h findcmd.h pathexp.h
bashline.o: $(DEFSRC)/common.h $(GLOB_LIBSRC)/glob.h alias.h
bashline.o: pcomplete.h ${BASHINCDIR}/chartypes.h input.h
bashline.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h
bracecomp.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
bracecomp.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h
bracecomp.o: command.h ${BASHINCDIR}/stdc.h error.h
bracecomp.o: general.h xmalloc.h bashtypes.h variables.h arrayfunc.h conftypes.h
bracecomp.o: array.h hashlib.h alias.h builtins.h 
bracecomp.o: quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
bracecomp.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
bracecomp.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h

# library dependencies

bashline.o: $(RL_LIBSRC)/rlconf.h
bashline.o: $(RL_LIBSRC)/keymaps.h $(RL_LIBSRC)/rlstdc.h
bashline.o: $(RL_LIBSRC)/chardefs.h $(RL_LIBSRC)/readline.h
bracecomp.o: $(RL_LIBSRC)/keymaps.h $(RL_LIBSRC)/chardefs.h
bracecomp.o: $(RL_LIBSRC)/readline.h $(RL_LIBSRC)/rlstdc.h
y.tab.o: $(RL_LIBSRC)/keymaps.h $(RL_LIBSRC)/chardefs.h
y.tab.o: $(RL_LIBSRC)/readline.h $(RL_LIBSRC)/rlstdc.h
subst.o: $(RL_LIBSRC)/keymaps.h $(RL_LIBSRC)/chardefs.h
subst.o: $(RL_LIBSRC)/readline.h $(RL_LIBSRC)/rlstdc.h

shell.o: $(HIST_LIBSRC)/history.h $(HIST_LIBSRC)/rlstdc.h
subst.o: $(HIST_LIBSRC)/history.h $(HIST_LIBSRC)/rlstdc.h
bashline.o: $(HIST_LIBSRC)/history.h $(HIST_LIBSRC)/rlstdc.h
bashhist.o: $(HIST_LIBSRC)/history.h $(HIST_LIBSRC)/rlstdc.h
y.tab.o: $(HIST_LIBSRC)/history.h $(HIST_LIBSRC)/rlstdc.h

execute_cmd.o: $(TILDE_LIBSRC)/tilde.h
general.o: $(TILDE_LIBSRC)/tilde.h
mailcheck.o: $(TILDE_LIBSRC)/tilde.h
shell.o: $(TILDE_LIBSRC)/tilde.h
subst.o: $(TILDE_LIBSRC)/tilde.h
variables.o: $(TILDE_LIBSRC)/tilde.h

# libintl dependencies
arrayfunc.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
bashhist.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
bashline.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
braces.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
error.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
eval.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
execute_cmd.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
expr.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
general.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
input.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
jobs.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
mailcheck.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
make_cmd.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
nojobs.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
y.tab.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
pcomplete.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
pcomplib.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
print_cmd.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
redir.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
shell.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
sig.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
siglist.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
subst.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
test.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
trap.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
variables.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
version.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
xmalloc.o: bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h

signames.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h

# XXX - dependencies checked through here

# builtin c sources
builtins/bashgetopt.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
builtins/bashgetopt.o: shell.h syntax.h config.h bashjmp.h command.h general.h xmalloc.h error.h
builtins/bashgetopt.o: variables.h arrayfunc.h conftypes.h quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
builtins/bashgetopt.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
builtins/bashgetopt.o: $(DEFSRC)/common.h
builtins/bashgetopt.o: ${BASHINCDIR}/chartypes.h
builtins/common.o: bashtypes.h ${BASHINCDIR}/posixstat.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
builtins/common.o: shell.h syntax.h config.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h command.h
builtins/common.o: ${BASHINCDIR}/memalloc.h variables.h arrayfunc.h conftypes.h input.h siglist.h
builtins/common.o: quit.h unwind_prot.h ${BASHINCDIR}/maxpath.h jobs.h builtins.h
builtins/common.o: dispose_cmd.h make_cmd.h subst.h externs.h bashhist.h 
builtins/common.o: execute_cmd.h ${BASHINCDIR}/stdc.h general.h xmalloc.h error.h pathnames.h
builtins/common.o: ${DEFDIR}/builtext.h
builtins/common.o: ${BASHINCDIR}/chartypes.h
builtins/evalfile.o: bashtypes.h ${BASHINCDIR}/posixstat.h ${BASHINCDIR}/filecntl.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
builtins/evalfile.o: shell.h syntax.h config.h bashjmp.h command.h general.h xmalloc.h error.h
builtins/evalfile.o: variables.h arrayfunc.h conftypes.h quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
builtins/evalfile.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
builtins/evalfile.o: jobs.h builtins.h flags.h input.h execute_cmd.h
builtins/evalfile.o: bashhist.h $(DEFSRC)/common.h
builtins/evalstring.o: config.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
builtins/evalstring.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h command.h siglist.h
builtins/evalstring.o: ${BASHINCDIR}/memalloc.h variables.h arrayfunc.h conftypes.h input.h
builtins/evalstring.o: quit.h unwind_prot.h ${BASHINCDIR}/maxpath.h jobs.h builtins.h
builtins/evalstring.o: dispose_cmd.h make_cmd.h subst.h externs.h 
builtins/evalstring.o: jobs.h builtins.h flags.h input.h execute_cmd.h
builtins/evalstring.o: bashhist.h $(DEFSRC)/common.h pathnames.h
builtins/getopt.o: config.h ${BASHINCDIR}/memalloc.h
builtins/getopt.o: shell.h syntax.h bashjmp.h command.h general.h xmalloc.h error.h
builtins/getopt.o: variables.h arrayfunc.h conftypes.h quit.h ${BASHINCDIR}/maxpath.h unwind_prot.h dispose_cmd.h
builtins/getopt.o: make_cmd.h subst.h sig.h pathnames.h externs.h 
builtins/getopt.o: $(DEFSRC)/getopt.h
builtins/mkbuiltins.o: config.h bashtypes.h ${BASHINCDIR}/posixstat.h ${BASHINCDIR}/filecntl.h
builtins/mkbuiltins.o: bashansi.h ${BASHINCDIR}/ansi_stdlib.h

# builtin def files
builtins/alias.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/alias.o: quit.h $(DEFSRC)/common.h pathnames.h
builtins/alias.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h command.h ${BASHINCDIR}/stdc.h unwind_prot.h
builtins/alias.o: dispose_cmd.h make_cmd.h subst.h externs.h variables.h arrayfunc.h conftypes.h 
builtins/bind.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/bind.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/bind.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h
builtins/bind.o: $(DEFSRC)/bashgetopt.h pathnames.h
builtins/break.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/break.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h
builtins/break.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/break.o: pathnames.h
builtins/builtin.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/builtin.o: quit.h $(DEFSRC)/common.h $(DEFSRC)/bashgetopt.h
builtins/builtin.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/builtin.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/builtin.o: pathnames.h
builtins/caller.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/caller.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h
builtins/caller.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/caller.o: $(DEFSRC)/common.h quit.h 
builtins/caller.o: ${BASHINCDIR}/chartypes.h bashtypes.h
builtins/caller.o: ${DEFDIR}/builtext.h pathnames.h
builtins/cd.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/cd.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h
builtins/cd.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/cd.o: $(DEFSRC)/common.h quit.h pathnames.h
builtins/command.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/command.o: quit.h $(DEFSRC)/bashgetopt.h
builtins/command.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/command.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h pathnames.h
builtins/declare.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/declare.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h
builtins/declare.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/declare.o: $(DEFSRC)/bashgetopt.h pathnames.h flags.h
builtins/echo.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/echo.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h
builtins/echo.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/echo.o: pathnames.h
builtins/enable.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/enable.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h
builtins/enable.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/enable.o: pcomplete.h pathnames.h
builtins/eval.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/eval.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h 
builtins/eval.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/eval.o: pathnames.h
builtins/exec.o: bashtypes.h pathnames.h
builtins/exec.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/exec.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h
builtins/exec.o: dispose_cmd.h make_cmd.h subst.h externs.h execute_cmd.h 
builtins/exec.o: findcmd.h flags.h quit.h $(DEFSRC)/common.h ${BASHINCDIR}/stdc.h
builtins/exec.o: pathnames.h
builtins/exit.o: bashtypes.h 
builtins/exit.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/exit.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h
builtins/exit.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/exit.o: pathnames.h
builtins/fc.o: bashtypes.h ${BASHINCDIR}/posixstat.h
builtins/fc.o: bashansi.h ${BASHINCDIR}/ansi_stdlib.h builtins.h command.h ${BASHINCDIR}/stdc.h 
builtins/fc.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/fc.o: flags.h unwind_prot.h variables.h arrayfunc.h conftypes.h shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h 
builtins/fc.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h quit.h 
builtins/fc.o: $(DEFSRC)/bashgetopt.h bashhist.h pathnames.h
builtins/fc.o: ${BASHINCDIR}/chartypes.h
builtins/fg_bg.o: bashtypes.h $(DEFSRC)/bashgetopt.h 
builtins/fg_bg.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/fg_bg.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h
builtins/fg_bg.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/fg_bg.o: pathnames.h
builtins/getopts.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/getopts.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h 
builtins/getopts.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/getopts.o: pathnames.h
builtins/hash.o: bashtypes.h 
builtins/hash.o: builtins.h command.h findcmd.h ${BASHINCDIR}/stdc.h $(DEFSRC)/common.h
builtins/hash.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/hash.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h 
builtins/hash.o: pathnames.h
builtins/help.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/help.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/help.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h
builtins/help.o: $(GLOB_LIBSRC)/glob.h pathnames.h
builtins/history.o: bashtypes.h pathnames.h
builtins/history.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/history.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/history.o: ${BASHINCDIR}/filecntl.h shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h
builtins/history.o: bashhist.h variables.h arrayfunc.h conftypes.h 
builtins/inlib.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/inlib.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h quit.h 
builtins/inlib.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/inlib.o: pathnames.h
builtins/jobs.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/jobs.o: quit.h $(DEFSRC)/bashgetopt.h
builtins/jobs.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/jobs.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/jobs.o: pathnames.h
builtins/kill.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/kill.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/kill.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h trap.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/kill.o: pathnames.h
builtins/let.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/let.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/let.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/let.o: pathnames.h
builtins/printf.o: config.h ${BASHINCDIR}/memalloc.h bashjmp.h command.h error.h
builtins/printf.o: general.h xmalloc.h quit.h dispose_cmd.h make_cmd.h subst.h
builtins/printf.o: externs.h sig.h pathnames.h shell.h syntax.h unwind_prot.h
builtins/printf.o: variables.h arrayfunc.h conftypes.h ${BASHINCDIR}/stdc.h $(DEFSRC)/bashgetopt.h
builtins/printf.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h
builtins/printf.o: ${BASHINCDIR}/chartypes.h 
builtins/pushd.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/pushd.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/pushd.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h
builtins/pushd.o: $(DEFSRC)/common.h pathnames.h
builtins/read.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/read.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/read.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/read.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h
builtins/read.o: pathnames.h
builtins/return.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/return.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/return.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/return.o: pathnames.h
builtins/set.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/set.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/set.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h flags.h
builtins/set.o: pathnames.h
builtins/setattr.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/setattr.o: quit.h $(DEFSRC)/common.h $(DEFSRC)/bashgetopt.h
builtins/setattr.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/setattr.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/setattr.o: pathnames.h flags.h
builtins/shift.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/shift.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/shift.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/shift.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/shift.o: pathnames.h
builtins/shopt.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h
builtins/shopt.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h
builtins/shopt.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h unwind_prot.h variables.h arrayfunc.h conftypes.h ${BASHINCDIR}/maxpath.h
builtins/shopt.o: $(DEFSRC)/common.h $(DEFSRC)/bashgetopt.h pathnames.h
builtins/shopt.o: bashhist.h bashline.h
builtins/source.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/source.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/source.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h
builtins/source.o: findcmd.h $(DEFSRC)/bashgetopt.h flags.h trap.h
builtins/source.o: pathnames.h
builtins/suspend.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/suspend.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/suspend.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/suspend.o: pathnames.h
builtins/test.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/test.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/test.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/test.o: test.h pathnames.h
builtins/times.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/times.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/times.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/times.o: pathnames.h
builtins/trap.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/trap.o: quit.h $(DEFSRC)/common.h
builtins/trap.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/trap.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/trap.o: pathnames.h
builtins/type.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/type.o: quit.h $(DEFSRC)/common.h findcmd.h
builtins/type.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h
builtins/type.o: dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/type.o: pathnames.h
builtins/ulimit.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/ulimit.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/ulimit.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/ulimit.o: pathnames.h
builtins/umask.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/umask.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/umask.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/umask.o: ${BASHINCDIR}/chartypes.h pathnames.h
builtins/wait.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/wait.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/wait.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h
builtins/wait.o: ${BASHINCDIR}/chartypes.h pathnames.h

builtins/complete.o: config.h shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h
builtins/complete.o: unwind_prot.h variables.h arrayfunc.h conftypes.h
builtins/complete.o: bashtypes.h bashansi.h ${BASHINCDIR}/ansi_stdlib.h
builtins/complete.o: builtins.h pathnames.h general.h
builtins/complete.o: bashtypes.h ${BASHINCDIR}/chartypes.h xmalloc.h
builtins/complete.o: pcomplete.h
builtins/complete.o: ${DEFSRC}/common.h ${DEFSRC}/bashgetopt.h
builtins/mapfile.o: command.h config.h ${BASHINCDIR}/memalloc.h error.h general.h xmalloc.h ${BASHINCDIR}/maxpath.h
builtins/mapfile.o: quit.h dispose_cmd.h make_cmd.h subst.h externs.h ${BASHINCDIR}/stdc.h
builtins/mapfile.o: shell.h syntax.h bashjmp.h ${BASHINCDIR}/posixjmp.h sig.h unwind_prot.h variables.h arrayfunc.h conftypes.h 
builtins/mapfile.o: pathnames.h

# libintl dependencies
builtins/bind.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/break.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/caller.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/cd.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/common.c: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/complete.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/declare.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/enable.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/evalfile.c: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/exec.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/exit.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/fc.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/fg_bg.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/getopt.c: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/hash.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/help.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/history.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/inlib.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/jobs.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/kill.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/let.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/mapfile.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/mkbuiltins.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/printf.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/pushd.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/read.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/return.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/set.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/setattr.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/shift.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/shopt.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/source.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/suspend.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/type.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/ulimit.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
builtins/umask.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h

# builtin library dependencies
builtins/bind.o: $(RL_LIBSRC)/chardefs.h $(RL_LIBSRC)/readline.h
builtins/bind.o: $(RL_LIBSRC)/keymaps.h $(RL_LIBSRC)/rlstdc.h

builtins/bind.o: $(HIST_LIBSRC)/history.h $(RL_LIBSRC)/rlstdc.h
builtins/fc.o: $(HIST_LIBSRC)/history.h $(RL_LIBSRC)/rlstdc.h
builtins/history.o: $(HIST_LIBSRC)/history.h $(RL_LIBSRC)/rlstdc.h

builtins/common.o: $(TILDE_LIBSRC)/tilde.h
builtins/cd.o: $(TILDE_LIBSRC)/tilde.h 

builtins/alias.o: $(DEFSRC)/alias.def
builtins/bind.o: $(DEFSRC)/bind.def
builtins/break.o: $(DEFSRC)/break.def
builtins/builtin.o: $(DEFSRC)/builtin.def
builtins/caller.o: $(DEFSRC)/caller.def
builtins/cd.o: $(DEFSRC)/cd.def
builtins/colon.o: $(DEFSRC)/colon.def
builtins/command.o: $(DEFSRC)/command.def
builtins/complete.o: $(DEFSRC)/complete.def
builtins/declare.o: $(DEFSRC)/declare.def
builtins/echo.o: $(DEFSRC)/echo.def
builtins/enable.o: $(DEFSRC)/enable.def
builtins/eval.o: $(DEFSRC)/eval.def
builtins/exec.o: $(DEFSRC)/exec.def
builtins/exit.o: $(DEFSRC)/exit.def
builtins/fc.o: $(DEFSRC)/fc.def
builtins/fg_bg.o: $(DEFSRC)/fg_bg.def
builtins/getopts.o: $(DEFSRC)/getopts.def
builtins/hash.o: $(DEFSRC)/hash.def
builtins/help.o: $(DEFSRC)/help.def
builtins/history.o: $(DEFSRC)/history.def
builtins/inlib.o: $(DEFSRC)/inlib.def
builtins/jobs.o: $(DEFSRC)/jobs.def
builtins/kill.o: $(DEFSRC)/kill.def
builtins/let.o: $(DEFSRC)/let.def
builtins/mapfile.o: $(DEFSRC)/mapfile.def
builtins/pushd.o: $(DEFSRC)/pushd.def
builtins/read.o: $(DEFSRC)/read.def
builtins/reserved.o: $(DEFSRC)/reserved.def
builtins/return.o: $(DEFSRC)/return.def
builtins/set.o: $(DEFSRC)/set.def
builtins/setattr.o: $(DEFSRC)/setattr.def
builtins/shift.o: $(DEFSRC)/shift.def
builtins/shopt.o: $(DEFSRC)/shopt.def
builtins/source.o: $(DEFSRC)/source.def
builtins/suspend.o: $(DEFSRC)/suspend.def
builtins/test.o: $(DEFSRC)/test.def
builtins/times.o: $(DEFSRC)/times.def
builtins/trap.o: $(DEFSRC)/trap.def
builtins/type.o: $(DEFSRC)/type.def
builtins/ulimit.o: $(DEFSRC)/ulimit.def
builtins/umask.o: $(DEFSRC)/umask.def
builtins/wait.o: $(DEFSRC)/wait.def
