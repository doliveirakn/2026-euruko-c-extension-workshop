UNAME := $(shell uname -s)

ifeq ($(UNAME),Darwin)
    LIB     = mylib.dylib
    LDFLAGS = -dynamiclib
    CFLAGS  =
else
    LIB     = mylib.so
    LDFLAGS = -shared
    CFLAGS  = -fPIC
endif

all: $(LIB)

$(LIB): mylib.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(LIB) mylib.c

clean:
	rm -f mylib.dylib mylib.so
