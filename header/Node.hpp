#ifndef NODE_HPP
#define NODE_HPP

class Creator; //forward declaration

class Node {
    Creator* creator;
    Node *left, *right;
  public:
    Node(Creator* creator);
    ~Node();
};

#endif
