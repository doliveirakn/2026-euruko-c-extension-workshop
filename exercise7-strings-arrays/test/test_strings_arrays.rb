require 'minitest/autorun'
require_relative '../lib/text_utils'

class TestTextUtils < Minitest::Test
  def test_reverse_string
    assert_equal "olleh", TextUtils.reverse_string("hello")
  end

  def test_reverse_string_single_char
    assert_equal "a", TextUtils.reverse_string("a")
  end

  def test_reverse_string_empty
    assert_equal "", TextUtils.reverse_string("")
  end

  def test_join_with
    assert_equal "a, b, c", TextUtils.join_with(["a", "b", "c"], ", ")
  end

  def test_join_with_single_element
    assert_equal "only", TextUtils.join_with(["only"], ", ")
  end

  def test_join_with_empty_separator
    assert_equal "abc", TextUtils.join_with(["a", "b", "c"], "")
  end

  def test_sum_array
    assert_equal 10, TextUtils.sum_array([1, 2, 3, 4])
  end

  def test_sum_array_empty
    assert_equal 0, TextUtils.sum_array([])
  end

  def test_sum_array_with_negatives
    assert_equal 1, TextUtils.sum_array([3, -2, 0, 5, -5])
  end
end
