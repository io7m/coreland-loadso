# auto generated - do not edit

default: all

all:\
UNIT_TESTS/loader UNIT_TESTS/test_lib.vlb ctxt/ctxt.a deinstaller inst-check \
inst-copy inst-dir inst-link installer instchk loadso-conf loadso.a 

# -- SYSDEPS start
_sd_dlopen.h:
	@echo SYSDEPS sd-dlopen run create libs-dlopen _sd_dlopen.h 
	@(cd SYSDEPS/modules/sd-dlopen && ./run)
libs-dlopen: _sd_dlopen.h


sd-dlopen_clean:
	@echo SYSDEPS sd-dlopen clean libs-dlopen _sd_dlopen.h 
	@(cd SYSDEPS/modules/sd-dlopen && ./clean)


sysdeps_clean:\
sd-dlopen_clean \


# -- SYSDEPS end

UNIT_TESTS/loader:\
cc-link UNIT_TESTS/loader.ld UNIT_TESTS/loader.lff UNIT_TESTS/loader.o \
loadso.a 
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
conf-systype conf-cc mk-cctype 
	./mk-cctype > conf-cctype.tmp && mv conf-cctype.tmp conf-cctype

conf-dlflag:\
mk-dlflag 
	./mk-dlflag > conf-dlflag.tmp && mv conf-dlflag.tmp conf-dlflag

conf-ldtype:\
conf-systype conf-ld conf-cctype mk-ldtype 
	./mk-ldtype > conf-ldtype.tmp && mv conf-ldtype.tmp conf-ldtype

conf-sosuffix:\
mk-sosuffix 
	./mk-sosuffix > conf-sosuffix.tmp && mv conf-sosuffix.tmp \
	conf-sosuffix

conf-systype:\
mk-systype 
	./mk-systype > conf-systype.tmp && mv conf-systype.tmp conf-systype

ctxt/bindir.c: mk-ctxt conf-bindir
	rm -f ctxt/bindir.c
	./mk-ctxt ctxt_bindir < conf-bindir > ctxt/bindir.c

ctxt/bindir.o:\
cc-compile ctxt/bindir.c 
	./cc-compile ctxt/bindir.c

ctxt/ctxt.a:\
cc-slib ctxt/ctxt.sld ctxt/bindir.o ctxt/dlibdir.o ctxt/incdir.o \
ctxt/repos.o ctxt/slibdir.o ctxt/version.o ctxt/libs_dlopen.o 
	./cc-slib ctxt/ctxt ctxt/bindir.o ctxt/dlibdir.o ctxt/incdir.o \
	ctxt/repos.o ctxt/slibdir.o ctxt/version.o ctxt/libs_dlopen.o 

ctxt/dlibdir.c: mk-ctxt conf-dlibdir
	rm -f ctxt/dlibdir.c
	./mk-ctxt ctxt_dlibdir < conf-dlibdir > ctxt/dlibdir.c

ctxt/dlibdir.o:\
cc-compile ctxt/dlibdir.c 
	./cc-compile ctxt/dlibdir.c

ctxt/incdir.c: mk-ctxt conf-incdir
	rm -f ctxt/incdir.c
	./mk-ctxt ctxt_incdir < conf-incdir > ctxt/incdir.c

ctxt/incdir.o:\
cc-compile ctxt/incdir.c 
	./cc-compile ctxt/incdir.c

ctxt/libs_dlopen.c: mk-ctxt libs-dlopen
	rm -f ctxt/libs_dlopen.c
	./mk-ctxt ctxt_libs_dlopen < libs-dlopen > ctxt/libs_dlopen.c

ctxt/libs_dlopen.o:\
cc-compile ctxt/libs_dlopen.c 
	./cc-compile ctxt/libs_dlopen.c

ctxt/repos.c: mk-ctxt conf-repos
	rm -f ctxt/repos.c
	./mk-ctxt ctxt_repos < conf-repos > ctxt/repos.c

ctxt/repos.o:\
cc-compile ctxt/repos.c 
	./cc-compile ctxt/repos.c

ctxt/slibdir.c: mk-ctxt conf-slibdir
	rm -f ctxt/slibdir.c
	./mk-ctxt ctxt_slibdir < conf-slibdir > ctxt/slibdir.c

ctxt/slibdir.o:\
cc-compile ctxt/slibdir.c 
	./cc-compile ctxt/slibdir.c

ctxt/version.c: mk-ctxt VERSION
	rm -f ctxt/version.c
	./mk-ctxt ctxt_version < VERSION > ctxt/version.c

ctxt/version.o:\
cc-compile ctxt/version.c 
	./cc-compile ctxt/version.c

deinstaller:\
cc-link deinstaller.ld deinstaller.o insthier.o install_core.o \
install_error.o ctxt/ctxt.a 
	./cc-link deinstaller deinstaller.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 

deinstaller.o:\
cc-compile deinstaller.c install.h 
	./cc-compile deinstaller.c

inst-check:\
cc-link inst-check.ld inst-check.o install_error.o 
	./cc-link inst-check inst-check.o install_error.o 

inst-check.o:\
cc-compile inst-check.c install.h 
	./cc-compile inst-check.c

inst-copy:\
cc-link inst-copy.ld inst-copy.o install_error.o 
	./cc-link inst-copy inst-copy.o install_error.o 

inst-copy.o:\
cc-compile inst-copy.c install.h 
	./cc-compile inst-copy.c

inst-dir:\
cc-link inst-dir.ld inst-dir.o install_error.o 
	./cc-link inst-dir inst-dir.o install_error.o 

inst-dir.o:\
cc-compile inst-dir.c install.h 
	./cc-compile inst-dir.c

inst-link:\
cc-link inst-link.ld inst-link.o install_error.o 
	./cc-link inst-link inst-link.o install_error.o 

inst-link.o:\
cc-compile inst-link.c install.h 
	./cc-compile inst-link.c

install_core.o:\
cc-compile install_core.c install.h 
	./cc-compile install_core.c

install_error.o:\
cc-compile install_error.c install.h 
	./cc-compile install_error.c

installer:\
cc-link installer.ld installer.o insthier.o install_core.o install_error.o \
ctxt/ctxt.a 
	./cc-link installer installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 

installer.o:\
cc-compile installer.c install.h 
	./cc-compile installer.c

instchk:\
cc-link instchk.ld instchk.o insthier.o install_core.o install_error.o \
ctxt/ctxt.a 
	./cc-link instchk instchk.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 

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
cc-compile loadso-conf.c ctxt.h 
	./cc-compile loadso-conf.c

loadso.a:\
cc-slib loadso.sld loadso_close.o loadso_error.o loadso_func.o loadso_open.o \
loadso_sym.o 
	./cc-slib loadso loadso_close.o loadso_error.o loadso_func.o \
	loadso_open.o loadso_sym.o 

loadso.h:\
sd_dlopen.h 

loadso_close.o:\
cc-compile loadso_close.c loadso.h 
	./cc-compile loadso_close.c

loadso_error.o:\
cc-compile loadso_error.c loadso.h 
	./cc-compile loadso_error.c

loadso_func.o:\
cc-compile loadso_func.c loadso.h 
	./cc-compile loadso_func.c

loadso_open.o:\
cc-compile loadso_open.c loadso.h 
	./cc-compile loadso_open.c

loadso_sym.o:\
cc-compile loadso_sym.c loadso.h 
	./cc-compile loadso_sym.c

mk-cctype:\
conf-cc conf-systype 

mk-ctxt:\
mk-mk-ctxt 
	./mk-mk-ctxt

mk-dlflag:\
conf-cctype conf-systype 

mk-ldtype:\
conf-cctype conf-systype 

mk-libname:\
conf-systype conf-sosuffix 

mk-mk-ctxt:\
conf-cc 

mk-sosuffix:\
conf-systype 

mk-systype:\
conf-cc 

sd_dlopen.h:\
_sd_dlopen.h 

clean-all: sysdeps_clean tests_clean obj_clean 
clean: obj_clean
obj_clean: 
	rm -f UNIT_TESTS/loader UNIT_TESTS/loader.o UNIT_TESTS/test_lib.o \
	`cat UNIT_TESTS/test_lib.vlb` UNIT_TESTS/test_lib.vlb conf-dlflag \
	ctxt/bindir.c ctxt/bindir.o ctxt/ctxt.a ctxt/dlibdir.c \
	ctxt/dlibdir.o ctxt/incdir.c ctxt/incdir.o ctxt/libs_dlopen.c \
	ctxt/libs_dlopen.o ctxt/repos.c ctxt/repos.o ctxt/slibdir.c \
	ctxt/slibdir.o ctxt/version.c ctxt/version.o deinstaller \
	deinstaller.o inst-check inst-check.o inst-copy inst-copy.o inst-dir \
	inst-dir.o inst-link inst-link.o install_core.o install_error.o \
	installer installer.o instchk instchk.o insthier.o loadso-conf \
	loadso-conf.o loadso.a loadso_close.o loadso_error.o loadso_func.o \
	loadso_open.o loadso_sym.o mk-ctxt 

deinstall: deinstaller inst-check inst-copy inst-dir inst-link
	./deinstaller
deinstall-dryrun: deinstaller inst-check inst-copy inst-dir inst-link
	./deinstaller dryrun
install: installer inst-check inst-copy inst-dir inst-link postinstall
	./installer
	./postinstall

install-dryrun: installer inst-check inst-copy inst-dir inst-link
	./installer dryrun
install-check: instchk inst-check
	./instchk
tests_clean:
	(cd UNIT_TESTS && make clean)
tests:
	(cd UNIT_TESTS && make tests)
regen:
	cpj-genmk > Makefile.tmp && mv Makefile.tmp Makefile

