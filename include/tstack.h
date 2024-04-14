// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int size>
class TStack {
 private:
T data[100];
int m;

 public:
TStack() : m(-1) {}
void pup(T value) {
  if (!isFull())
    data[++m] = value;
  else
  throw std::string("Full stack");
}
T pip() const {
  return data[m];
}
T pap() {
  if (isEmpty()) {
    throw std::string("Empty stack");
  } else {
    return data[m--];
  }
}
bool isEmpty() const {
  return m == -1;
}
bool isFull() const {
  return m == size - 1;
}
};

#endif  // INCLUDE_TSTACK_H_
