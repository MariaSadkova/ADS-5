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
    void pushh(T vl) {
      if (!isOverflow())
        arr[++m] = vl;
      else
        throw std::string("Fall stack");
    }
    T popp() {
      if (isEmptyy())
        throw std::string("Empty stack");
      else
        return arr[m--];
    }
    bool isOverflow() const {
      return m == size - 1;
    }
    bool isEmptyy() const {
      return m == -1;
    }
};
#endif  // INCLUDE_TSTACK_H_
