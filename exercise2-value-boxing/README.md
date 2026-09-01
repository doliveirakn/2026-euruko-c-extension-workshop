# Exercise 2 — Value Boxing

## Goal

Understand why Ruby's `VALUE` type cannot be used as a plain C integer, and how to use conversion macros correctly.

## Background

In Ruby's C implementation, `VALUE` is defined as `uintptr_t`. For Fixnum integers, the integer `n` is stored internally as `(n << 1) | 1` — meaning the `VALUE` representing integer 3 is actually the bit pattern 7. Doing direct arithmetic (`a + b`) on two `VALUE`s adds their raw tagged representations, not the Ruby integers they represent.

## What's Provided

- `ext/adder/extconf.rb` — build configuration
- `ext/adder/adder.c` — contains a deliberately broken `wrong_add` and a stub for `add`
- `lib/adder.rb` — requires the compiled extension
- `test/test_adder.rb` — tests that demonstrate the bug and verify the fix

## Steps

1. `cd ext/adder && ruby extconf.rb && make`
2. From the exercise root, run `ruby -Ilib test/test_adder.rb` — observe that `wrong_add` produces incorrect results
3. Implement `add` in `adder.c` using the correct conversion macros
4. Recompile (`make` from `ext/adder/`) and run tests again — they should pass

## Conversion Macro Reference

| Ruby type | C type | VALUE → C  | C → VALUE  |
|-----------|--------|------------|------------|
| Integer   | int    | `NUM2INT`  | `INT2NUM`  |
| Integer   | long   | `NUM2LONG` | `LONG2NUM` |
| Float     | double | `NUM2DBL`  | `DBL2NUM`  |

**Note:** `NUM2INT` raises a `TypeError` if the argument is not numeric — this is the correct behavior; don't work around it.

## Hints

The fix for `add` is three lines — convert `a` with `NUM2INT`, convert `b` with `NUM2INT`, add them as C ints, return the result with `INT2NUM`.
