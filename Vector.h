//
// Created by linkl on 3/27/2025.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
#include <string>


class Vector {
  int x, y;
public:
  Vector(const int x, const int y) : x(x), y(y) {}
  explicit Vector(const int a) : x(a), y(a) {}

  float magnitude() const {return sqrt(x * x + y * y);}
  std::string direction() const;

  float dist(const Vector other) const {return (*this - other).magnitude();}

  Vector normalize() const {return Vector(x / magnitude(), y / magnitude());}
  Vector scale(const float scale) const {return Vector(x * scale, y * scale);}
  Vector clamp(const Vector &min, const Vector &max) const;
  Vector operator+(const Vector &other) const {return Vector(x + other.x, y + other.y);}
  Vector operator-(const Vector &other) const {return Vector(x - other.x, y - other.y);}
  bool operator==(const Vector & vector) const = default;

  static Vector random(const int range, const float offset=0) {return Vector(rand() % range + offset, rand() % range + offset);}

  int getX() const {return x;}
  int getY() const {return y;}
};

#endif //VECTOR_H
