#ifndef MAP_H
#define MAP_H

namespace DIM {
  namespace Lists {

    template <typename TF>
    class List {
    private:
      unsigned int size;

      template <typename TE>
      class ListElement {
      private: 
        ListElement<TE>* next;
        ListElement<TE>* prev;
        TE data;
      public:
        ListElement<TE>* getNext();
        void setNext(ListElement<TE>* elem);
        ListElement<TE>* getPrev();
        void setPrev(ListElement<TE>* elem);
        TE& getData();
        void setData(const TE& elem);

        ListElement();
        ~ListElement();
      };

    ListElement<TF>* first;
    ListElement<TF>* last;

    public:
      List();
      ~List();
      void addElementBack(const TF& newElement);
      void addElementFront(const TF& newElement);
      void removeFirstMatchingElement(const TF& element);
      const unsigned int getSize() const;

      class iterator {
      private:
        ListElement<TF>* element;
        iterator(ListElement<TF>* el);
      public:
        iterator(const iterator& other);
        ~iterator();
        TF& operator*();
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