require 'ffi'
require 'minitest/autorun'

lib_name = case RUBY_PLATFORM
           when /darwin/ then 'mylib.dylib'
           else               'mylib.so'
           end
lib_path = File.expand_path("../#{lib_name}", __FILE__)

module MyLib
  extend FFI::Library
end

MyLib.ffi_lib lib_path
MyLib.attach_function :hello_world, [], :void
MyLib.attach_function :add, [:int, :int], :int

class TestFFI < Minitest::Test
  def test_hello_world_does_not_raise
    assert_nil MyLib.hello_world
  end

  def test_add_returns_correct_sum
    assert_equal 7, MyLib.add(3, 4)
  end

  def test_add_with_negative
    assert_equal 1, MyLib.add(3, -2)
  end
end
