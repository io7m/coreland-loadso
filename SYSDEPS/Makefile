default: sysdeps
clean: sysdeps_clean

sysdeps:  sd_sd-dlopen
sysdeps_clean:  sd_sd-dlopen_clean

sd_sd-dlopen:
	@(cd modules/sd-dlopen && ./run)
sd_sd-dlopen_clean:
	@(cd modules/sd-dlopen && ./clean)

regen:
	./gen-makefile > Makefile.tmp
	mv Makefile.tmp Makefile
