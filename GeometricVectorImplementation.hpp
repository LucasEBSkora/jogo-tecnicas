
namespace DIM {
  namespace Utility {

    template <typename T>
    GeometricVector<T>::GeometricVector(const GeometricVector<T>& other) : x{other.x}, y{other.y} {

    }

    template <typename T>
    GeometricVector<T>::GeometricVector(T X, T Y) : x{X}, y{Y} {

    }

    template <typename T>
    GeometricVector<T>::~GeometricVector() {

    }

    template <typename T>
    void GeometricVector<T>::operator =(GeometricVector v) {
      x = v.x;
      y = v.y;
    }

    template <typename T>
    GeometricVector<T> GeometricVector<T>::operator +(GeometricVector v) const {
      return GeometricVector(x + v.x, y + v.y);
    }

    template <typename T>
    GeometricVector<T> GeometricVector<T>::operator -(GeometricVector v) const {
      return GeometricVector(x-v.x, y - v.y);
    }

    template <typename T>
    void GeometricVector<T>::operator +=(GeometricVector v) {
      x = x + v.x;
      y = y + v.y;
    }

    template <typename T>
    void GeometricVector<T>::operator -=(GeometricVector v) {
      x = x - v.x;
      y = y - v.y;
    }

    template <typename T>
    float GeometricVector<T>::operator *(GeometricVector v) const {
      return x*(v.x) + y*(v.y);
    }

    template <typename T>
    GeometricVector<T> GeometricVector<T>::operator *(int a) const {
    return GeometricVector(a*x, a*y);
    }

    template <typename T>
    GeometricVector<T> GeometricVector<T>::operator *(float f) const {
    return GeometricVector(f*x, f*y);
    }

    template <typename T>
    GeometricVector<T> GeometricVector<T>::operator *(double b) const {
    return GeometricVector(b*x, b*y);
    }

    template <typename T>
    float GeometricVector<T>::module() const{
    return sqrt(x*x+y*y);
    }

    template <typename T>
    GeometricVector<T> GeometricVector<T>::unitVector() const {
      return this->operator*(1.0f/module());
    }

    template <typename T>
    GeometricVector<T> GeometricVector<T>::projection(GeometricVector vector) const {
      return vector*((this->operator*(vector))/pow(vector.module(), 2));
    }

    template <typename T>
    std::ostream& operator<< (std::ostream& out, const GeometricVector<T> vector) {
      out << '(' << vector.x << " , " << vector.y << ')';
      return out;
    }

  }
}
