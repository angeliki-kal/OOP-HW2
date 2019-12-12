#include "Thread.hpp"

using namespace std;

Thread::Thread(string s, string c, string d):subject(s), creator(c), date(d) {
  cout << "Thread with subject:" << subject << " has just been created\n";
}

Thread::~Thread() {
  for(auto elem: posts) {
    delete elem.second;
  }
  cout << "\nThread with subject: " << subject << " is about to be destroyed\n";
}

std::string Thread::getSubject() const {
  return subject;
}

void Thread::addPost(Post* post) {
  posts.insert(std::pair<int,Post*>(post->getId(),post));
}

Post* Thread::getPost(int id) {
  try {
    return posts.at(id);
  }
  catch(std::out_of_range e) {
    return NULL; //not found
  }
}

void Thread::print() {
  cout << "\n-----Printing Thread: \"" << subject << "\" by \"" << creator << "\" " << date.to_string() << endl;
  for(auto elem: posts) {
    cout << "\t" << elem.second->getTitle() << endl;
  }
  cout << "---------------\n";
}
