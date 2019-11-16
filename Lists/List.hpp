#ifndef MAP_H
#define MAP_H

namespace DIM {
  template <typename TE>
  class List {
  private:
    unsigned int size;

    class ListElement {
    private: // tudo privado pra agradar o Simão
              //Até pq friend nem existe
      ListElement* next;
      ListElement* prev;
      TE data;
    public:
      ListElement* getNext();
      void setNext(ListElement* elem);
      ListElement* getPrev();
      void setPrev(ListElement* elem);
      // ninguém além da lista sabe que existe essa classe
      // já que é protected
      // não pode ser nomeada fora da classe mãe
      // o certo (como fazem na STL) é usar struct e tudo público
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

#include "ListImplementation.hpp"

#endif