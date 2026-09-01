#include <ruby.h>

/*
 * WRONG IMPLEMENTATION — do not copy this pattern.
 *
 * VALUE is not a plain integer. For Fixnums, Ruby encodes the integer n
 * as (n << 1) | 1, so the VALUE for integer 3 is internally 7.
 * Adding two VALUEs adds their raw tagged bit patterns, not the integers
 * they represent.
 *
 * Try Adder.wrong_add(3, 4) — it will not return 7.
 */
static VALUE wrong_add(VALUE self, VALUE a, VALUE b) {
    return a + b;
}

/* TODO: implement this correctly.
 *   1. convert a to a C int: int x = NUM2INT(a);
 *   2. convert b to a C int: int y = NUM2INT(b);
 *   3. add them:             int sum = x + y;
 *   4. convert back:         return INT2NUM(sum);
 */
static VALUE add(VALUE self, VALUE a, VALUE b) {
    return Qnil;
}

void Init_adder(void) {
    VALUE mAdder = rb_define_module("Adder");
    rb_define_module_function(mAdder, "wrong_add", wrong_add, 2);
    rb_define_module_function(mAdder, "add", add, 2);
}
