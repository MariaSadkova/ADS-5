// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int size>
class TStack {
 private:
T data[100];
int t;

 public:
TStack() : t(-1) {}
void pup(T value) {
  if (!isFull())
    data[++t] = value;
  else
  throw std::string("Full stack");
}
T pip() const {
  return data[t];
}
T pap() {
  if (isEmpty()) {
    throw std::string("Empty stack");
  } else {
    return data[t--];
  }
}
bool isEmpty() const {
  return t == -1;
}
bool isFull() const {
  return t == size - 1;
}
};

#endif  // INCLUDE_TSTACK_H_
