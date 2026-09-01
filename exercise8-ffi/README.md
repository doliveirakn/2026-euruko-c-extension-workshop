# Exercise 5 — Ruby FFI

## Goal

Call C code from Ruby _without_ writing any Ruby C API code — using the `ffi` gem and a plain shared library.

## Two Approaches Compared

- **Exercises 1–4**: C code includes `ruby.h`, uses `VALUE` types, defines `Init_`, compiles into a `.bundle`/`.so` that Ruby treats as a native extension.
- **Exercise 5**: C code is a plain C library — no `ruby.h`, no `VALUE`, no `Init_`. The `ffi` gem uses `libffi` to call its functions at runtime. No Ruby-specific compilation.

## What's Provided

`mylib.c` — the C source; no Makefile (writing one is part of this exercise).

## Steps

1. Open `mylib.c` — note: no `#include <ruby.h>`, no `VALUE`, no `Init_` function
2. Write a `Makefile` to compile `mylib.c` as a shared library (`.dylib` on macOS, `.so` on Linux) — see Makefile instructions below
3. Run `make` from the `exercise5-ffi/` directory
4. Write the FFI bindings in `runner.rb` — see FFI instructions below
5. Run `ruby runner.rb`

## Writing the Makefile

The key compiler flags differ by platform:

- macOS (Clang): `cc -dynamiclib -o mylib.dylib mylib.c`
- Linux (GCC): `gcc -shared -fPIC -o mylib.so mylib.c`

A platform-detecting Makefile looks like this:

```makefile
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
```

**Important**: the recipe line (the `$(CC)` line under `$(LIB): mylib.c`) MUST be indented with a TAB character, not spaces. This is a Makefile requirement.

## FFI Bindings

The `ffi` gem API:

- `extend FFI::Library` — adds FFI class methods to your module
- `ffi_lib 'path/to/lib'` — loads the shared library
- `attach_function :c_function_name, [arg_types], return_type` — declares a binding
- Common types: `:int`, `:void`, `:string`, `:double`

Example:

```ruby
require 'ffi'

module MyLib
  extend FFI::Library
  ffi_lib File.expand_path('../mylib.dylib', __FILE__)  # adjust extension for Linux
  attach_function :hello_world, [], :void
  attach_function :add, [:int, :int], :int
end

MyLib.hello_world
puts MyLib.add(3, 4)
```

## When to Use Each Approach

- **Native C extension** (Exercises 1–4): more control, GC integration, and maximum performance
- **FFI** (this exercise): simpler, requires no Ruby-specific compilation, excellent for wrapping existing C libraries
