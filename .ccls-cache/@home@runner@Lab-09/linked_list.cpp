// Original Author: Brian Law
//
#include <iostream>
#include <string>

#include "linked_list.h"

// Create a new linked list.
LinkedList::LinkedList() {
  // Initialize the head pointer to null, to indicate 0 nodes.
  this->head_ = 0;
}

LinkedList::~LinkedList() {
  // If there is a head node, delete it.
  // Recursive destructor in LLNode should take care
  // of remaining nodes in the LL.
  if (this->head_ != 0) {
    delete this->head_;
  }
}

// Add a new node with the given value to the end of the LL.
void LinkedList::Append(std::string new_data) {
  // Special case: if the LL has no nodes in it yet,
  // we need to deal with that case separately
  // and manipulate the head pointer ourselves.
  if (this->head_ == 0) {
    this->head_ = new LLNode(new_data);
  }
  else {
    // Otherwise, LL is not empty, so traversal is required.
    // Start a pointer at the head.
    LLNode* current_node = this->head_;

    // Traversing the linked list until the current_node
    // pointer points at the last node.
    while (current_node->next_ != 0) {
      current_node = current_node->next_;
    }

    // So at this point here, current_node should be
    // a pointer to the last node because the last node's
    // next_ points at 0.
    current_node->next_ = new LLNode(new_data);
  }
}

// Return the data in the node located at the specified index.
std::string LinkedList::Get(int index) {
  // Start the pointer at the head
  LLNode* current_node = this->head_;

  // Index counter
  int counter = 0;

  // Traverse the LL until we reach the end or until
  // the given index is reached.
  // HOPEFULLY the user didn't give us a too-large index.
  // If they did, this will seg-fault.
  while (current_node != 0 && counter < index) {
    counter++;
    current_node = current_node->next_;
  }

  // Pointer should now be pointing at correct index
  // (or null, if a bad index was given).
  return current_node->data_;
}
