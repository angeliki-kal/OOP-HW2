#include "Node.hpp"

using namespace std;

Node::Node(Creator* c):creator(c), left(NULL), right(NULL) {

}

Node::~Node() {
  if(left!=NULL) delete left;
  if(right!=NULL) delete right;
}
