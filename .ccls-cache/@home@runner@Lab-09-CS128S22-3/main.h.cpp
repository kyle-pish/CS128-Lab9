#include <iostream>
#include "linked_list.h"

void Lab9Part1_main() {
  LLNode* head = new LLNode("George");
  head->next_ = new LLNode("ate");
  head->next_->next_ = new LLNode("my");
  head->next_->next_->next_ = new LLNode("chicken");
  head->next_->next_->next_->next_  = new LLNode("nuggets");

  std::cout << head->data_ << " ";
  std::cout << head->next_->data_ << " ";
  std::cout << head->next_->next_->data_ << " ";
  std::cout << head->next_->next_->next_->data_ << " ";
  std::cout << head->next_->next_->next_->next_->data_ << std::endl;

  LLNode* current_node = head;
  while (current_node->next_ != 0) {
    std::cout << current_node->data_ << " ";
    current_node = current_node->next_;
  }

  std::cout << current_node->data_ << std::endl;

  //Pointing "current node" back at head; no need for a new variable
  current_node = head;
  while (current_node->next_ != 0) {
    current_node = current_node->next_;
  }
  current_node->next_ = new LLNode("sad");

    current_node = head;
  while (current_node->next_ != 0) {
    std::cout << current_node->data_ << " ";
    current_node = current_node->next_;
  }

  std::cout << current_node->data_;

  delete head;
  head = 0;
  
}

int main() {
  Lab9Part1_main();
}

