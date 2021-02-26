#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Linked List Node definition
template <class ItemType>
struct Node {
	ItemType info;
	Node<ItemType>* next;
};

// Exception classes
class OutOfBound{};

class DeletingMissingItem {};

class DuplicateItem{};

// Sorted List Template
template <class ItemType>
class SortedList
{
public: 
	// Class constructor.
	SortedList();
	
	// Class destructor. 
    ~SortedList();
	
	// Function: Deallocates list nodes, and reinitializes the list to its empty state.
	// Pre: List is initialized
	// Post: list is empty.
	void makeEmpty();
	
	// Function: Determines whether the list is empty.
	// Pre: List is initialized
	// Post: Function value = (list is empty)
    bool isEmpty() const;
   
   // Function: Adds newItem to the list. Must insert the item in the correct position to
   // maintain that the list is sorted in ascending order.
   // Pre: List is initialized
   // Post: If item is already in the list DuplicateItem exception is thrown
   //       else newItem is in the list at the correct position based on key value.
   //       The list should remain sorted after this function call.  
	void putItem(ItemType newItem);
   
	// Function: deletes Item from the list.
	// Post: If item is not in the list or if the list is empty, DeletingMissingItem exception is thrown.
    //       else Item is not in the list.
	void deleteItem(ItemType item);
	
	// Function: returns the number of items in the list
	// pre: List is initialized.
	// post: Function value = number of elemnts in the list.
	int getLength() const;
	
	// Function: returns the ith element of the list
	// pre: List is initialized.
	// post: if 1 <= i <= length, Function value = the ith list element. (i = 1 means get the value of the first node)
	//       Throws the OutOfBound exception if i < 1 or i > length 
	ItemType getAt(int i);
	
	//Function: Merges two sorted lists in place.
	//Preconditions: List is initialized. otherList is initialized. 
	//               otherList is sorted.
	//Postconditions: Function merges otherList into this/current list.
	//				  After merging, this/current list becomes the sorted and merged list with NO DUPLICATE keys;
	//				  otherList becomes empty.
	void merge(SortedList& otherList);
	
	// Function: Prints the list to a file.
	// For example, if the list consists of elements 1, 2 and 3,
	// the function should output "List Items : 1->2->3->NULL".
	// pre: List is initialized
	// post: List is not changed
	void printList(ofstream& out);

private:
    Node<ItemType>* head;	// you can choose whether to use a dummy head node or not
    int length;				// number of elements in the list
	
	// Function: Searches the list for item and returns a boolean on whether the item is already in the list or not, and
	// a pointer to item's predecessor node.
	// pre: list is initialized
	// post: (1) If item is in the list, the boolean value should be true 
	//       (2) if item is not in the list, the boolean value should be false  
	//       (3) predecessor contains the address of item's predecessor node (i.e. node with largest value < item's key)
	//           if no predescessor exit, predecessor is set to NULL.
	//		     Note: if you are using a dummy head node, then there will always be a predecessor
	pair<bool, Node<ItemType>*> findItem(ItemType item);
	
	// If needed, feel free to add any other private helper functions.
	
};


