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
    void addPost(Post*);
    ~Creator();
    std::string getName();
    void printPosts();
};

#endif
