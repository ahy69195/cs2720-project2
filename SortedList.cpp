#include "SortedList.h"
template <class ItemType>
SortedList<ItemType>::SortedList() {
  length = 0;
  head = new Node<ItemType>;
  head->next = nullptr;
}

template <class ItemType>
SortedList<ItemType>::~SortedList() {
  makeEmpty();
}

template <class ItemType>
void SortedList<ItemType>::makeEmpty() {

  while (head != NULL) {
    Node<ItemType>* current = head;
    head = head->next;
    delete current;
  }
  length = 0;
  head = new Node<ItemType>;
  head->next = nullptr;
}

template <class ItemType>
bool SortedList<ItemType>::isEmpty() const {
  if (head->next == NULL) {
    return true;
  }
  return false;
}

template <class ItemType>
void SortedList<ItemType>::putItem(ItemType newItem) {
  Node<ItemType>* current;
  pair<bool, Node<ItemType>*> find = findItem(newItem);

  if (find.first == true) {
    throw DuplicateItem();
  }

  current = find.second->next;
  find.second->next = new Node<ItemType>;
  find.second->next->info = newItem;
  find.second->next->next = current;
  length++;
}

template <class ItemType>
void SortedList<ItemType>::deleteItem(ItemType item) {
  pair<bool, Node<ItemType>*> find = findItem(item);

  if (find.first == false) {
    throw DeletingMissingItem();
  } else {
    find.second->next = find.second->next->next;
    length--;
  }
}

template <class ItemType>
int SortedList<ItemType>::getLength() const {
  return length;
}

template <class ItemType>
ItemType SortedList<ItemType>::getAt(int i) {
  if (i < 1 || i > length) {
    throw OutOfBound();
  } else {
    int count = 1;
    Node<ItemType>* current = head->next; //skips dummy head
    while (count < i) {
      current = current->next;
      count++;
    }
    return current->info;
  }
}

template <class ItemType>
void SortedList<ItemType>::merge(SortedList& otherList) {
  Node<ItemType>* mergedList = new Node<ItemType>;
  Node<ItemType>* current = mergedList;
  Node<ItemType>* deleteDummyHead = head; //will be deleted at the end
  head = head->next; //removes the dummy head
  delete deleteDummyHead; 

  //I think this is the best way to deallocate otherList without messing up its pointer.
  int i = 1;
  int len = otherList.getLength();
  
  int count = length; //This is to add on to length later on- this will count how many elements in head that need to be added on at the end  
  length = 0; //how many nodes in merged list

  while (head != nullptr && i <= len) {
    //<= because we need to check last index of otherList by getAt function
    if (head->info < otherList.getAt(i)) { 
      current->next = head;                  
      head = head->next;
      current = current->next;
      length++;
      count--;
    } else if (head->info > otherList.getAt(i)) {
      current->next = new Node<ItemType>;
      current->next->info = otherList.getAt(i);
      current = current->next;
      i++;
      length++;
    } else if (head->info == otherList.getAt(i)){ //The lists are equal
      Node<ItemType>* temp = head;
      head = head->next;
      count--;
      delete temp;
    }
  }


  if (head == nullptr) {
    while (i <= len) {
      current->next = new Node<ItemType>;
      current->next->info = otherList.getAt(i);
      current = current->next;
      i++;
      length++;
    }
    current->next = nullptr; //end of the merged list so needs null ending 
  } else {
    current->next = head;// comes with it's own null
    length += count;
  }
  
  
  otherList.makeEmpty();
  head = mergedList;
}

template<class ItemType>
void SortedList<ItemType>::printList(ofstream& out) {
  Node<ItemType>* current = head;
  while (current->next != NULL) {
    out << current->next->info << "->";
    current = current->next;
  }

  out << "NULL";
  
}

template <class ItemType>
pair<bool, Node<ItemType>*> SortedList<ItemType>::findItem(ItemType item) {
  Node<ItemType>* current = head;

  while (current->next != nullptr) {
    if (current->next->info == item) {
      return make_pair(true, current);
    }
    if (current->next->info > item) {
      return make_pair(false, current);
    }
    current=current->next;
  }
  return make_pair(false, current);
}
