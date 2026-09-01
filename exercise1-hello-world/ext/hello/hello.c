#include <ruby.h>

/* TODO: implement this function.
 *   it should return a Ruby String containing "Hello World".
 *   hint: rb_str_new_cstr("Hello World") creates a Ruby String from a C string.
 */
static VALUE hello_world(VALUE self) {
    return Qnil;
}

void Init_hello(void) {
    /* TODO: create the Hello module and register hello_world on it.
     *   1. VALUE mod = rb_define_module("Hello");
     *   2. rb_define_module_function(mod, "hello_world", hello_world, 0);
     *      the last argument is the arity — 0 means the method takes no arguments.
     */
}
