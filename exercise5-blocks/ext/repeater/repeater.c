#include <ruby.h>

/* TODO: implement repeat — yields the index to the block n times.
 *   for (int i = 0; i < NUM2INT(n); i++) {
 *     rb_yield(INT2NUM(i));
 *   }
 *   return Qnil;
 */
static VALUE repeater_repeat(VALUE self, VALUE n) {
    return Qnil;
}

/* TODO: implement transform — yields value to the block once, returns the result.
 *   return rb_yield(value);
 *   (rb_yield raises LocalJumpError automatically if no block is given)
 */
static VALUE repeater_transform(VALUE self, VALUE value) {
    return Qnil;
}

/* TODO: implement stringify — calls .to_s on value from C and returns the result.
 *   return rb_funcall(value, rb_intern("to_s"), 0);
 *   the third argument to rb_funcall is the number of additional arguments (0 here).
 */
static VALUE repeater_stringify(VALUE self, VALUE value) {
    return Qnil;
}

void Init_repeater(void) {
    VALUE mRepeater = rb_define_module("Repeater");
    rb_define_module_function(mRepeater, "repeat",    repeater_repeat,    1);
    rb_define_module_function(mRepeater, "transform", repeater_transform, 1);
    rb_define_module_function(mRepeater, "stringify", repeater_stringify, 1);
}
