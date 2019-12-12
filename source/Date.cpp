#include "Date.hpp"

#include <iostream>
#include <string>

using namespace std;

//input i.e 2019-12-12
Date::Date(std::string str)
:year(stoi(str.substr(0,4))),month(stoi(str.substr(5,2))),day(stoi(str.substr(8,2))) {
  if(month > 12 || month < 1 || day < 0 || day >31) {
    cerr << "Invalid date created " << str << endl;
  }
}

Date::~Date() {}

std::string Date::to_string() {
  return std::to_string(year)+"-"+std::to_string(month)+"-"+std::to_string(day);
}
