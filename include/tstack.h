// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T* stackM;
    int t;
 public:
   TStack() : t(0) {
     stackM = new T[size];
   }
   void Pup(const T& v) {
     if (t <= size - 1) {
      stackM[t++] = v;
     } else {
       throw std::string(“FALL STACK”);
     }
   }
   T Pip() {
     if (t > 0) {
      return stackM[--t];
     } else{
        throw std::string("EMPTY STACK");
     }
   }
   bool Pap() const{
     eturn t == 0;
   }
   T Pep() const{
     if (t > 0) {
       return stackM[t – 1];
     } else {
        throw std::string(“FALL STACK”);
     }
   }
};
#endif // INCLUDE_TSTACK_H_

