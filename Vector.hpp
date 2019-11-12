#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

namespace DIM {

template <typename T>
class Vector {
  public:
    T x, y;

    Vector(const Vector<T>& other);
    Vector(T X = 0.0f, T Y = 0.0f);
    ~Vector();

    void operator =(Vector v);

    Vector operator +(Vector v) const;
    Vector operator -(Vector v) const; 
    
    void operator +=(Vector v);
    void operator -=(Vector v);
    
    //canonical inner product for R²
    float operator *(Vector v) const;
    
    Vector operator *(int a) const;
    Vector operator *(float f) const;
    Vector operator *(double b) const;
    
    float module() const;
    Vector unitVector() const;

    //Projection of this in the direction of the argument
    Vector projection(Vector vector) const;

};
  typedef Vector<float> VectorF;
  typedef Vector<int> VectorI;
  typedef Vector<unsigned int> VectorU;

}

#include "VectorImplementation.hpp"

#endif
