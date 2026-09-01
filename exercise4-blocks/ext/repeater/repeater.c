#include <ruby.h>

static VALUE repeater_repeat(VALUE self, VALUE n)
{
    // TODO: implement repeat — yields the index to the block n times.
    // Bonus: If no block is given, return an enumerator.
    //        There are no tests for this, but you can play with it.
    return Qnil;
}

static VALUE repeater_transform(VALUE self, VALUE value)
{
    // TODO: implement transform — yields value to the block once, returns the result.
    return Qnil;
}

static VALUE repeater_stringify(VALUE self, VALUE value)
{
    // TODO: implement stringify — calls .to_s on value from C and returns the result.
    return Qnil;
}

void Init_repeater(void)
{
    VALUE mRepeater = rb_define_module("Repeater");
    rb_define_module_function(mRepeater, "repeat", repeater_repeat, 1);
    rb_define_module_function(mRepeater, "transform", repeater_transform, 1);
    rb_define_module_function(mRepeater, "stringify", repeater_stringify, 1);
}
