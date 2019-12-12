#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date {
    int day, month, year;
  public:
    Date(std::string str);
    ~Date();
    std::string to_string();
};

#endif
