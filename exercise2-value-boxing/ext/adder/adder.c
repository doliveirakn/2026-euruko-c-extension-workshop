#include <ruby.h>

/*
  This function is adding 3 + 4. The answer is 7 right?
  But it isn't. See the test in test/test_adder.rb for more details.
*/
static VALUE wrong_add(VALUE self)
{
    return 3 + 4;
}

/* TODO: implement this correctly.
 *   1. convert a to a C int
 *   2. convert b to a C int
 *   3. add them:
 *   4. convert back to a Ruby VALUE and return the result
 */
static VALUE add(VALUE self, VALUE a, VALUE b)
{
    return Qnil;
}

void Init_adder(void)
{
    VALUE mAdder = rb_define_module("Adder");
    rb_define_module_function(mAdder, "wrong_add", wrong_add, 0);
    rb_define_module_function(mAdder, "add", add, 2);
}
