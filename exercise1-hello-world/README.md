# Exercise 1: Hello World / Initial Setup

## Goal

Understand the full Ruby C extension compile cycle — write `extconf.rb`, generate a Makefile, compile the extension, require it from Ruby, and verify it with tests.

## What's Provided

- `ext/hello/hello.c` — skeleton with stubs for the function and `Init_hello`
- `lib/hello.rb` — requires the compiled extension
- `test/test_hello.rb` — minitest suite

## What You Need to Create

- `ext/hello/extconf.rb`

## Steps

1. Create `ext/hello/extconf.rb` (see Hints below for what goes in it)
2. From inside `ext/hello/`, run `ruby extconf.rb` — this generates a `Makefile`
3. Run `make` to compile the extension into a shared library
4. Open `ext/hello/hello.c` and implement the `hello_world` function body and the `Init_hello` registration
5. Recompile with `make` after editing the C file
6. Run the tests from the exercise root: `ruby -Ilib test/test_hello.rb`

## Key Concepts

- `mkmf` is a Ruby standard library for generating Makefiles that know how to compile Ruby C extensions
- `create_makefile('hello/hello')` tells mkmf to name the shared library `hello` and place it under `ext/hello/` — this path also determines the `Init_` function name Ruby expects
- `Init_hello` is the entry point Ruby calls automatically when the extension is loaded via `require`
- The argument count passed to `rb_define_module_function` tells Ruby how many arguments the Ruby method accepts (not counting `self`)

## Hints

- `extconf.rb` needs two lines: `require 'mkmf'` and `create_makefile('hello/hello')`
- `rb_str_new_cstr("your string")` creates a Ruby String from a null-terminated C string
- `rb_define_module("Hello")` creates and returns a Ruby module named `Hello`
- `rb_define_module_function(mod, "hello_world", hello_world, 0)` registers `hello_world` as a module function with 0 arguments
