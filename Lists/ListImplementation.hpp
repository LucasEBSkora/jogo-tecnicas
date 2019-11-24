
namespace DIM {
  namespace Lists {

    template <typename TF>
    template <typename TE>
    List<TF>::ListElement<TE>::ListElement() {
      next = nullptr;
      prev = nullptr;
    }

    template <typename TF>
    template <typename TE>
    List<TF>::ListElement<TE>::~ListElement() {
      next = nullptr;
      prev = nullptr;
    }

    template <typename TF>
    template <typename TE>
    typename List<TF>::template ListElement<TE>* List<TF>::ListElement<TE>::getNext() {
      return next;
    }

    template <typename TF>
    template <typename TE>
    void List<TF>::ListElement<TE>::setNext(ListElement<TE>* elem) {
      next = elem;
    }

    template <typename TF>
    template <typename TE>
    typename List<TF>::template ListElement<TE>* List<TF>::ListElement<TE>::getPrev() {
      return prev;
    }

    template <typename TF>
    template <typename TE>
    void List<TF>::ListElement<TE>::setPrev(ListElement<TE>* elem) {
      prev = elem;
    }

    template <typename TF>
    template <typename TE>
    TE& List<TF>::ListElement<TE>::getData() {
      return data;
    }

    template <typename TF>
    template <typename TE>
    void List<TF>::ListElement<TE>::setData(const TE& elem) {
      data = elem;
    }

    template <typename TF>
    List<TF>::List() {
      first = nullptr;
      last = nullptr;
      size = 0;
    }

    template <typename TF>
    List<TF>::~List() {
      clear();
    }

    template <typename TF>
    void List<TF>::addElementBack(const TF& newElement) {
      ++size;
      if (first == nullptr) {
        ListElement<TF>* elem = new ListElement<TF>();
        elem->setData(newElement);
        first = elem;
        last = elem;
      } else {
        ListElement<TF>* elem = new ListElement<TF>();
        elem->setData(newElement);
        last->setNext(elem);
        elem->setPrev(last);
        last = elem;
      }
    }
    
    template <typename TF>
    void List<TF>::addElementFront(const TF& newElement) {
      ++size;
      if (first == nullptr) {
        ListElement<TF>* elem = new ListElement<TF>();
        elem->setData(newElement);
        first = elem;
        last = elem;
      } else {
        ListElement<TF>* elem = new ListElement<TF>();
        elem->setData(newElement);
        first->setPrev(elem);
        elem->setNext(first);
        first = elem;
      }
    }
    
    template <typename TF>
    void List<TF>::removeFirstMatchingElement(const TF& element) {
      if (first == nullptr) {
        return;
      } else {
        ListElement<TF>* aux = first;
        while (aux != nullptr && aux->getData() != element) {
          aux = aux->getNext();
        }
        if (aux == nullptr) return;
        if (aux->getNext() != nullptr) aux->getNext()->setPrev(aux->getPrev());
        else last = aux->getPrev();
        if (aux->getPrev() != nullptr) aux->getPrev()->setNext(aux->getNext());
        else first = aux->getNext();
        
        delete aux;
        --size;
      }
    }

    template <typename TF>
    List<TF>::iterator::iterator(List<TF>::ListElement<TF>* el) {
      element = el;
    }

    template <typename TF>
    List<TF>::iterator::iterator(const List<TF>::iterator& other) {
      element = other.element;
    }

    template <typename TF>
    List<TF>::iterator::~iterator() {
      element = nullptr;
    }

    template <typename TF>
    TF& List<TF>::iterator::operator*() {
      return element->getData();
    }

    template <typename TF>
    bool List<TF>::iterator::operator==(const iterator& other) {
      return element == other.element;
    }

    template <typename TF>
    bool List<TF>::iterator::operator!=(const iterator& other) {
      return !(*this == other);
    }

    template <typename TF>
    typename List<TF>::iterator& List<TF>::iterator::operator++() {
      if (element != nullptr) {
        element = element->getNext();
      }
      return *this;
    }

    template <typename TF>
    typename List<TF>::iterator List<TF>::iterator::operator++(int) {
      ListElement<TF>* ret = element;
      if (element != nullptr) {
        element = element->getNext();
      }
      return iterator(ret);
    }

    template <typename TF>
    typename List<TF>::iterator List<TF>::begin() {
      return iterator(first);
    }

    template <typename TF>
    typename List<TF>::iterator List<TF>::end() {
      return iterator(nullptr);
    }

    template <typename TF>
    void List<TF>::clear() {
      while (first != nullptr) {
        ListElement<TF>* aux = first->getNext();
        delete first;
        first = aux;
      }
      first = nullptr;
      last = nullptr;
    }
    
    template <typename TF>
    const unsigned int List<TF>::getSize() const {
      return size;
    }

  }
}