# Exercise 3: Classes, Modules, and Inheritance in C

## Goal

Learn to define Ruby modules, classes with inheritance, instance methods, and class (singleton) methods from C.

## What to build

A `Geometry` module containing three types:

- `Geometry::Shape` — the base class (no methods to implement; serves as the superclass)
- `Geometry::Circle < Shape` — represents a circle, stores `@radius`
- `Geometry::Rectangle < Shape` — represents a rectangle, stores `@width` and `@height`

## Methods to implement

- `Geometry::Circle.new(radius)` — stores radius as `@radius`
- `Geometry::Circle#area` — returns `π * r²` as a Float
- `Geometry::Circle#circumference` — returns `2 * π * r` as a Float
- `Geometry::Circle.unit_circle` — class method, returns a new `Circle` with radius `1.0`
- `Geometry::Rectangle.new(width, height)` — stores `@width` and `@height`
- `Geometry::Rectangle#area` — returns `width * height` as a Float
- `Geometry::Rectangle#perimeter` — returns `2 * (width + height)` as a Float
- `Geometry::Rectangle.square(side)` — class method, returns a new `Rectangle` with `width == height == side`

## C API reference

| Task | C call |
|------|--------|
| Define top-level module | `rb_define_module("Geometry")` |
| Define class under module | `rb_define_class_under(mGeometry, "Circle", cShape)` |
| Instance method | `rb_define_method(cCircle, "area", circle_area, 0)` |
| Class (singleton) method | `rb_define_singleton_method(cCircle, "unit_circle", circle_unit_circle, 0)` |
| Store ivar | `rb_iv_set(self, "@radius", value)` |
| Read ivar | `VALUE r = rb_iv_get(self, "@radius")` |
| Float conversion | `double d = NUM2DBL(val)` / `VALUE v = DBL2NUM(d)` |
| Create instance from C | `rb_class_new_instance(1, (VALUE[]){ arg }, klass)` |

> **Note on instance variables:** We're using `rb_iv_set` and `rb_iv_get` to store values on instances — Exercise 4 covers this in depth.

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
