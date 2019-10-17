SRC = $(shell pwd)/miwesta/miwesta.ino
LIB_A = /usr/share/arduino/libraries/
LIB_B = $(HOME)/sketchbook/libraries/

all: upload

.PHONY: check-style
check-style:
	cpplint --extensions=ino miwesta/*
	@echo Check style completed!

.PHONY: tags
tags:
	ctags -R --c++-kinds=+p --fields=+iaS --extras=+q $(LIB_A) $(LIB_B)
	@echo Build tag completed!

.PHONY: build
build:
	arduino --verify $(SRC) --board arduino:avr:uno
	@echo Build completed!

.PHONY: build_verbose
build_verbose:
	arduino --verify --verbose-build $(SRC) --board arduino:avr:uno
	@echo Build verbose completed!

.PHONY: upload
upload:
	arduino --upload $(SRC) --board arduino:avr:uno
	@echo Upload completed!

.PHONY: upload_verbose
upload_verbose:
	arduino --upload --verbose-upload $(SRC) --board arduino:avr:uno
	@echo Upload verbose completed!
