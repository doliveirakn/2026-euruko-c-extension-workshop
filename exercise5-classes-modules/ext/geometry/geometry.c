#include <ruby.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static VALUE mGeometry;
static VALUE cShape;
static VALUE cCircle;
static VALUE cRectangle;
static VALUE mMeasurable;

static VALUE circle_initialize(VALUE self, VALUE radius)
{
    // TODO: store the radius as an instance variable.
    return self;
}

static VALUE circle_area(VALUE self)
{
    // TODO: compute and return pi * r^2 as a Ruby Float.
    return DBL2NUM(0.0);
}

static VALUE circle_circumference(VALUE self)
{
    /* TODO: compute and return 2 * pi * r as a Ruby Float.
     *   hint: same pattern as circle_area above.
     */
    return DBL2NUM(0.0);
}

/*
 * Class method — note: first argument is klass (the Circle class), not self.
 *  return a new Circle with radius 1.0.
 */
static VALUE circle_unit_circle(VALUE klass)
{
    return rb_class_new_instance(1, (VALUE[]){DBL2NUM(1.0)}, klass);
}

static VALUE rectangle_initialize(VALUE self, VALUE width, VALUE height)
{
    // TODO: store width as @width and height as @height.
    return Qnil;
}

static VALUE rectangle_area(VALUE self)
{
    // TODO: return width * height as a Ruby Float.
    return DBL2NUM(0.0);
}

static VALUE rectangle_perimeter(VALUE self)
{
    // TODO: return 2 * (width + height) as a Ruby Float.
    return DBL2NUM(0.0);
}

/*
 * Class method — first argument is klass (the Rectangle class).
 *   return a new Rectangle where width == height == side.
 */
static VALUE rectangle_square(VALUE klass, VALUE side)
{
    return rb_class_new_instance(2, (VALUE[]){side, side}, klass);
}

static VALUE measurable_larger_than(VALUE self, VALUE other)
{
    // TODO: compare the area of self and other.
    //  return Qtrue if self's area is larger than other's area, otherwise return Qfalse.
    return Qnil;
}

void Init_geometry(void)
{
    // TODO: Define the geometry module and then define the Shape class under it.
    // TODO: then define a module wiht the larger_than method
    // TODO: define Circle and Rectangle under the Geometry module and register their methods.
    // TODO: Then include the Measurable module in both Circle and Rectangle.
}
