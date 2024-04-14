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
    TStack(): m(-1) {}
    void push(T vl) {
      if (!isOverflow())
        data[++m] = vl;
      else
        throw std::string("Fall stack");
    }
    T pop() {
      if (isEmpty())
        throw std::string("Empty stack");
      else
        return data[m--];
    }
    T see() {
     if (m > 0)
      return data[m - 1];
     else
      return -1;
    }
    bool isOverflow() const {
      return m == size - 1;
    }
    bool isEmpty() const {
      return m == -1;
    }
};
#endif  // INCLUDE_TSTACK_H_
