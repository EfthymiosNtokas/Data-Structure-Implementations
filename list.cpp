#include <iostream>
#include <cstdio>
struct node{
    int info;
    node *next;
};
using namespace std;
class list {
public:
    list(); //default constructor
    bool empty(); //check if the list is emplty
    int size ();//return the size of the list
    void add(int k, int x);//add the element "x" in position k
    int get(int k); //return the element in the kth position
    void remove(int k);//remove the element in the kth position
    int searchMF(int x); //returns the position of number x in the list and
     //places it in front. If it is not found it returns 0

private:
    struct node {
        int info;
        node *next;
    };
    node *head;
    int sizee = 0;

};
list::list(){
    head = nullptr;
}
bool list::empty(){
    return head == nullptr;
}
int list::size(){
    return sizee;
}
void list::add(int k, int x){
    if(k!= 1){
        node *p = head;
        for(int f = 1; f < k-1; f++){
            p = p->next;
        }
        node *n = new node;
        n->next = p->next;
        p->next = n;
        n->info = x;

    }else {
        node *n = new node;
        n->next = head;
        head = n;
        n->info = x;
    }
    sizee++;
}
int list::get(int k){
    node *n = head;
    for(int i = 1; i < k; i++){
        n = n->next;
    }
    return n->info;
}
void list::remove(int k){
    node *p = new node;
    p = head;
    if(k!=1){
        for(int i = 1; i < k-1; i++){
            p = p->next;
        }
        node *q = p->next;
        if(q == nullptr){
            p->next = nullptr;
            delete p;
        }else{
            p->next = q->next;

            delete q;
        }
    }else {
        head = p->next;
        delete p;
    }
    sizee--;
}
int list::searchMF(int x){
    node *p = head;
    int k = 1;
    if(head == nullptr)return 0;
    while(p!= nullptr && p->info != x ){
        p = p->next;
        k++;
    }
    if(p==nullptr) return 0;
    else{if(k!=1){
            remove(k);
            node *n = new node;
            n->info = x;
            n->next = head;
            head = n;
            return k;
        }
        else return 1;
    }
}
int main()
{
    
    return 0;
}
