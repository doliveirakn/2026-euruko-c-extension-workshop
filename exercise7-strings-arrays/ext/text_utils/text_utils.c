#include <ruby.h>
#include <string.h>

static VALUE text_utils_reverse_string(VALUE self, VALUE str)
{
    // TODO: reverse the characters of str and return a new Ruby String.
    return Qnil;
}

static VALUE text_utils_join_with(VALUE self, VALUE array, VALUE separator)
{
    // TODO: join array elements into a String separated by separator.
    return Qnil;
}

static VALUE text_utils_sum_array(VALUE self, VALUE array)
{
    return Qnil;
}

void Init_text_utils(void)
{
    VALUE mTextUtils = rb_define_module("TextUtils");
    rb_define_module_function(mTextUtils, "reverse_string", text_utils_reverse_string, 1);
    rb_define_module_function(mTextUtils, "join_with", text_utils_join_with, 2);
    rb_define_module_function(mTextUtils, "sum_array", text_utils_sum_array, 1);
}
