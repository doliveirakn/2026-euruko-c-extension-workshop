require 'minitest/autorun'
require_relative '../lib/counter'

class TestCounter < Minitest::Test
  def test_default_value_is_zero
    assert_equal 0, Counter.new.value
  end

  def test_custom_start_value
    assert_equal 10, Counter.new(10).value
  end

  def test_increment
    c = Counter.new
    c.increment
    assert_equal 1, c.value
  end

  def test_increment_multiple_times
    c = Counter.new
    c.increment.increment.increment
    assert_equal 3, c.value
  end

  def test_decrement
    c = Counter.new(5)
    c.decrement
    assert_equal 4, c.value
  end

  def test_reset_to_zero
    c = Counter.new
    c.increment.increment
    c.reset
    assert_equal 0, c.value
  end

  def test_reset_to_custom_start
    c = Counter.new(7)
    c.increment.increment
    c.reset
    assert_equal 7, c.value
  end

  def test_increment_returns_self
    c = Counter.new
    assert_same c, c.increment
  end
end
