# auto generated - do not edit

default: all

all:\
UNIT_TESTS/loader UNIT_TESTS/loader.o UNIT_TESTS/test_lib.o \
UNIT_TESTS/test_lib.vlb ctxt/bindir.o ctxt/ctxt.a ctxt/dlibdir.o ctxt/incdir.o \
ctxt/libs_dlopen.o ctxt/repos.o ctxt/slibdir.o ctxt/version.o deinstaller \
deinstaller.o install-core.o install-error.o install-posix.o install-win32.o \
install.a installer installer.o instchk instchk.o insthier.o loadso-conf \
loadso-conf.o loadso.a loadso.o loadso_dlopen.o loadso_win32.o

# Mkf-deinstall
deinstall: deinstaller conf-sosuffix
	./deinstaller
deinstall-dryrun: deinstaller conf-sosuffix
	./deinstaller dryrun

# Mkf-install
install: installer postinstall conf-sosuffix
	./installer
	./postinstall

install-dryrun: installer conf-sosuffix
	./installer dryrun

# Mkf-instchk
install-check: instchk conf-sosuffix
	./instchk

# Mkf-test
tests_clean:
	(cd UNIT_TESTS && make clean)
tests:
	(cd UNIT_TESTS && make tests)

#----------------------------------------------------------------------
# SYSDEPS start

_sd_dlopen.h:
	@echo SYSDEPS sd-dlopen run create libs-dlopen _sd_dlopen.h 
	@(cd SYSDEPS && ./sd-run modules/sd-dlopen)
libs-dlopen: _sd_dlopen.h
_sd_ptr_uint.h:
	@echo SYSDEPS sd-ptr_uint run create _sd_ptr_uint.h 
	@(cd SYSDEPS && ./sd-run modules/sd-ptr_uint)
_sd_sysinfo.h:
	@echo SYSDEPS sd-sysinfo run create _sd_sysinfo.h 
	@(cd SYSDEPS && ./sd-run modules/sd-sysinfo)


sd-dlopen_clean:
	@echo SYSDEPS sd-dlopen clean libs-dlopen _sd_dlopen.h 
	@(cd SYSDEPS && ./sd-clean modules/sd-dlopen)
sd-ptr_uint_clean:
	@echo SYSDEPS sd-ptr_uint clean _sd_ptr_uint.h 
	@(cd SYSDEPS && ./sd-clean modules/sd-ptr_uint)
sd-sysinfo_clean:
	@echo SYSDEPS sd-sysinfo clean _sd_sysinfo.h 
	@(cd SYSDEPS && ./sd-clean modules/sd-sysinfo)


sysdeps_clean:\
sd-dlopen_clean \
sd-ptr_uint_clean \
sd-sysinfo_clean \



# SYSDEPS end
#----------------------------------------------------------------------

UNIT_TESTS/loader:\
cc-link UNIT_TESTS/loader.ld UNIT_TESTS/loader.o loadso.a UNIT_TESTS/loader.lff
	./cc-link UNIT_TESTS/loader UNIT_TESTS/loader.o loadso.a

UNIT_TESTS/loader.lff:\
libs-dlopen

UNIT_TESTS/loader.o:\
cc-compile UNIT_TESTS/loader.c loadso.h
	./cc-compile UNIT_TESTS/loader.c

UNIT_TESTS/test_lib.o:\
cc-compile-dl UNIT_TESTS/test_lib.c
	./cc-compile-dl UNIT_TESTS/test_lib.c

UNIT_TESTS/test_lib.vlb:\
cc-dlib UNIT_TESTS/test_lib.dld UNIT_TESTS/test_lib.o
	./cc-dlib UNIT_TESTS/test_lib UNIT_TESTS/test_lib.o

cc-compile:\
conf-cc conf-cctype conf-systype conf-cflags

cc-compile-dl:\
cc-compile conf-dlflag

cc-dlib:\
conf-ldtype conf-ld conf-sosuffix mk-libname

cc-link:\
conf-ld conf-ldtype conf-systype

cc-slib:\
conf-systype

conf-cctype:\
conf-cc mk-cctype
	./mk-cctype > conf-cctype.tmp && mv conf-cctype.tmp conf-cctype

conf-dlflag:\
mk-dlflag
	./mk-dlflag > conf-dlflag.tmp && mv conf-dlflag.tmp conf-dlflag

conf-ldtype:\
conf-ld mk-ldtype
	./mk-ldtype > conf-ldtype.tmp && mv conf-ldtype.tmp conf-ldtype

conf-sosuffix:\
mk-sosuffix
	./mk-sosuffix > conf-sosuffix.tmp && mv conf-sosuffix.tmp conf-sosuffix

conf-systype:\
mk-systype
	./mk-systype > conf-systype.tmp && mv conf-systype.tmp conf-systype

# ctxt/bindir.c.mff
ctxt/bindir.c: mk-ctxt conf-bindir
	rm -f ctxt/bindir.c
	./mk-ctxt ctxt_bindir < conf-bindir > ctxt/bindir.c

ctxt/bindir.o:\
cc-compile ctxt/bindir.c
	./cc-compile ctxt/bindir.c

ctxt/ctxt.a:\
cc-slib ctxt/ctxt.sld ctxt/bindir.o ctxt/dlibdir.o ctxt/incdir.o ctxt/repos.o \
ctxt/slibdir.o ctxt/version.o ctxt/libs_dlopen.o
	./cc-slib ctxt/ctxt ctxt/bindir.o ctxt/dlibdir.o ctxt/incdir.o ctxt/repos.o \
	ctxt/slibdir.o ctxt/version.o ctxt/libs_dlopen.o

# ctxt/dlibdir.c.mff
ctxt/dlibdir.c: mk-ctxt conf-dlibdir
	rm -f ctxt/dlibdir.c
	./mk-ctxt ctxt_dlibdir < conf-dlibdir > ctxt/dlibdir.c

ctxt/dlibdir.o:\
cc-compile ctxt/dlibdir.c
	./cc-compile ctxt/dlibdir.c

# ctxt/incdir.c.mff
ctxt/incdir.c: mk-ctxt conf-incdir
	rm -f ctxt/incdir.c
	./mk-ctxt ctxt_incdir < conf-incdir > ctxt/incdir.c

ctxt/incdir.o:\
cc-compile ctxt/incdir.c
	./cc-compile ctxt/incdir.c

# ctxt/libs_dlopen.c.mff
ctxt/libs_dlopen.c: mk-ctxt libs-dlopen
	rm -f ctxt/libs_dlopen.c
	./mk-ctxt ctxt_libs_dlopen < libs-dlopen > ctxt/libs_dlopen.c

ctxt/libs_dlopen.o:\
cc-compile ctxt/libs_dlopen.c
	./cc-compile ctxt/libs_dlopen.c

# ctxt/repos.c.mff
ctxt/repos.c: mk-ctxt conf-repos
	rm -f ctxt/repos.c
	./mk-ctxt ctxt_repos < conf-repos > ctxt/repos.c

ctxt/repos.o:\
cc-compile ctxt/repos.c
	./cc-compile ctxt/repos.c

# ctxt/slibdir.c.mff
ctxt/slibdir.c: mk-ctxt conf-slibdir
	rm -f ctxt/slibdir.c
	./mk-ctxt ctxt_slibdir < conf-slibdir > ctxt/slibdir.c

ctxt/slibdir.o:\
cc-compile ctxt/slibdir.c
	./cc-compile ctxt/slibdir.c

# ctxt/version.c.mff
ctxt/version.c: mk-ctxt VERSION
	rm -f ctxt/version.c
	./mk-ctxt ctxt_version < VERSION > ctxt/version.c

ctxt/version.o:\
cc-compile ctxt/version.c
	./cc-compile ctxt/version.c

deinstaller:\
cc-link deinstaller.ld deinstaller.o insthier.o install.a ctxt/ctxt.a
	./cc-link deinstaller deinstaller.o insthier.o install.a ctxt/ctxt.a

deinstaller.o:\
cc-compile deinstaller.c install.h
	./cc-compile deinstaller.c

install-core.o:\
cc-compile install-core.c install.h
	./cc-compile install-core.c

install-error.o:\
cc-compile install-error.c install.h
	./cc-compile install-error.c

install-posix.o:\
cc-compile install-posix.c install.h
	./cc-compile install-posix.c

install-win32.o:\
cc-compile install-win32.c install.h
	./cc-compile install-win32.c

install.a:\
cc-slib install.sld install-core.o install-posix.o install-win32.o \
install-error.o
	./cc-slib install install-core.o install-posix.o install-win32.o \
	install-error.o

install.h:\
install_os.h

installer:\
cc-link installer.ld installer.o insthier.o install.a ctxt/ctxt.a
	./cc-link installer installer.o insthier.o install.a ctxt/ctxt.a

installer.o:\
cc-compile installer.c install.h
	./cc-compile installer.c

instchk:\
cc-link instchk.ld instchk.o insthier.o install.a ctxt/ctxt.a
	./cc-link instchk instchk.o insthier.o install.a ctxt/ctxt.a

instchk.o:\
cc-compile instchk.c install.h
	./cc-compile instchk.c

insthier.o:\
cc-compile insthier.c ctxt.h install.h
	./cc-compile insthier.c

loadso-conf:\
cc-link loadso-conf.ld loadso-conf.o ctxt/ctxt.a
	./cc-link loadso-conf loadso-conf.o ctxt/ctxt.a

loadso-conf.o:\
cc-compile loadso-conf.c ctxt.h _sd_sysinfo.h
	./cc-compile loadso-conf.c

loadso.a:\
cc-slib loadso.sld loadso.o loadso_dlopen.o loadso_win32.o
	./cc-slib loadso loadso.o loadso_dlopen.o loadso_win32.o

loadso.h:\
sd_dlopen.h

loadso.o:\
cc-compile loadso.c loadso.h
	./cc-compile loadso.c

loadso_dlopen.o:\
cc-compile loadso_dlopen.c loadso.h _sd_ptr_uint.h
	./cc-compile loadso_dlopen.c

loadso_win32.o:\
cc-compile loadso_win32.c _sd_sysinfo.h loadso.h _sd_ptr_uint.h
	./cc-compile loadso_win32.c

mk-cctype:\
conf-cc conf-systype

mk-ctxt:\
mk-mk-ctxt
	./mk-mk-ctxt

mk-dlflag:\
conf-cctype conf-systype

mk-ldtype:\
conf-ld conf-systype conf-cctype

mk-libname:\
conf-systype conf-sosuffix

mk-mk-ctxt:\
conf-cc conf-ld

mk-sosuffix:\
conf-systype

mk-systype:\
conf-cc conf-ld

sd_dlopen.h:\
_sd_dlopen.h

clean-all: sysdeps_clean tests_clean obj_clean ext_clean
clean: obj_clean
obj_clean:
	rm -f UNIT_TESTS/loader UNIT_TESTS/loader.o UNIT_TESTS/test_lib.o `cat \
	UNIT_TESTS/test_lib.vlb` UNIT_TESTS/test_lib.vlb ctxt/bindir.c ctxt/bindir.o \
	ctxt/ctxt.a ctxt/dlibdir.c ctxt/dlibdir.o ctxt/incdir.c ctxt/incdir.o \
	ctxt/libs_dlopen.c ctxt/libs_dlopen.o ctxt/repos.c ctxt/repos.o ctxt/slibdir.c \
	ctxt/slibdir.o ctxt/version.c ctxt/version.o deinstaller deinstaller.o \
	install-core.o install-error.o install-posix.o install-win32.o install.a \
	installer installer.o instchk instchk.o insthier.o loadso-conf loadso-conf.o \
	loadso.a loadso.o loadso_dlopen.o loadso_win32.o
ext_clean:
	rm -f conf-cctype conf-dlflag conf-ldtype conf-sosuffix conf-systype mk-ctxt

regen:
	cpj-genmk > Makefile.tmp && mv Makefile.tmp Makefile
