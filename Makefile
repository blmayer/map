.PHONY: all test install clean

CFLAGS += -fPIC -O0
ifeq ($(shell uname -s),Darwin)
	LDFLAGS += -dynamiclib
	EXT = dylib
else
	LDFLAGS += -shared
	EXT = so
endif

all: *.c *.h
	$(CC) $(CFLAGS) $< -o map.$(EXT) $(LDFLAGS)

test: *.c
	$(CC) -g $^ -o $@
	./test

install: all
	install -d /usr/lib/
	install -m 644 map.$(EXT) /usr/lib/
	install -d /usr/include/
	install -m 644 map.h /usr/include/

clean:
	$(RM) test
	$(RM) map.$(EXT)