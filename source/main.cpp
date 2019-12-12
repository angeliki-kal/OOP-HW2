#include <iostream>
#include <string>

#include "Forum.hpp"
#include "Thread.hpp"
#include "Creator.hpp"

using namespace std;

int main(int argc, char** argv) {
  //read text file to memory (used to write random posts)
  readRandomTextFile("./rand_text.txt");
  //instantiate Forum Object
  Forum A("OOP");
  //add 2 threads to forum
  A.addThread(new Thread("Kanones kai Xrisimes Plirofories", "aggkal", "2019-11-11"));
  A.addThread(new Thread("Thread2", "bla", "2018-10-10"));
  //print the forum
  A.print();
  //print thread
  A.getThread("Kanones kai Xrisimes Plirofories")->print();

  //make x random posts to Thread2
  int num_posts = 5;
  Creator* creators[5];
  for(int i=0; i<num_posts; i++) {
    Creator* crt = new Creator("crt"+to_string(i));
    crt->createPost("posttitle"+to_string(i), "2000-03-15", getRandomText(), &A, A.getThread("Thread2"));
    creators[i] = crt;
  }
  //print x random posts from forum
  for(int i=0; i<num_posts; i++) {
    A.printPost((rand() % num_posts) + 1);
  }
  for(int i=0; i<num_posts; i++) {
    delete creators[i];
  }
  return 0;
}
