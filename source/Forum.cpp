#include <iostream>

#include "Forum.hpp"
#include "Thread.hpp"

using namespace std;

Forum::Forum(std::string const &t):title(t),threads(),post_cache(),creator_bst(NULL) {
  cout << "Forum with title: " << title << " has just been created\n\n";
}

Forum::~Forum() {
  for(auto elem: threads) { //delete threads
    delete elem.second;
  }
  delete creator_bst;
  cout << "\nForum with title: " << title << " is about to be destroyed\n";
}

void Forum::addThread(Thread* t) {
  threads.insert(std::pair<string,Thread*>(t->getSubject(),t));
}

Thread* Forum::getThread(std::string const &thread_subject){
  try {
    return threads.at(thread_subject);
  }
  catch(std::out_of_range e) {
    return NULL;  //not found
  }
}

void Forum::print() {
  cout << "\n-----Printing Forum: " << title << endl;
  for(auto elem: threads) {
    cout << elem.second->getSubject() << endl;
  }
  cout << "---------------\n";
}

Post* Forum::getPost(int id) {
  //first check if the post is avl in cache
  auto thread_pair = post_cache.find(id);
  if(thread_pair != post_cache.end()) {
    return (thread_pair->second)->getPost(id);   //yay!! found it in cache
  }
  else { //post not in cache
    //search all threads for post
    Post* post;
    for(auto elem: threads) {
      Thread* t = elem.second;
      if((post = t->getPost(id)) != NULL ) {
        //found the post in this thread
        post_cache.insert(pair<int,Thread*>(id,t)); //save in cache for next time
        return post;
      }
    }
  }
  return NULL; //not found
}

void Forum::printPost(int id) {
  Post* post = getPost(id);
  if(post != NULL) {
      post->print();
  }
  else {
    cerr << "Requested to print post that doesn't exist";
  }
}

/*
Insert Post to Thread and to the BST
*/
void Forum::insertPost(const string &thread, Post* post) {
  //insert to thread
  getThread(thread)->addPost(post);
  //insert to creator bst
  if(creator_bst==NULL) {
    creator_bst = new Node(post->getCreator());
  }
  creator_bst->insert(post);
}

void Forum::printSorted() {
  creator_bst->print();
}
