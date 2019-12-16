#ifndef NODE_HPP
#define NODE_HPP

#include "Post.hpp"
class Creator; //forward declaration

class Node {
    Creator* creator;
    Node *left, *right;
  public:
    void insert(Post* post);
    void print();
    Node(Creator* creator);
    ~Node();
};

#endif
