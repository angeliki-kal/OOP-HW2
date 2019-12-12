#ifndef CREATOR_HPP
#define CREATOR_HPP

#include <string>
#include <vector>
#include "Forum.hpp"
#include "Post.hpp"

class Creator {
    std::string name;
    std::vector<Post*> posts; //watch out, if forum destroyed posts are del as well
  public:
    Creator(std::string);
    ~Creator();
    std::string getName();
    //create post and insert it to forum/thread
    void createPost(std::string title, std::string date, std::string text, Forum* forum, Thread* thread);
};

#endif
