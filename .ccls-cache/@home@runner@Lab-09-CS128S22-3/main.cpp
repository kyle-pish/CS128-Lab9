#include <iostream>
#include "linked_list.h"


void Lab9Part1_main() {
  //This is awful, but demonstrates how important having an LL class is for making this practical.
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

  //Pointing "current node" back at head; no need for a new variable. 
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


void Lab9Part2_main() {
  //An LL for testing
  LinkedList LL1 = LinkedList();

  //Note that this contains the repitions needed for testing Count()
  LL1.Append("I");
  LL1.Append("am");
  LL1.Append("Iron");
  LL1.Append("Man");
  LL1.Append("Nah");
  LL1.Append("Nuh");
  LL1.Append("Nah");
  LL1.Append("Nuh");
  LL1.Append("Nah");
  LL1.Append("Nuh");
  LL1.Append("Nuh");

  //Print() test
  LL1.Print();

  //GetSize() test
  std::cout << LL1.GetSize() << std::endl;

  //Contains() test
  std::cout << LL1.Contains("Iron") << std::endl;
  std::cout << LL1.Contains("George") << std::endl;

  //Count() test; items of various repitions and one that is absent
  std::cout << 
LL1.Count("Nah") << std::endl;
  std::cout << 
LL1.Count("Nuh") << std::endl;
  std::cout << LL1.Count("Blah") << std::endl;

  //Insert test; tests index 0 insert edge case
  LL1.Insert(2, "the");
  LL1.Print();
  LL1.Insert(0, "Hey!");
  LL1.Print();

  std::cout << " " << std::endl; 

  //Single element for Pop test
  LinkedList LL2 = LinkedList();
  LL2.Append("blah");

  //Pop test; single and multielement lists
  std::cout << LL1.Pop() << std::endl;
  std::cout << LL2.Pop() << std::endl;

  //Set test
  LL1.Set(3, "THE");
  LL1.Print();

  //PopAt test; zero and non-zero indices 
  std::cout << std::endl << LL1.PopAt(3) << std::endl;
  LL1.Print();
  std::cout << std::endl << LL1.PopAt(0) << std::endl;
  LL1.Print();
}

int main() {
  Lab9Part1_main();
  Lab9Part2_main();
  
}