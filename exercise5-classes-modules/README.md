# Exercise 5: Classes, Modules, and Inheritance in C

## Goal

Learn to define Ruby modules, classes with inheritance, instance methods, and class (singleton) methods from C.

## What to build

A `Geometry` module containing three types:

- `Geometry::Shape` — the base class (no methods to implement; serves as the superclass)
- `Geometry::Circle < Shape` — represents a circle, stores `@radius`
- `Geometry::Rectangle < Shape` — represents a rectangle, stores `@width` and `@height`
- `Geometry::Measurable` — a module included in both `Circle` and `Rectangle`

## Methods to implement

- `Geometry::Circle.new(radius)` — stores radius as `@radius`
- `Geometry::Circle#area` — returns `π * r²` as a Float
- `Geometry::Circle#circumference` — returns `2 * π * r` as a Float
- `Geometry::Rectangle.new(width, height)` — stores `@width` and `@height`
- `Geometry::Rectangle#area` — returns `width * height` as a Float
- `Geometry::Rectangle#perimeter` — returns `2 * (width + height)` as a Float
- `Geometry::Measurable#larger_than?(other)` — returns `true` if `self.area > other.area`

## C API reference

| Task                        | C call                                                            |
| --------------------------- | ----------------------------------------------------------------- |
| Define top-level module     | `rb_define_module("ModuleName")`                                  |
| Define class under module   | `rb_define_class_under(mParent, "ClassName", cSuperclass)`        |
| Instance method             | `rb_define_method(klass, "method_name", c_func, arity)`           |
| Class (singleton) method    | `rb_define_singleton_method(klass, "method_name", c_func, arity)` |
| Store ivar                  | `rb_iv_set(self, "@ivar_name", value)`                            |
| Read ivar                   | `VALUE val = rb_iv_get(self, "@ivar_name")`                       |
| Float conversion            | `double d = NUM2DBL(val)` / `VALUE v = DBL2NUM(d)`                |
| Create instance from C      | `rb_class_new_instance(argc, argv, klass)`                        |
| Include a module in a class | `rb_include_module(klass, mModule)`                               |
| Call a Ruby method from C   | `rb_funcall(obj, rb_intern("method"), nargs)`                     |

> **Note on instance variables:** We're using `rb_iv_set` and `rb_iv_get` to store values on instances — Exercise 3 covered this.

> **Note on class methods:** The C function for a class method receives the class VALUE as its first argument (named `klass` by convention, not `self`).

## Compile

```
cd ext/geometry && ruby extconf.rb && make
```

## Test

```
ruby -Ilib test/test_geometry.rb
```

Run from the exercise root.
