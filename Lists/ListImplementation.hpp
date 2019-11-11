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
  ListElement<TE>* List<TE>::ListElement::getNext() {
    return next;
  }

  template <typename TE>
  void List<TE>::ListElement::setNext(ListElement<TE>* elem) {
    next = elem;
  }

  template <typename TE>
  ListElement<TE>* List<TE>::ListElement::getPrev() {
    return prev;
  }

  template <typename TE>
  void List<TE>::ListElement::setPrev(ListElement<TE>* elem) {
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
      ListElement<TE>* aux = first->getNext();
      delete first;
      first = aux;
    }
  }

  template <typename TE>
  List<TE>::AddElementBack(const TE& newElement) {
    if (first == nullptr) {
      ListElement<TE>* elem = new ListElement<TE>();
      elem->setData(newElement);
      first = elem;
      last = elem;
    } else {
      ListElement<TE>* elem = new ListElement<TE>();
      elem->setData(newElement);
      last->setNext(elem);
      elem->setPrev(last);
      last = elem;
    }
  }
  
  template <typename TE>
  List<TE>::AddElementFront(const TE& newElement) {
    if (first == nullptr) {
      ListElement<TE>* elem = new ListElement<TE>();
      elem->setData(newElement);
      first = elem;
      last = elem;
    } else {
      ListElement<TE>* elem = new ListElement<TE>();
      elem->setData(newElement);
      first->setPrev(elem);
      elem->setNext(first);
      first = elem;
    }
  }

}