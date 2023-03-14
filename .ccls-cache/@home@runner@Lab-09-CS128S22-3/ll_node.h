// Original Author: Brian Law
//
#ifndef LL_NODE_H_
#define LL_NODE_H_

#include <string>

class LLNode {
  public:
    LLNode(std::string data);
    ~LLNode();

    // Leaving attributes public for easy access
    // This violates encapsulation, and we wouldn't do it
    // in "real" code.
    std::string data_;
    LLNode* next_;  // A pointer to the next node in the LL
};


#endif