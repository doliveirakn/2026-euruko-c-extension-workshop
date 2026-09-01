require 'minitest/autorun'
require_relative '../lib/safemath'

class TestSafeMath < Minitest::Test
  def test_divide_returns_correct_result
    assert_in_delta 2.5, SafeMath.divide(5, 2), 0.0001
  end

  def test_divide_raises_on_zero
    assert_raises(SafeMath::DivisionByZeroError) { SafeMath.divide(5, 0) }
  end

  def test_division_by_zero_error_is_zero_div_error
    assert SafeMath::DivisionByZeroError.ancestors.include?(ZeroDivisionError)
  end
end

class TestPoint < Minitest::Test
  def test_stores_coordinates
    p = Point.new(3.0, 4.0)
    assert_in_delta 3.0, p.x, 0.0001
    assert_in_delta 4.0, p.y, 0.0001
  end

  def test_distance_from_origin
    p = Point.new(3.0, 4.0)
    assert_in_delta 5.0, p.distance_from_origin, 0.0001
  end

  def test_unit_point
    p = Point.new(1.0, 0.0)
    assert_in_delta 1.0, p.distance_from_origin, 0.0001
  end
end
