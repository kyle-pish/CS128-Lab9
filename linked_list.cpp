// Original Author: Brian Law
//
#include <iostream>
#include <string>

#include "linked_list.h"

// Create a new linked list.
LinkedList::LinkedList() {
  // Initialize the head pointer to null, to indicate 0 nodes.
  this->head_ = 0;
  this->size_ = 0;
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

  this->size_++;
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

//Print to console the contents of the linked list in the format "[1 2 3 4 ]"
void LinkedList::Print() {  
  std::cout << "[";
  
  LLNode* current_node = this->head_;

  while(current_node != 0) {
    std::cout << current_node->data_ << " ";
    current_node = current_node->next_;
  }
  std::cout << "]";
}

//Return the size_ attribute
int LinkedList::GetSize() {
  return this->size_;
}

//Takes as input an std::string; returns true if that string exists in the Linked List, and false if not.
bool LinkedList::Contains(std::string contains_me) {
  LLNode* current_node = this->head_;
  while (current_node != 0) {
    if (current_node->data_ == contains_me) {
      return true; 
    }

    current_node = current_node->next_;
  }

  return false;
}

//Takes as input an std::string; returns as an int the number of times that string exists in the list.
int LinkedList::Count(std::string count_me) {
  LLNode* current_node = this->head_;
  int counter = 0;

  while (current_node != 0) {
    if (current_node->data_ == count_me) {
      counter++;
    }
    current_node = current_node->next_;
  }

  return counter;
} 

//Takes as input an int index and an std::string value, and places the value at the index in the list.
void LinkedList::Insert(int index, std::string value) {
  LLNode* current_node = this->head_;
  int index_counter = 0;

  //Handles inserting at 0 separately 
  if (index == 0) {
    LLNode* new_node = new LLNode(value);
    new_node->next_ = head_;
    head_ = new_node;
  }
  

  else { 
    //We want to stop one before the item at the index we're aiming for, so we can update the previous node's next_ 
    while (index_counter < index - 1) {
      index_counter++;
      current_node = current_node->next_;
    }
  
    LLNode* new_node = new LLNode(value);
  
    new_node->next_ = current_node->next_;
    current_node->next_ = new_node;
  }
  this->size_++;
  
}

//Removes and returns the last element of the list
std::string LinkedList::Pop() {
  LLNode* current_node = this->head_;

  std::string output = "";
  //Handles a list of length 1 separately
  if (current_node->next_ == 0) {
    output = current_node->data_;
    delete this->head_;
    this->head_ = 0; //Unclear if this should be necessary, but it segfaults without it.
  }
  
  //Stopping at the second to last element so we do not lose track of it
  else {
    while (current_node->next_->next_ != 0) {
      current_node = current_node->next_;
    }
  
    output = current_node->data_;
    delete current_node->next_;
    current_node->next_ = 0;
  }
  this->size_--;
  return output;
}

//Takes as input an int index and an std::string value. Sets the data_ of the node at the given index to the given value.
void LinkedList::Set(int index, std::string value) {
  LLNode* current_node = this->head_;
  int index_counter = 0;

  while (index_counter < index) {
    index_counter++;
    current_node = current_node->next_;
  }

  current_node->data_ = value; 
}

//Takes as input an int index; returns and removes the node at that index.
std::string LinkedList::PopAt(int index) {
  LLNode* current_node = this->head_;
  int index_counter = 0;
  std::string output = "";

  //Handles popping at 0 separately 
  if (index == 0) {
    output = this->head_->data_;
    LLNode* next_node = this->head_->next_;

    this->head_->next_ = 0; //Without this, the node destructor will recursively delete the rest of the LL, so we have to disconnect the node we're popping from the LL.
    delete this->head_;
    this->head_ = next_node; 
  }

  else { 
    //Stops one before the one we want to remove
    while (index_counter < index - 1) {
      index_counter++;
      current_node = current_node->next_;
    }
    //Saves the node after the one we want to remove
    LLNode* next_node = current_node->next_->next_;
  
    output = current_node->next_->data_;
    current_node->next_->next_ = 0; //Again, keeping the node destructor in check
    delete current_node->next_;
    current_node->next_ = next_node;
  }

  this->size_--;
  return output;
  
}


