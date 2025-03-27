//
// Created by linkl on 3/27/2025.
//

#include "Vector.h"

#include <iostream>

Vector Vector::clamp(const Vector& min, const Vector& max) const {
  if (min.getX() > max.getX()) {
    throw std::invalid_argument("Vector::clamp: min.getX() > max.getX()");
  }
  if (min.getY() > max.getY()) {
    throw std::invalid_argument("Vector::clamp: min.getY() > max.getY()");
  }

  const int clampedX = std::max(min.getX(), std::min(getX(), max.getX()));
  const int clampedY = std::max(min.getY(), std::min(getY(), max.getY()));

  return Vector(clampedX, clampedY);
}
