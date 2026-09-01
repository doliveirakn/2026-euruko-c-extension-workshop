#include <ruby.h>

static VALUE counter_initialize(int argc, VALUE *argv, VALUE self)
{
    VALUE start;
    /*
     * rb_scan_args parses optional arguments.
     * "01" means 0 required, 1 optional.
     * If no argument is given, start is set to Qnil.
     */
    rb_scan_args(argc, argv, "01", &start);

    if (NIL_P(start))
    {
        start = INT2NUM(0);
    }

    return self;
}

static VALUE counter_value(VALUE self)
{
    // TODO: return the current count.
    return Qnil;
}

static VALUE counter_increment(VALUE self)
{
    // TODO: add 1 to @value and return self.
    return self;
}

static VALUE counter_decrement(VALUE self)
{
    // TODO: subtract 1 from @value and return self.
    return self;
}

static VALUE counter_reset(VALUE self)
{
    // TODO: reset @value back to @start and return self.
    return self;
}

void Init_counter(void)
{
    VALUE cCounter = rb_define_class("Counter", rb_cObject);
    rb_define_method(cCounter, "initialize", counter_initialize, -1);
    rb_define_method(cCounter, "value", counter_value, 0);
    rb_define_method(cCounter, "increment", counter_increment, 0);
    rb_define_method(cCounter, "decrement", counter_decrement, 0);
    rb_define_method(cCounter, "reset", counter_reset, 0);
}
