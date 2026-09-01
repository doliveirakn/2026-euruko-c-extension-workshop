# Exercise 6 — Exceptions and Memory Management

## Goal

Learn to raise Ruby exceptions from C, define custom exception classes, and use `TypedData_Make_Struct` to safely attach C memory to Ruby objects.

## Two topics covered

### Part 1 — Exceptions

A `SafeMath` module with a `divide(a, b)` method that raises a custom `SafeMath::DivisionByZeroError` when `b` is zero.

### Part 2 — Memory management

A `Point` class that stores `x` and `y` as a C struct, demonstrating `TypedData_Make_Struct` / `TypedData_Get_Struct` and the GC free callback.

## Methods to implement

- `SafeMath.divide(a, b)` — returns `a / b` as a Float; raises `SafeMath::DivisionByZeroError` if `b == 0`
- `SafeMath::DivisionByZeroError` — custom exception class inheriting from `ZeroDivisionError`
- `Point.new(x, y)` — stores x, y in a C struct via TypedData
- `Point#x` — returns the x coordinate as a Float
- `Point#y` — returns the y coordinate as a Float
- `Point#distance_from_origin` — returns `sqrt(x² + y²)` as a Float

## Why TypedData?

When you allocate a C struct with `malloc` (or Ruby's `xmalloc`), that memory lives outside the Ruby heap. Ruby's GC knows nothing about it. If you store only the Ruby wrapper object, the GC will collect the wrapper when it goes out of scope — but the C struct stays in memory forever. That is a memory leak.

`rb_iv_set`/`rb_iv_get` (used in earlier exercises) can only store Ruby `VALUE` objects, not raw C pointers. You cannot use instance variables to hold a `point_t *`.

`TypedData_Make_Struct` solves both problems: it wraps the C pointer inside the Ruby object and registers a `free` callback (`point_free` in this exercise). When the GC collects the Ruby object, it automatically calls your free function, releasing the C struct. This is the idiomatic, GC-safe way to attach C data to Ruby objects.

## Key API

| Task | C call |
|------|--------|
| Raise exception | `rb_raise(rb_eArgError, "message")` |
| Define custom exception | `rb_define_class_under(mod, "ErrorName", rb_eZeroDivError)` |
| Register alloc function | `rb_define_alloc_func(klass, alloc_func)` |
| Allocate struct + wrap | `TypedData_Make_Struct(klass, type_t, &type_desc, ptr)` |
| Unwrap struct in method | `TypedData_Get_Struct(self, type_t, &type_desc, ptr)` |
| GC-safe free | `xfree(ptr)` |

## Compile

```sh
cd ext/safemath && ruby extconf.rb && make
```

Note: this exercise compiles one extension (`safemath`) that defines both `SafeMath` and `Point`.

## Test

```sh
ruby -Ilib test/test_exceptions.rb
```

Run from the exercise root (`exercise6-exceptions/`).
