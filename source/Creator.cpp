#include "Creator.hpp"

using namespace std;

Creator::Creator(string n):name(n),posts() {
}

Creator::~Creator() {}

std::string Creator::getName() {
  return name;
}
