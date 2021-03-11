.PHONY: all test bench install clean

CFLAGS += -fPIC -O0 -std=c89 -pedantic
ifeq ($(shell uname -s),Darwin)
	LDFLAGS += -dynamiclib
	EXT = dylib
else
	LDFLAGS += -shared
	EXT = so
endif

all: map.c map.h
	$(CC) $(CFLAGS) $< -o libmap.$(EXT) $(LDFLAGS)

test: all test.c
	$(CC) -g test.c -o $@ -L$(shell pwd) -lmap
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(shell pwd) ./test

bench: all bench.c
	$(CC) bench.c -o $@ -L$(shell pwd) -lmap
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(shell pwd) ./bench

install: all
	install -d /usr/lib/
	install -m 644 map.$(EXT) /usr/lib/
	install -d /usr/include/
	install -m 644 map.h /usr/include/

clean:
	$(RM) test
	$(RM) map.$(EXT)