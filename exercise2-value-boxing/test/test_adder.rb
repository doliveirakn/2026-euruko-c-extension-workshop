require 'minitest/autorun'
require_relative '../lib/adder'

class TestAdder < Minitest::Test
  def test_wrong_add_does_not_return_correct_sum
    result = Adder.wrong_add(3, 4)
    refute_equal 7, result, "wrong_add intentionally returns an incorrect result — this is the bug being demonstrated"
  end

  def test_add_returns_correct_sum
    assert_equal 7, Adder.add(3, 4)
  end

  def test_add_with_zero
    assert_equal 5, Adder.add(5, 0)
  end

  def test_add_negative_numbers
    assert_equal 1, Adder.add(3, -2)
  end

  def test_add_raises_on_wrong_type
    assert_raises(TypeError) { Adder.add("3", 4) }
  end
end
