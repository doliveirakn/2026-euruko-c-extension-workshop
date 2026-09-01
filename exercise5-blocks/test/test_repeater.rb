require 'minitest/autorun'
require_relative '../lib/repeater'

class TestRepeater < Minitest::Test
  def test_repeat_yields_correct_number_of_times
    count = 0
    Repeater.repeat(5) { count += 1 }
    assert_equal 5, count
  end

  def test_repeat_yields_correct_indices
    indices = []
    Repeater.repeat(3) { |i| indices << i }
    assert_equal [0, 1, 2], indices
  end

  def test_repeat_returns_nil
    result = Repeater.repeat(2) { }
    assert_nil result
  end

  def test_transform_returns_block_result
    result = Repeater.transform(6) { |v| v * 2 }
    assert_equal 12, result
  end

  def test_transform_raises_without_block
    assert_raises(LocalJumpError) { Repeater.transform(1) }
  end

  def test_stringify_calls_to_s
    assert_equal "42",    Repeater.stringify(42)
    assert_equal "hello", Repeater.stringify("hello")
    assert_equal "3.14",  Repeater.stringify(3.14)
  end
end
