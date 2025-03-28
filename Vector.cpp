//
// Created by linkl on 3/27/2025.
//

#include "Vector.h"

#include <iostream>

std::string Vector::direction() const {
  const float angle = atan2(y, x) * 180 / M_PI;
  if (angle > -22.5  && angle <= 22.5)   return "East";
  if (angle > 22.5   && angle <= 67.5)   return "Northeast";
  if (angle > 67.5   && angle <= 112.5)  return "North";
  if (angle > 112.5  && angle <= 157.5)  return "Northwest";
  if (angle > 157.5  || angle <= -157.5) return "West";
  if (angle > -157.5 && angle <= -112.5) return "Southwest";
  if (angle > -112.5 && angle <= -67.5)  return "South";
  return "Southeast";
}

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
