TOOLCHAIN=/opt/cross/arm-apple-darwin11
CC=$(TOOLCHAIN)/bin/arm-apple-darwin11-clang
CODESIGN=ldid2 -S
SYSROOT=$(TOOLCHAIN)/SDK/iPhoneOS11.2.sdk
CFLAGS=-arch arm64 -isysroot $(SYSROOT) -miphoneos-version-min=12.0 -Wall

all: rtc unicopy conslog

rtc: rtc.c rtc-op.S
	$(CC) -o$@ $(CFLAGS) $^
	$(CODESIGN) $@

unicopy: unicopy.c unicopy-op.S
	$(CC) -o$@ $(CFLAGS) $^
	$(CODESIGN) $@

conslog: conslog.c conslog-op.S
	$(CC) -o$@ $(CFLAGS) $^
	$(CODESIGN) $@

clean:
	rm -f rtc unicopy conslog
