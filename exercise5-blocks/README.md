# Exercise 5: Blocks and Calling Ruby Methods from C

## Goal

Learn to write C extension methods that accept blocks (`rb_yield`) and call Ruby methods from C (`rb_funcall`).

## What to build

A `Repeater` module with three methods:

- `Repeater.repeat(n) { |i| ... }` — yields the index (0-based) to the block `n` times; returns `nil`
- `Repeater.transform(value) { |v| ... }` — yields `value` to the block once, returns what the block returns; raises `LocalJumpError` if no block given (this happens automatically when you call `rb_yield` with no block)
- `Repeater.stringify(value)` — calls `.to_s` on `value` from C using `rb_funcall`, returns the result — demonstrates calling a Ruby method from C without a block

## What's provided

- `ext/repeater/extconf.rb` — build configuration
- `ext/repeater/repeater.c` — stub implementations (fill these in)
- `lib/repeater.rb` — requires the compiled extension
- `test/test_repeater.rb` — tests to verify your implementation

## C API reference

| Task | C call |
|------|--------|
| Check if block given | `rb_block_given_p()` |
| Yield value to block | `result = rb_yield(value)` |
| Yield with no value | `rb_yield(Qnil)` |
| Capture block as Proc | `VALUE proc = rb_block_proc()` |
| Call Ruby method | `rb_funcall(obj, rb_intern("name"), nargs, ...)` |

**Note:** `rb_yield` raises `LocalJumpError` automatically if called when no block was given — you don't need to check `rb_block_given_p()` first unless you want different behavior when no block is present.

## Compile

```
cd ext/repeater && ruby extconf.rb && make
```

## Test

Run from the exercise root:

```
ruby -Ilib test/test_repeater.rb
```
