//
// Created by antis on 3/3/2021.
//
#include <iostream>
using namespace std;
#ifndef STACKS_DEMO_STACKDEMO_H
#define STACKS_DEMO_STACKDEMO_H

#endif //STACKS_DEMO_STACKDEMO_H
template <typename T>
class stack{
public:
    stack(int size);
    stack(const stack &s);
    ~stack();
    const stack &operator = (const stack &s);
    bool empty();
    void push(const T &x);
    T pop();
    int size();
    friend ostream &operator << (ostream &out, const stack &s)
};