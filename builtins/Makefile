# This Makefile for building libbuiltins.a is in -*- text -*- for Emacs.
SHELL = /bin/sh
RANLIB = ranlib
CC = gcc
CC_FOR_BUILD = $(CC)
AR = ar
ARFLAGS = cr
RM = rm -f
CP = cp

prefix = /usr/local

srcdir = .

topdir = ..

datarootdir = ${prefix}/share

includedir = ${prefix}/include
datadir = ${datarootdir}
localedir = ${datarootdir}/locale

loadablesdir = ${libdir}/bash

# Support an alternate destination root directory for package building
DESTDIR =

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
BUILD_DIR = /home/ayursha/code/shell

LIBBUILD = ${BUILD_DIR}/lib

PROFILE_FLAGS = 
CFLAGS = -g -O2 -Wno-parentheses -Wno-format-security -Wfatal-errors
CFLAGS_FOR_BUILD = -g -O2 -Wno-parentheses -Wno-format-security 
CPPFLAGS = 
CPPFLAGS_FOR_BUILD = 
LOCAL_CFLAGS =  ${DEBUG}

LIBS = -ldl 
LDFLAGS =  $(LOCAL_LDFLAGS) $(CFLAGS)
LDFLAGS_FOR_BUILD = $(LDFLAGS) $(LOCAL_LDFLAGS) $(CFLAGS_FOR_BUILD)
LOCAL_LDFLAGS = -rdynamic
LIBS_FOR_BUILD = $(LIBS)
#LIBS_FOR_BUILD = $(LIBS)

BASHINCDIR = ${topdir}/include

HELPDIR = 
MKDIRS = ${topdir}/support/mkdirs

INCLUDES = -I$(topdir) -I$(BASHINCDIR) -I$(topdir)/lib -I$(srcdir)

BASE_CCFLAGS = ${PROFILE_FLAGS} $(SYSTEM_FLAGS) \
	 ${INCLUDES} $(LOCAL_CFLAGS)

CCFLAGS = $(BASE_CCFLAGS) $(CPPFLAGS) $(CFLAGS)

CCFLAGS_FOR_BUILD = $(BASE_CCFLAGS) $(CPPFLAGS_FOR_BUILD) $(CFLAGS_FOR_BUILD)

GCC_LINT_FLAGS = -Wall -Wshadow -Wpointer-arith -Wcast-qual \
		 -Wcast-align -Wstrict-prototypes -Wconversion \
		 -Wmissing-prototypes -Wtraditional -Wredundant-decls -pedantic

DIRECTDEFINE = -D $(srcdir)
HELPDIRDEFINE = 
HELPSTRINGS = 

# default rule for making a .o file from a .c file
.c.o:
	$(RM) $@
	$(CC) -c $(CCFLAGS) $<

DEFSRC =  $(srcdir)/alias.c $(srcdir)/bind.c $(srcdir)/break.c \
	  $(srcdir)/builtin.c $(srcdir)/caller.c \
	  $(srcdir)/cd.c $(srcdir)/colon.c \
	  $(srcdir)/command.c $(srcdir)/declare.c $(srcdir)/echo.c \
	  $(srcdir)/enable.c $(srcdir)/eval.c $(srcdir)/getopts.c \
	  $(srcdir)/exec.c $(srcdir)/exit.c $(srcdir)/fc.c \
	  $(srcdir)/fg_bg.c $(srcdir)/hash.c $(srcdir)/help.c \
	  $(srcdir)/history.c $(srcdir)/jobs.c $(srcdir)/kill.c \
	  $(srcdir)/let.c $(srcdir)/read.c $(srcdir)/return.c \
	  $(srcdir)/set.c $(srcdir)/setattr.c $(srcdir)/shift.c \
	  $(srcdir)/source.c $(srcdir)/suspend.c $(srcdir)/test.c \
	  $(srcdir)/times.c $(srcdir)/trap.c $(srcdir)/type.c \
	  $(srcdir)/ulimit.c $(srcdir)/umask.c $(srcdir)/wait.c \
	  $(srcdir)/pushd.c $(srcdir)/shopt.c \
	  $(srcdir)/printf.c $(srcdir)/complete.c $(srcdir)/mapfile.c

STATIC_SOURCE = common.c evalstring.c evalfile.c getopt.c bashgetopt.c \
		getopt.h 

OFILES = builtins.o \
	alias.o bind.o break.o builtin.o caller.o cd.o colon.o command.o \
	common.o declare.o echo.o enable.o eval.o evalfile.o \
	evalstring.o exec.o exit.o fc.o fg_bg.o hash.o help.o history.o \
	jobs.o kill.o let.o mapfile.o \
	pushd.o read.o return.o set.o setattr.o shift.o source.o \
	suspend.o test.o times.o trap.o type.o ulimit.o umask.o \
	wait.o getopts.o shopt.o printf.o getopt.o bashgetopt.o complete.o

all: libbuiltins.a

libbuiltins.a: $(OFILES) builtins.o
	$(RM) $@
	$(AR) $(ARFLAGS) $@ $(OFILES)
	-$(RANLIB) $@

ulimit.o: pipesize.h

pipesize.h:	psize.aux
	$(SHELL) $(srcdir)/psize.sh > $@

# Technically this is wrong; the pipe size should be for the target system,
# not the build host.
psize.aux:	psize.c
	$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ $(srcdir)/psize.c

clean:
	$(RM) $(OFILES) libbuiltins.a
	$(RM) $(MKBUILTINS) gen-helpfiles $(CREATED_OBJECTS)
	-test -d helpfiles && $(RM) -r helpfiles

mostlyclean: 
	$(RM) $(OFILES) libbuiltins.a

distclean maintainer-clean: clean
	$(RM) Makefile

$(OFILES):	$(MKBUILTINS) ../config.h

../version.h: ../config.h ../Makefile Makefile
	-( cd ${BUILD_DIR} && ${MAKE} ${MFLAGS} version.h )

# dependencies

# C files
bashgetopt.o: ../config.h $(topdir)/bashansi.h $(BASHINCDIR)/ansi_stdlib.h
bashgetopt.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/bashjmp.h
bashgetopt.o: $(topdir)/command.h $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/error.h
bashgetopt.o: $(topdir)/variables.h $(topdir)/conftypes.h $(topdir)/quit.h $(BASHINCDIR)/maxpath.h
bashgetopt.o: $(topdir)/unwind_prot.h $(topdir)/dispose_cmd.h
bashgetopt.o: $(topdir)/make_cmd.h $(topdir)/subst.h $(topdir)/sig.h
bashgetopt.o: ../pathnames.h $(topdir)/externs.h $(srcdir)/common.h
bashgetopt.o: $(BASHINCDIR)/chartypes.h
common.o: $(topdir)/bashtypes.h $(BASHINCDIR)/posixstat.h $(topdir)/bashansi.h $(BASHINCDIR)/ansi_stdlib.h
common.o: $(topdir)/shell.h $(topdir)/syntax.h ../config.h $(topdir)/bashjmp.h
common.o: $(topdir)/sig.h $(topdir)/command.h
common.o: $(topdir)/general.h $(topdir)/xmalloc.h $(BASHINCDIR)/stdc.h $(BASHINCDIR)/memalloc.h
common.o: $(topdir)/variables.h $(topdir)/conftypes.h $(topdir)/input.h
common.o: $(topdir)/siglist.h $(topdir)/bashhist.h $(topdir)/quit.h
common.o: $(topdir)/unwind_prot.h $(BASHINCDIR)/maxpath.h $(topdir)/jobs.h
common.o: $(topdir)/builtins.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h
common.o: $(topdir)/subst.h $(topdir)/execute_cmd.h $(topdir)/error.h
common.o: $(topdir)/externs.h ../pathnames.h ./builtext.h
common.o: $(BASHINCDIR)/chartypes.h
evalfile.o: $(topdir)/bashtypes.h $(BASHINCDIR)/posixstat.h ${BASHINCDIR}/filecntl.h
evalfile.o: $(topdir)/bashansi.h $(BASHINCDIR)/ansi_stdlib.h
evalfile.o: $(topdir)/shell.h $(topdir)/syntax.h ../config.h $(topdir)/bashjmp.h
evalfile.o: $(topdir)/command.h $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/error.h
evalfile.o: $(topdir)/variables.h $(topdir)/conftypes.h $(topdir)/quit.h $(BASHINCDIR)/maxpath.h
evalfile.o: $(topdir)/unwind_prot.h $(topdir)/dispose_cmd.h
evalfile.o: $(topdir)/make_cmd.h $(topdir)/subst.h $(topdir)/sig.h
evalfile.o: ../pathnames.h $(topdir)/externs.h
evalfile.o: $(topdir)/jobs.h $(topdir)/builtins.h $(topdir)/flags.h
evalfile.o: $(topdir)/input.h $(topdir)/execute_cmd.h
evalfile.o: $(topdir)/bashhist.h $(srcdir)/common.h
evalstring.o: ../config.h $(topdir)/bashansi.h $(BASHINCDIR)/ansi_stdlib.h
evalstring.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/bashjmp.h
evalstring.o: $(topdir)/sig.h $(topdir)/command.h $(topdir)/siglist.h
evalstring.o: $(BASHINCDIR)/memalloc.h $(topdir)/variables.h $(topdir)/conftypes.h $(topdir)/input.h
evalstring.o: $(topdir)/quit.h $(topdir)/unwind_prot.h
evalstring.o: $(BASHINCDIR)/maxpath.h $(topdir)/jobs.h $(topdir)/builtins.h
evalstring.o: $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/subst.h
evalstring.o: $(topdir)/externs.h $(topdir)/jobs.h $(topdir)/builtins.h
evalstring.o: $(topdir)/flags.h $(topdir)/input.h $(topdir)/execute_cmd.h
evalstring.o: $(topdir)/bashhist.h $(srcdir)/common.h
evalstring.o: $(topdir)/trap.h $(topdir)/redir.h ../pathnames.h
#evalstring.o: $(topdir)/y.tab.h
getopt.o: ../config.h $(BASHINCDIR)/memalloc.h
getopt.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/bashjmp.h $(topdir)/command.h
getopt.o: $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/error.h $(topdir)/variables.h $(topdir)/conftypes.h
getopt.o: $(topdir)/quit.h $(BASHINCDIR)/maxpath.h $(topdir)/unwind_prot.h
getopt.o: $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/subst.h
getopt.o: $(topdir)/sig.h ../pathnames.h $(topdir)/externs.h
getopt.o: $(srcdir)/getopt.h 

# def files
alias.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
alias.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h $(BASHINCDIR)/maxpath.h
alias.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
alias.o: $(topdir)/subst.h $(topdir)/externs.h $(srcdir)/common.h
alias.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
alias.o: ../pathnames.h
bind.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h $(topdir)/error.h
bind.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
bind.o: $(topdir)/subst.h $(topdir)/externs.h $(srcdir)/bashgetopt.h
bind.o: $(topdir)/general.h $(topdir)/xmalloc.h $(BASHINCDIR)/maxpath.h $(topdir)/bashline.h
bind.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h 
bind.o: ../pathnames.h
break.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h 
break.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
break.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
break.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
break.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
break.o: ../pathnames.h
builtin.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
builtin.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/externs.h
builtin.o: $(topdir)/quit.h $(srcdir)/common.h $(BASHINCDIR)/maxpath.h $(topdir)/sig.h
builtin.o: $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/subst.h
builtin.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h 
builtin.o: $(srcdir)/bashgetopt.h ../pathnames.h
caller.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h $(topdir)/error.h
caller.o: $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/quit.h $(topdir)/dispose_cmd.h
caller.o: $(topdir)/make_cmd.h $(topdir)/subst.h $(topdir)/externs.h $(topdir)/sig.h
caller.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
caller.o: $(srcdir)/common.h $(BASHINCDIR)/maxpath.h ./builtext.h
caller.o: ${BASHINCDIR}/chartypes.h $(topdir)/bashtypes.h ../pathnames.h
cd.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h $(topdir)/error.h
cd.o: $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/quit.h $(topdir)/dispose_cmd.h
cd.o: $(topdir)/make_cmd.h $(topdir)/subst.h $(topdir)/externs.h
cd.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
cd.o: $(srcdir)/common.h $(BASHINCDIR)/maxpath.h ../pathnames.h
cd.o: $(topdir)/sig.h
command.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
command.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/externs.h
command.o: $(topdir)/quit.h $(srcdir)/bashgetopt.h $(BASHINCDIR)/maxpath.h
command.o: $(topdir)/sig.h
command.o: $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/subst.h
command.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h 
command.o: ../pathnames.h
declare.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
declare.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
declare.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
declare.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
declare.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
declare.o: $(topdir)/arrayfunc.h $(srcdir)/bashgetopt.h $(topdir)/flags.h
declare.o: ./builtext.h ../pathnames.h
echo.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h $(topdir)/error.h
echo.o: $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/subst.h $(topdir)/externs.h
echo.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
echo.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
echo.o: $(BASHINCDIR)/maxpath.h ../pathnames.h
enable.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
enable.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
enable.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h
enable.o: $(topdir)/subst.h $(topdir)/externs.h $(topdir)/sig.h
enable.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
enable.o: $(BASHINCDIR)/maxpath.h ../pathnames.h
enable.o: $(topdir)/pcomplete.h
eval.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
eval.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
eval.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h
eval.o: $(topdir)/subst.h $(topdir)/externs.h  $(topdir)/sig.h
eval.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
eval.o: $(BASHINCDIR)/maxpath.h ../pathnames.h
exec.o: $(topdir)/bashtypes.h
exec.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
exec.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
exec.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
exec.o: $(topdir)/subst.h $(topdir)/externs.h $(topdir)/flags.h
exec.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
exec.o: $(srcdir)/common.h $(topdir)/execute_cmd.h $(BASHINCDIR)/maxpath.h
exec.o: $(topdir)/findcmd.h $(topdir)/jobs.h ../pathnames.h
exit.o: $(topdir)/bashtypes.h
exit.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
exit.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
exit.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
exit.o: $(topdir)/subst.h $(topdir)/externs.h  $(topdir)/jobs.h
exit.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
exit.o: $(BASHINCDIR)/maxpath.h ./builtext.h ../pathnames.h
fc.o: $(topdir)/bashtypes.h $(BASHINCDIR)/posixstat.h
fc.o: $(topdir)/builtins.h $(topdir)/command.h $(srcdir)/bashgetopt.h
fc.o: $(topdir)/bashhist.h
fc.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h $(topdir)/error.h
fc.o: $(topdir)/general.h $(topdir)/xmalloc.h $(BASHINCDIR)/maxpath.h
fc.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
fc.o: $(topdir)/subst.h $(topdir)/externs.h $(topdir)/shell.h $(topdir)/syntax.h
fc.o: $(topdir)/flags.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
fc.o: $(topdir)/bashansi.h $(BASHINCDIR)/ansi_stdlib.h $(BASHINCDIR)/chartypes.h
fc.o: ../pathnames.h
fg_bg.o: $(topdir)/bashtypes.h $(srcdir)/bashgetopt.h
fg_bg.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
fg_bg.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
fg_bg.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
fg_bg.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
fg_bg.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
fg_bg.o: $(topdir)/jobs.h ../pathnames.h
getopts.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
getopts.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
getopts.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
getopts.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
getopts.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
getopts.o: ../pathnames.h
hash.o: $(topdir)/builtins.h $(topdir)/command.h $(topdir)/quit.h
hash.o: $(topdir)/findcmd.h $(topdir)/hashlib.h $(topdir)/sig.h
hash.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
hash.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
hash.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
hash.o: $(srcdir)/common.h $(BASHINCDIR)/maxpath.h ../pathnames.h
help.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
help.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
help.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h
help.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
help.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
help.o: ${srcdir}/common.h $(topdir)/sig.h ../pathnames.h
history.o: $(topdir)/bashtypes.h
history.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
history.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
history.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h
history.o: $(topdir)/subst.h $(topdir)/externs.h $(topdir)/sig.h
history.o: ${BASHINCDIR}/filecntl.h $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h
history.o: $(topdir)/variables.h $(topdir)/conftypes.h $(topdir)/bashhist.h $(BASHINCDIR)/maxpath.h
history.o: ../pathnames.h
jobs.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h $(topdir)/error.h
jobs.o: $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/quit.h $(srcdir)/bashgetopt.h
jobs.o: $(BASHINCDIR)/maxpath.h $(topdir)/externs.h $(topdir)/jobs.h
jobs.o: $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/subst.h
jobs.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h 
jobs.o: $(topdir)/sig.h ../pathnames.h
kill.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h $(topdir)/error.h
kill.o: $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/subst.h $(topdir)/externs.h
kill.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
kill.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/trap.h $(topdir)/unwind_prot.h
kill.o: $(topdir)/variables.h $(topdir)/conftypes.h $(BASHINCDIR)/maxpath.h
kill.o: $(topdir)/jobs.h ../pathnames.h
let.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
let.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
let.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
let.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
let.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
let.o: ../pathnames.h
printf.o: ../config.h $(BASHINCDIR)/memalloc.h $(topdir)/bashjmp.h
printf.o: $(topdir)/command.h $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
printf.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h
printf.o: $(topdir)/subst.h $(topdir)/externs.h $(topdir)/sig.h
printf.o: ../pathnames.h $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h
printf.o: $(topdir)/variables.h $(topdir)/conftypes.h $(BASHINCDIR)/stdc.h $(srcdir)/bashgetopt.h
printf.o: $(topdir)/bashtypes.h ${srcdir}/common.h $(BASHINCDIR)/chartypes.h
printf.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h
printf.o: ../pathnames.h
pushd.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
pushd.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
pushd.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h
pushd.o: $(topdir)/subst.h $(topdir)/externs.h $(topdir)/sig.h
pushd.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
pushd.o: $(BASHINCDIR)/maxpath.h $(srcdir)/common.h ./builtext.h
pushd.o: ../pathnames.h
read.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
read.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
read.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h
read.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
read.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
read.o: $(BASHINCDIR)/shtty.h $(topdir)/sig.h
read.o: ${BASHINCDIR}/shmbutil.h ${BASHINCDIR}/shmbchar.h
read.o: $(topdir)/arrayfunc.h ../pathnames.h
return.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
return.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
return.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
return.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
return.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
return.o: ../pathnames.h
set.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
set.o: $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/subst.h $(topdir)/externs.h
set.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h
set.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
set.o: $(BASHINCDIR)/maxpath.h $(topdir)/error.h $(topdir)/sig.h
set.o: $(topdir)/arrayfunc.h ../pathnames.h
setattr.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
setattr.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h $(BASHINCDIR)/maxpath.h
setattr.o: $(topdir)/quit.h $(srcdir)/common.h $(srcdir)/bashgetopt.h
setattr.o: $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/subst.h
setattr.o: $(topdir)/externs.h $(topdir)/flags.h $(topdir)/sig.h
setattr.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h 
setattr.o: $(topdir)/arrayfunc.h ../pathnames.h
shift.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
shift.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
shift.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
shift.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
shift.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
shift.o: ../pathnames.h
shopt.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
shopt.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h 
shopt.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h
shopt.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
shopt.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
shopt.o: $(srcdir)/common.h $(srcdir)/bashgetopt.h ../pathnames.h
shopt.o: $(topdir)/bashhist.h $(topdir)/bashline.h $(topdir)/sig.h
source.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
source.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/findcmd.h
source.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
source.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
source.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
source.o: $(srcdir)/bashgetopt.h $(topdir)/flags.h $(topdir)/trap.h
source.o: ../pathnames.h
suspend.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
suspend.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
suspend.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
suspend.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
suspend.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
suspend.o: $(topdir)/jobs.h ../pathnames.h
test.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
test.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
test.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
test.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
test.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
test.o: $(topdir)/test.h ../pathnames.h
times.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
times.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
times.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
times.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
times.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
times.o: $(BASHINCDIR)/posixtime.h ../pathnames.h
trap.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
trap.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h $(topdir)/externs.h
trap.o: $(topdir)/quit.h $(srcdir)/common.h $(BASHINCDIR)/maxpath.h $(topdir)/sig.h
trap.o: $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/subst.h
trap.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
trap.o: $(topdir)/findcmd.h ../pathnames.h
type.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
type.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
type.o: $(topdir)/quit.h $(srcdir)/common.h $(BASHINCDIR)/maxpath.h $(topdir)/sig.h
type.o: $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/subst.h
type.o: $(topdir)/externs.h $(topdir)/hashcmd.h ../pathnames.h
type.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h 
ulimit.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
ulimit.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
ulimit.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
ulimit.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
ulimit.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
ulimit.o: ../pathnames.h
umask.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
umask.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
umask.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
umask.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
umask.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
umask.o: $(BASHINCDIR)/chartypes.h ../pathnames.h
wait.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
wait.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
wait.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h
wait.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
wait.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/unwind_prot.h $(topdir)/variables.h $(topdir)/conftypes.h
wait.o: $(topdir)/jobs.h $(topdir)/sig.h
wait.o: $(BASHINCDIR)/chartypes.h ../pathnames.h

complete.o: ../config.h ../pathnames.h
complete.o: ${topdir}/shell.h $(topdir)/syntax.h ${topdir}/bashjmp.h ${topdir}/sig.h  
complete.o: ${topdir}/unwind_prot.h ${topdir}/variables.h
complete.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
complete.o: ${topdir}/bashtypes.h ${topdir}/bashansi.h ${BASHINCDIR}/ansi_stdlib.h
complete.o: ${topdir}/builtins.h ${topdir}/general.h
complete.o: ${topdir}/bashtypes.h ${BASHINCDIR}/chartypes.h ${topdir}/xmalloc.h
complete.o: ${topdir}/pcomplete.h
complete.o: ${srcdir}/common.h ${srcdir}/bashgetopt.h
mapfile.o: $(topdir)/command.h ../config.h $(BASHINCDIR)/memalloc.h
mapfile.o: $(topdir)/error.h $(topdir)/general.h $(topdir)/xmalloc.h
mapfile.o: $(topdir)/quit.h $(topdir)/dispose_cmd.h $(topdir)/make_cmd.h $(topdir)/sig.h
mapfile.o: $(topdir)/subst.h $(topdir)/externs.h $(BASHINCDIR)/maxpath.h
mapfile.o: $(topdir)/shell.h $(topdir)/syntax.h $(topdir)/variables.h $(topdir)/conftypes.h
mapfile.o: $(topdir)/arrayfunc.h ../pathnames.h

# libintl dependencies
bind.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
break.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
caller.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
cd.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
common.c: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
complete.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
declare.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
enable.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
evalfile.c: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
exec.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
exit.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
fc.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
fg_bg.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
getopt.c: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
hash.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
help.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
history.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
jobs.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
kill.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
let.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
mapfile.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
printf.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
pushd.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
read.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
return.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
set.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
setattr.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
shift.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
shopt.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
source.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
suspend.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
type.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
ulimit.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
umask.o: ${topdir}/bashintl.h ${LIBINTL_H} $(BASHINCDIR)/gettext.h
