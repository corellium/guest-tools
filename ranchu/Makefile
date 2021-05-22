#
#
# This file contains confidential information of Corellium LLC.
# Unauthorized reproduction or distribution of this file is subject
# to civil and criminal penalties.
#
# Copyright (C) 2021 Corellium LLC
# All rights reserved.
#
#

-include Makefile.local

ASFLAGS  ?=
CFLAGS   ?= -O2 -Wall -Wcast-qual -Wextra -Wpointer-arith -Wshadow -Wstrict-prototypes
LDFLAGS  ?=

.PHONY: all
all: rtc unicopy conslog

.PHONY: clean
clean:
	/bin/rm rtc unicopy conslog rtc.o rtc-op.o unicopy.o unicopy-op.o conslog.o conslog-op.o

rtc: rtc.o rtc-op.o
unicopy: unicopy.o unicopy-op.o
conslog: conslog.o conslog-op.o
