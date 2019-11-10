#ifndef MAP_H
#define MAP_H

namespace DIM {
  template <typename TE>
  class List {
    private:

    
    protected:

      class ListElement {
      private: // tudo privado pra agradar o Simão
               //Até pq friend nem existe
        ListElement<TE>* next;
        ListElement<TE>* prev;
        TE data;
      public:
        ListElement<TE>* getNext();
        void setNext(ListElement<TE>* elem);
        ListElement<TE>* getPrev();
        void setPrev(ListElement<TE>* elem);
        // ninguém além da lista sabe que existe essa classe
        // já que é protected
        // não pode ser nomeada fora da classe mãe
        // o certo (como fazem na STL) é usar struct e tudo público
        TE& getData();
        void setData(const TE& elem);

        ListElement();
        ~ListElement();
      };
      ListElement<TE>* first;
      ListElement<TE>* last;


    public:
      List();
      ~List();
      void AddElementBack(const TE& newElement);
      void AddElementFront(const TE& newElement);
      

  };
}

#include "ListImplementation.hpp"

#endif