// Original Author: Brian Law
//
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "ll_node.h"

class LinkedList {
  public:
    LinkedList();
    ~LinkedList();

    void Append(std::string new_data);
    std::string Get(int index);
    void Print();
    int GetSize();
    bool Contains(std::string contains_me);
    int Count(std::string count_me);
    void Insert(int index, std::string value);
    std::string Pop();
    void Set(int index, std::string value);
    std::string PopAt(int index);

  private:
    LLNode* head_;
    int size_;

};

#endif