#ifndef MAP_H
#define MAP_H

namespace DIM {
  namespace Lists {

    template <typename TE>
    class List {
    private:
      unsigned int size;

      class ListElement {
      private: 
        ListElement* next;
        ListElement* prev;
        TE data;
      public:
        ListElement* getNext();
        void setNext(ListElement* elem);
        ListElement* getPrev();
        void setPrev(ListElement* elem);
        TE& getData();
        void setData(const TE& elem);

        ListElement();
        ~ListElement();
      };

    ListElement* first;
    ListElement* last;

    public:
      List();
      ~List();
      void addElementBack(const TE& newElement);
      void addElementFront(const TE& newElement);
      void removeFirstMatchingElement(const TE& element);
      const unsigned int getSize() const;

      class iterator {
      private:
        ListElement* element;
        iterator(ListElement* el);
      public:
        iterator(const iterator& other);
        ~iterator();
        TE& operator*();
        bool operator==(const iterator& other);
        bool operator!=(const iterator& other);
        iterator& operator++();
        iterator operator++(int);
        friend class List;
      };

      iterator begin();
      iterator end();

      void clear();

    };
    
  }
}

#include "ListImplementation.hpp"

#endif