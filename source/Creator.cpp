#include "Creator.hpp"

using namespace std;

Creator::Creator(string n):name(n),posts() {
}

Creator::~Creator() {}

string Creator::getName() {
  return name;
}

void Creator::addPost(Post* post){
  posts.push_back(post);
}

void Creator::printPosts() {
  for(int i=0; i < posts.size(); i++) {
      cout << posts.at(i)->getId() << "\n";
  }
}
