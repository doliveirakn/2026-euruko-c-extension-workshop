require 'minitest/autorun'
require_relative '../lib/hello'

class TestHello < Minitest::Test
  def test_hello_world_returns_correct_string
    assert_equal "Hello World", Hello.hello_world
  end

  def test_hello_world_returns_a_string
    assert_kind_of String, Hello.hello_world
  end
end
