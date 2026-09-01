#include <ruby.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static VALUE mGeometry;
static VALUE cShape;
static VALUE cCircle;
static VALUE cRectangle;

static VALUE circle_initialize(VALUE self, VALUE radius) {
    /* TODO: store the radius as an instance variable.
     *   rb_iv_set(self, "@radius", radius);
     *   return self;
     */
    return self;
}

static VALUE circle_area(VALUE self) {
    /* TODO: compute and return pi * r^2 as a Ruby Float.
     *   double r = NUM2DBL(rb_iv_get(self, "@radius"));
     *   return DBL2NUM(M_PI * r * r);
     */
    return DBL2NUM(0.0);
}

static VALUE circle_circumference(VALUE self) {
    /* TODO: compute and return 2 * pi * r as a Ruby Float.
     *   hint: same pattern as circle_area above.
     */
    return DBL2NUM(0.0);
}

/*
 * Class method — note: first argument is klass (the Circle class), not self.
 * TODO: return a new Circle with radius 1.0.
 *   rb_class_new_instance(1, (VALUE[]){ DBL2NUM(1.0) }, klass)
 */
static VALUE circle_unit_circle(VALUE klass) {
    return Qnil;
}

static VALUE rectangle_initialize(VALUE self, VALUE width, VALUE height) {
    /* TODO: store width as @width and height as @height.
     *   rb_iv_set(self, "@width", width);
     *   rb_iv_set(self, "@height", height);
     *   return self;
     */
    return self;
}

static VALUE rectangle_area(VALUE self) {
    /* TODO: return width * height as a Ruby Float.
     *   double w = NUM2DBL(rb_iv_get(self, "@width"));
     *   double h = NUM2DBL(rb_iv_get(self, "@height"));
     *   return DBL2NUM(w * h);
     */
    return DBL2NUM(0.0);
}

static VALUE rectangle_perimeter(VALUE self) {
    /* TODO: return 2 * (width + height) as a Ruby Float.
     */
    return DBL2NUM(0.0);
}

/*
 * Class method — first argument is klass (the Rectangle class).
 * TODO: return a new Rectangle where width == height == side.
 *   rb_class_new_instance(2, (VALUE[]){ side, side }, klass)
 */
static VALUE rectangle_square(VALUE klass, VALUE side) {
    return Qnil;
}

void Init_geometry(void) {
    mGeometry = rb_define_module("Geometry");
    cShape = rb_define_class_under(mGeometry, "Shape", rb_cObject);

    /* TODO: define Circle and Rectangle under the Geometry module and register their methods.
     *
     * Pattern for Circle:
     *   cCircle = rb_define_class_under(mGeometry, "Circle", cShape);
     *   rb_define_method(cCircle, "initialize", circle_initialize, 1);
     *   rb_define_method(cCircle, "area", circle_area, 0);
     *   rb_define_method(cCircle, "circumference", circle_circumference, 0);
     *   rb_define_singleton_method(cCircle, "unit_circle", circle_unit_circle, 0);
     *
     * Do the same for Rectangle — initialize takes 2 args, square class method takes 1.
     */
}
