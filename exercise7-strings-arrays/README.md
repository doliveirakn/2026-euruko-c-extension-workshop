# Exercise 7: Strings and Arrays

## Goal

Learn to create, read, and manipulate Ruby Strings and Arrays from C extension code.

## What to build

A `TextUtils` module with three methods:

- `TextUtils.reverse_string(str)` — returns a new Ruby String that is the reverse of `str`
- `TextUtils.join_with(array, separator)` — joins array elements into a String, with `separator` between each; returns the result String
- `TextUtils.sum_array(array)` — sums all integer elements in the array, returns the total as an Integer

## Key API

| Task | C call |
|------|--------|
| Get C string from Ruby String | `char *s = StringValueCStr(val)` |
| Get String length | `long len = RSTRING_LEN(val)` |
| Create Ruby String from C | `rb_str_new_cstr("...")` or `rb_str_new(buf, len)` |
| Append to Ruby String | `rb_str_cat_cstr(str, "more")` |
| Stack-allocate C buffer | `char *buf = ALLOCA_N(char, len + 1)` |
| Create empty Array | `rb_ary_new()` |
| Push onto Array | `rb_ary_push(ary, val)` |
| Get Array length | `long n = RARRAY_LEN(ary)` |
| Get element at index | `VALUE el = rb_ary_entry(ary, i)` |
| Type-check (raises TypeError) | `Check_Type(val, T_ARRAY)` |

## Compile

```
cd ext/text_utils && ruby extconf.rb && make
```

## Test

```
ruby -Ilib test/test_strings_arrays.rb
```

Run from the exercise root directory.
