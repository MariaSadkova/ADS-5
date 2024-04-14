// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
TStack<char, 100> stack1;
TStack<int, 100> stack2;
int perv(char k) {
    if (k == '-') return 1;
    if (k == '+') return 1;
    if (k == '*') return 2;
    if (k == '/') return 2;
    return 0;
}
std::string infx2pstfx(std::string inf) {
    std::string post;
    TStack<char, 100> stack;
    for (char t : inf) {
        if (isdigit(t)) {
            post += t;
            post += ' ';
        } else if (t == '(') {
            stack.push(t);
        } else if (t == '+' || t == '-' || t == '*' || t == '/') {
            while (!stack.isEmpty() && perv(stack.see()) >= perv(inf[t])) {
                post = post + stack.see() + ' ';
                stack.pop();
            }
            stack.push(t);
        } else if (t == ')') {
            while (!stack.isEmpty() && stack.see() != '(') {
                post = post + stack.see() + ' ';
                stack.pop();
            }
            stack.pop();
        }
    }
    while (!stack.isEmpty()) {
        post = post + stack.see() + ' ';
        stack.pop();
    }
    if (!post.empty()) {
        post.pop_back();
    }
    return post;
}
int eval(std::string pref) {
    std::string strNumber = "";
    for (char t : pref) {
        if (t != ' ' && t != '+' && t != '-' && t != '*' && t != '/') {
            strNumber += t;
        }
        if (t == ' ') {
            if (!strNumber.empty()) {
                int numer = std::stoi(strNumber);
                stack2.push(numer);
                strNumber = "";
            }
        }
        if (t == '+' || t == '-' || t == '*' || t == '/') {
            int vt = stack2.see();
            stack2.pop();
            int per = stack2.see();
            stack2.pop();
            if (t == '+') {
                stack2.push((per + vt));
            } else if (t == '-') {
                stack2.push((per - vt));
            } else if (t == '*') {
                stack2.push((per * vt));
            } else if (t == '/') {
                stack2.push((per / vt));
            }
        }
    }
    return stack2.see();
}
