# Exercise 4 — Instance Variables

## Goal

Understand how to persist state on Ruby objects from C using `rb_iv_get` and `rb_iv_set`. See `TypedData_Make_Struct` as the idiomatic approach for complex C structs.

## What to Build

A `Counter` class with:

- `Counter.new(start = 0)` — optional starting value; stores both `@start` (the initial value) and `@value` (the current count)
- `counter.increment` — adds 1 to `@value`, returns `self`
- `counter.decrement` — subtracts 1 from `@value`, returns `self`
- `counter.reset` — resets `@value` back to `@start`, returns `self`
- `counter.value` — returns the current integer value

## Key API

- `rb_iv_set(self, "@name", value)` — the `@` prefix is required
- `rb_iv_get(self, "@name")` — returns `Qnil` if not set
- `NIL_P(val)` — true if a VALUE is nil
- `rb_scan_args(argc, argv, "01", &start)` — parses optional arguments; `"01"` means 0 required, 1 optional
- When a method uses variable arity, its C signature is: `static VALUE fn(int argc, VALUE *argv, VALUE self)`
- Methods registered with `-1` arity use this variable-arity signature

## TypedData Aside

For real-world extensions managing complex C structs, `TypedData_Make_Struct` and `TypedData_Get_Struct` are the idiomatic approach (they integrate with the GC and handle memory correctly). This exercise uses `rb_iv_get`/`rb_iv_set` to keep things accessible, but the pattern is worth knowing. Brief read-only reference:

```c
// Define a C struct
typedef struct { int value; int start; } counter_data_t;

// Define a type descriptor telling Ruby how to free the struct
static const rb_data_type_t counter_type = {
    "Counter",
    { 0, RUBY_DEFAULT_FREE, 0 },
    0, 0, RUBY_TYPED_FREE_IMMEDIATELY
};

// Allocate: called by Ruby when Counter.new is invoked
static VALUE counter_alloc(VALUE klass) {
    counter_data_t *data;
    return TypedData_Make_Struct(klass, counter_data_t, &counter_type, data);
}

// Access in methods:
counter_data_t *data;
TypedData_Get_Struct(self, counter_data_t, &counter_type, data);
data->value += 1;
```

## Compile

```
cd ext/counter && ruby extconf.rb && make
```

## Test

```
ruby -Ilib test/test_counter.rb
```

Run from the exercise root (`exercise4-instance-variables/`).
