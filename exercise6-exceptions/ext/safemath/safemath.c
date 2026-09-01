#include <ruby.h>
#include <math.h>

static VALUE safemath_divide(VALUE self, VALUE a, VALUE b)
{
    // TODO: implement divide — returns a / b as a Float; raises DivisionByZeroError if b == 0.
    return Qnil;
}

/* ---- Point (TypedData) ---- */
typedef struct
{
    double x;
    double y;
} point_t;

static VALUE point_initialize(VALUE self, VALUE x, VALUE y)
{
    // TODO: store x and y in the C struct.
    return self;
}

static VALUE point_x(VALUE self)
{
    // TODO: return the x coordinate.
    return Qnil;
}

static VALUE point_y(VALUE self)
{
    // TODO: return the y coordinate (same pattern as point_x).
    return Qnil;
}

static VALUE point_distance_from_origin(VALUE self)
{
    // TODO: return sqrt(x*x + y*y) as a Float.
    // sqrt is already included from <math.h>
    return Qnil;
}

void Init_safemath(void)
{
    VALUE mSafeMath = rb_define_module("SafeMath");

    // TODO: Define the custom exception class under SafeMath, inheriting from ZeroDivisionError */
    rb_define_module_function(mSafeMath, "divide", safemath_divide, 2);

    VALUE cPoint = rb_define_class("Point", rb_cObject);
    rb_define_alloc_func(cPoint, point_alloc);
    rb_define_method(cPoint, "initialize", point_initialize, 2);
    rb_define_method(cPoint, "x", point_x, 0);
    rb_define_method(cPoint, "y", point_y, 0);
    rb_define_method(cPoint, "distance_from_origin", point_distance_from_origin, 0);
}
