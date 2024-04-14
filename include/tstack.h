// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
template<typename T, int size>
class TStack {
 private:
    T* stackM;
    int t;
 public:
    TStack() : t(-1), stackM(new T(size)) {}
    char Pr(void) {
        if (IsEmpty()) throw std::string("EMPTY!");
        else
            return stackM[t];
    }
    void Pup(T value) {
        if (t == size - 1) {
            throw std::string("FULL!");
        } else {
            t++;
            stackM[t] = value;
        }
    }
    const T& Pip() {
        if (IsEmpty()) {
            throw std::string("EMPTY!");
        }
        t--;
        return stackM[t + 1];
    }
    bool IsEmpty() {
        if (t == -1) return true;
        else
            return false;
    }
};
#endif // INCLUDE_TSTACK_H_
