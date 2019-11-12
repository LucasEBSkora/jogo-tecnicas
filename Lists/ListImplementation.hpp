namespace DIM {

  template <typename TE>
  List<TE>::ListElement::ListElement() {
    next = nullptr;
    prev = nullptr;
  }

  template <typename TE>
  List<TE>::ListElement::~ListElement() {
    next = nullptr;
    prev = nullptr;
  }

  template <typename TE>
  typename List<TE>::ListElement* List<TE>::ListElement::getNext() {
    return next;
  }

  template <typename TE>
  void List<TE>::ListElement::setNext(ListElement* elem) {
    next = elem;
  }

  template <typename TE>
  typename List<TE>::ListElement* List<TE>::ListElement::getPrev() {
    return prev;
  }

  template <typename TE>
  void List<TE>::ListElement::setPrev(ListElement* elem) {
    prev = elem;
  }

  template <typename TE>
  TE& List<TE>::ListElement::getData() {
    return data;
  }

  template <typename TE>
  void List<TE>::ListElement::setData(const TE& elem) {
    data = elem;
  }

  template <typename TE>
  List<TE>::List() {
    first = nullptr;
    last = nullptr;
  }

  template <typename TE>
  List<TE>::~List() {
    while (first != nullptr) {
      ListElement* aux = first->getNext();
      delete first;
      first = aux;
    }
  }

  template <typename TE>
  void List<TE>::AddElementBack(const TE& newElement) {
    if (first == nullptr) {
      ListElement* elem = new ListElement();
      elem->setData(newElement);
      first = elem;
      last = elem;
    } else {
      ListElement* elem = new ListElement();
      elem->setData(newElement);
      last->setNext(elem);
      elem->setPrev(last);
      last = elem;
    }
  }
  
  template <typename TE>
  void List<TE>::AddElementFront(const TE& newElement) {
    if (first == nullptr) {
      ListElement* elem = new ListElement();
      elem->setData(newElement);
      first = elem;
      last = elem;
    } else {
      ListElement* elem = new ListElement();
      elem->setData(newElement);
      first->setPrev(elem);
      elem->setNext(first);
      first = elem;
    }
  }

  template <typename TE>
  List<TE>::iterator::iterator(List<TE>::ListElement* el) {
    element = el;
  }

  template <typename TE>
  List<TE>::iterator::iterator(const List<TE>::iterator& other) {
    element = other.element;
  }

  template <typename TE>
  List<TE>::iterator::~iterator() {
    element = nullptr;
  }

  template <typename TE>
  TE& List<TE>::iterator::operator*() {
    return element->getData();
  }

  template <typename TE>
  bool List<TE>::iterator::operator==(const iterator& other) {
    return element == other.element;
  }

  template <typename TE>
  bool List<TE>::iterator::operator!=(const iterator& other) {
    return !(*this == other);
  }

  template <typename TE>
  typename List<TE>::iterator& List<TE>::iterator::operator++() {
    if (element != nullptr) {
      element = element->getNext();
    }
    return *this;
  }

  template <typename TE>
  typename List<TE>::iterator List<TE>::iterator::operator++(int) {
    ListElement* ret = element;
    if (element != nullptr) {
      element = element->getNext();
    }
    return iterator(ret);
  }

  template <typename TE>
  typename List<TE>::iterator List<TE>::begin() {
    return iterator(first);
  }

  template <typename TE>
  typename List<TE>::iterator List<TE>::end() {
    return iterator(nullptr);
  }

}