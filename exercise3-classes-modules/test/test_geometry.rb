require 'minitest/autorun'
require_relative '../lib/geometry'

class TestGeometry < Minitest::Test
  def test_circle_area
    c = Geometry::Circle.new(5.0)
    assert_in_delta Math::PI * 25.0, c.area, 0.0001
  end

  def test_circle_circumference
    c = Geometry::Circle.new(5.0)
    assert_in_delta 2 * Math::PI * 5.0, c.circumference, 0.0001
  end

  def test_circle_unit_circle
    uc = Geometry::Circle.unit_circle
    assert_instance_of Geometry::Circle, uc
    assert_in_delta Math::PI, uc.area, 0.0001
  end

  def test_circle_inherits_from_shape
    assert Geometry::Circle.ancestors.include?(Geometry::Shape)
  end

  def test_rectangle_area
    r = Geometry::Rectangle.new(4.0, 6.0)
    assert_in_delta 24.0, r.area, 0.0001
  end

  def test_rectangle_perimeter
    r = Geometry::Rectangle.new(4.0, 6.0)
    assert_in_delta 20.0, r.perimeter, 0.0001
  end

  def test_rectangle_square
    sq = Geometry::Rectangle.square(3.0)
    assert_instance_of Geometry::Rectangle, sq
    assert_in_delta 9.0, sq.area, 0.0001
  end

  def test_rectangle_inherits_from_shape
    assert Geometry::Rectangle.ancestors.include?(Geometry::Shape)
  end
end
