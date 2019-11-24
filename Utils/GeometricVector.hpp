#ifndef GEOMETRICVECTOR_HPP
#define GEOMETRICVECTOR_HPP

#include <ostream>

namespace DIM {
  namespace Utils {

    template <typename T>
    class GeometricVector {
      public:
        T x, y;

        GeometricVector(const GeometricVector<T>& other);
        GeometricVector(T X = 0.0f, T Y = 0.0f);
        ~GeometricVector();

        void operator =(GeometricVector v);

        GeometricVector operator +(GeometricVector v) const;
        GeometricVector operator -(GeometricVector v) const; 
        
        void operator +=(GeometricVector v);
        void operator -=(GeometricVector v);
        
        //canonical inner product for R²
        float operator *(GeometricVector v) const;
        
        GeometricVector operator *(int a) const;
        GeometricVector operator *(float f) const;
        GeometricVector operator *(double b) const;
        
        float module() const;
        GeometricVector unitVector() const;

        //Projection of this in the direction of the argument
        GeometricVector projection(GeometricVector vector) const;

    };
    
    typedef GeometricVector<float> VectorF;
    typedef GeometricVector<int> VectorI;
    typedef GeometricVector<unsigned int> VectorU;

    template <typename T>
    std::ostream& operator<< (std::ostream& out, const GeometricVector<T> vector);

  }
}

#include "GeometricVectorImplementation.hpp"

#endif
