#ifndef THREAD_HPP
#define THREAD_HPP

#include <string>
#include <map>
#include "Post.hpp"

class Thread {
    std::string subject, creator;
    Date date;
    std::map<int,Post*> posts;
  public:
    Thread(std::string subject, std::string creator, std::string date);
    ~Thread();
    std::string getSubject() const;
    void addPost(Post*);
    Post* getPost(int id);
    void print();
};

#endif
