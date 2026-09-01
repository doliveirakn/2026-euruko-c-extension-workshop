#include <ruby.h>

/* TODO: implement this function.
 *   it should return a Ruby String containing "Hello World".
 */
static VALUE hello_world(VALUE self)
{
    return Qnil;
}

void Init_hello(void)
{
    // creates and returns a Ruby module named `Hello`
    VALUE mod = rb_define_module("Hello");
    // registers `hello_world` as a module function using the given C function with 0 arguments
    rb_define_module_function(mod, "hello_world", hello_world, 0);
}
