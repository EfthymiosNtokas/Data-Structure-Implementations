#include <iostream>
using namespace std;
template <typename T>
class stack{
public:
    stack(int size): top(0), mysiz(0){a = new T[size]; act_size = size;}
    stack(const stack &s){
        mysiz =s.mysiz;
        act_size = s.act_size;
        a = new T[act_size];
        for(int i = 0; i < mysiz; i++){
            a[i] = s.a[i];
        }
        top = act_size;
    };
    ~stack(){
        int f = 1;
    };
    const stack &operator = (const stack &s){
        mysiz =s.mysiz;
        act_size = s.act_size;
        a = new T[act_size];
        for(int i = 0; i < mysiz; i++){
            a[i] = s.a[i];
        }
        top = act_size;
        return *this;

    };
    bool empty(){
        return top == 0;
    };
    void push(const T &x){
        a[top++]=x;
        mysiz++;
    };
    T pop(){
        mysiz--;
        return a[--top];
    };
    int size(){
        return mysiz;
    };
    friend ostream &operator << (ostream &out, const stack &s){
        out << "[";
        for(int i = 0; i < s.mysiz-1; i++){
            out << s.a[i] <<", ";
        }
        if(s.mysiz==0){
            out << "]";
        }else{
            out << s.a[s.mysiz-1] << "]";}
        return out;

    };
private:
    int top;
    int mysiz;
    int act_size;
    T *a;
};