

namespace DIM {

  template <typename T>
  Vector<T>::Vector(const Vector<T>& other) : x{other.x}, y{other.y} {

  }

  template <typename T>
  Vector<T>::Vector(T X, T Y) : x{X}, y{Y} {

  }

  template <typename T>
  Vector<T>::~Vector() {

  }

  template <typename T>
  void Vector<T>::operator =(Vector v) {
    x = v.x;
    y = v.y;
  }

  template <typename T>
  Vector<T> Vector<T>::operator +(Vector v) const {
    return Vector(x + v.x, y + v.y);
  }

  template <typename T>
  Vector<T> Vector<T>::operator -(Vector v) const {
    return Vector(x-v.x, y - v.y);
  }

  template <typename T>
  void Vector<T>::operator +=(Vector v) {
    x = x + v.x;
    y = y + v.y;
  }

  template <typename T>
  void Vector<T>::operator -=(Vector v) {
    x = x - v.x;
    y = y - v.y;
  }

  template <typename T>
  float Vector<T>::operator *(Vector v) const {
    return x*(v.x) + y*(v.y);
  }

  template <typename T>
  Vector<T> Vector<T>::operator *(int a) const {
  return Vector(a*x, a*y);
  }

  template <typename T>
  Vector<T> Vector<T>::operator *(float f) const {
  return Vector(f*x, f*y);
  }

  template <typename T>
  Vector<T> Vector<T>::operator *(double b) const {
  return Vector(b*x, b*y);
  }

  template <typename T>
  float Vector<T>::module() const{
  return sqrt(x*x+y*y);
  }

  template <typename T>
  Vector<T> Vector<T>::unitVector() const {
    return this->operator*(1.0f/module());
  }

  template <typename T>
  Vector<T> Vector<T>::projection(Vector vector) const {
    return vector*((this->operator*(vector))/pow(vector.module(), 2));
  }

  template <typename T>
  std::ostream& operator<< (std::ostream& out, const Vector<T> vector) {
    out << '(' << vector.x << " , " << vector.y << ')';
    return out;
  }

} // namespace DIM
