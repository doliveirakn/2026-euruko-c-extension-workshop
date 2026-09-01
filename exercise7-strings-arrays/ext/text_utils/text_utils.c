#include <ruby.h>
#include <string.h>

/* TODO: reverse the characters of str and return a new Ruby String.
 *   char *s   = StringValueCStr(str);
 *   long  len = RSTRING_LEN(str);
 *   char *buf = ALLOCA_N(char, len + 1);
 *   for (long i = 0; i < len; i++) {
 *     buf[i] = s[len - 1 - i];
 *   }
 *   buf[len] = '\0';
 *   return rb_str_new_cstr(buf);
 */
static VALUE text_utils_reverse_string(VALUE self, VALUE str) {
    return rb_str_new_cstr("");
}

/* TODO: join array elements into a String separated by separator.
 *   VALUE result = rb_str_new_cstr("");
 *   long  n      = RARRAY_LEN(array);
 *   for (long i = 0; i < n; i++) {
 *     if (i > 0) rb_str_cat_cstr(result, StringValueCStr(separator));
 *     rb_str_cat_cstr(result, StringValueCStr(rb_ary_entry(array, i)));
 *   }
 *   return result;
 */
static VALUE text_utils_join_with(VALUE self, VALUE array, VALUE separator) {
    return rb_str_new_cstr("");
}

/* TODO: sum all integer elements of array and return the total.
 *   long sum = 0;
 *   long n   = RARRAY_LEN(array);
 *   for (long i = 0; i < n; i++) {
 *     sum += NUM2LONG(rb_ary_entry(array, i));
 *   }
 *   return LONG2NUM(sum);
 */
static VALUE text_utils_sum_array(VALUE self, VALUE array) {
    return INT2NUM(0);
}

void Init_text_utils(void) {
    VALUE mTextUtils = rb_define_module("TextUtils");
    rb_define_module_function(mTextUtils, "reverse_string", text_utils_reverse_string, 1);
    rb_define_module_function(mTextUtils, "join_with",      text_utils_join_with,      2);
    rb_define_module_function(mTextUtils, "sum_array",      text_utils_sum_array,      1);
}
