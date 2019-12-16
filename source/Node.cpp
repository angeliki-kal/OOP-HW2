#include "Node.hpp"
#include "Post.hpp"
#include "Creator.hpp"

using namespace std;

Node::Node(Creator* c):creator(c), left(0), right(0) {

}

Node::~Node() {
  if(left!=0) delete left;
  if(right!=0) delete right;
}

void Node::insert(Post* post){
  if(creator == post->getCreator()) {
    creator->addPost(post);
  }
  else if(post->getCreator() < creator){
    if(left != 0) {
      left->insert(post);
    }
    else { //left doesnt exist yet
      left = new Node(post->getCreator());
      post->getCreator()->addPost(post);
    }
  }
  else {
    if(right != 0){
      right->insert(post);
    }
    else { //right doesnt exist yet
      right = new Node(post->getCreator());
      post->getCreator()->addPost(post);
    }
  }
}

void Node::print(){
  if(left != 0){
    left->print();
  }
  cout << "\nCreator: " << creator->getName() << "\n";
  creator->printPosts();
  if(right != 0){
    right->print();
  }
}
