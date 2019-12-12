#ifndef POST_HPP
#define POST_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Date.hpp"

class Creator; //forward declaration

class Post {
  static int counter;
  int id;
  Creator* creator;
  std::string title, text;
  Date date;
 public:
   Post(std::string title, Creator* creator, std::string date, std::string text);
   ~Post();
   int getId();
   std::string getTitle();
   void print();
};

void readRandomTextFile(std::string path);
std::string getRandomText();

#endif
