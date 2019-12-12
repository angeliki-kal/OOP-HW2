#include "Creator.hpp"
#include "Post.hpp"
#include "Forum.hpp"

using namespace std;

Creator::Creator(string n):name(n),posts() {
}

Creator::~Creator() {}

std::string Creator::getName() {
  return name;
}

void Creator::createPost(std::string title, std::string date, std::string text, Forum* forum, Thread* thread) {
  Post* post = new Post(title, this, date, text);
  posts.push_back(post);  //add to creators posts
  forum->insertPost(thread, post); //add to forum
}
