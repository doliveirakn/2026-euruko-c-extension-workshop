#include <ruby.h>
#include <math.h>

static VALUE eDivisionByZeroError;

/* ---- SafeMath ---- */

/* TODO: implement divide — returns a / b as a Float; raises DivisionByZeroError if b == 0.
 *   if (NUM2DBL(b) == 0.0) {
 *     rb_raise(eDivisionByZeroError, "divided by 0");
 *   }
 *   return DBL2NUM(NUM2DBL(a) / NUM2DBL(b));
 *
 *   where eDivisionByZeroError is the custom exception class VALUE (declared at file scope above).
 */
static VALUE safemath_divide(VALUE self, VALUE a, VALUE b) {
    return Qnil;
}

/* ---- Point (TypedData) ---- */

typedef struct {
    double x;
    double y;
} point_t;

static void point_free(void *ptr) {
    xfree(ptr);
}

static const rb_data_type_t point_type = {
    "Point",
    { 0, point_free, 0 },
    0, 0, RUBY_TYPED_FREE_IMMEDIATELY
};

static VALUE point_alloc(VALUE klass) {
    point_t *p;
    return TypedData_Make_Struct(klass, point_t, &point_type, p);
}

/* TODO: store x and y in the C struct.
 *   point_t *p;
 *   TypedData_Get_Struct(self, point_t, &point_type, p);
 *   p->x = NUM2DBL(x);
 *   p->y = NUM2DBL(y);
 *   return self;
 */
static VALUE point_initialize(VALUE self, VALUE x, VALUE y) {
    return self;
}

/* TODO: return the x coordinate.
 *   point_t *p;
 *   TypedData_Get_Struct(self, point_t, &point_type, p);
 *   return DBL2NUM(p->x);
 */
static VALUE point_x(VALUE self) {
    return DBL2NUM(0.0);
}

/* TODO: return the y coordinate (same pattern as point_x). */
static VALUE point_y(VALUE self) {
    return DBL2NUM(0.0);
}

/* TODO: return sqrt(x*x + y*y) as a Float.
 *   use sqrt() from math.h and DBL2NUM to convert.
 */
static VALUE point_distance_from_origin(VALUE self) {
    return DBL2NUM(0.0);
}

void Init_safemath(void) {
    VALUE mSafeMath = rb_define_module("SafeMath");

    /* Define the custom exception class under SafeMath, inheriting from ZeroDivisionError */
    eDivisionByZeroError = rb_define_class_under(mSafeMath, "DivisionByZeroError", rb_eZeroDivError);

    rb_define_module_function(mSafeMath, "divide", safemath_divide, 2);

    VALUE cPoint = rb_define_class("Point", rb_cObject);
    rb_define_alloc_func(cPoint, point_alloc);
    rb_define_method(cPoint, "initialize",           point_initialize,          2);
    rb_define_method(cPoint, "x",                    point_x,                   0);
    rb_define_method(cPoint, "y",                    point_y,                   0);
    rb_define_method(cPoint, "distance_from_origin", point_distance_from_origin, 0);
}
