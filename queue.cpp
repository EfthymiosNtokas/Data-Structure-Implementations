#include <iostream>

using namespace std;
class queue {
public:
   queue();
   bool empty();
   void enqueue(int x);
   int dequeue();
private:
    struct node {
       int info;
       node *next;
    };
    node *front, *rear;
};
queue::queue(){
   front = rear = nullptr;
}
bool queue::empty(){
   return front == nullptr;
}
void queue::enqueue(int x){
   node *n = new node;

   n->info = x;
   n->next = nullptr;
   if(front == nullptr)
    {front = n;}
   else
   {rear->next = n;}
   rear = n;

}
int queue::dequeue(){
   int result = front->info;
   node *p = front;
   if(front == rear){rear = nullptr;}
   front = front->next; //it is assumed the queue is not emplty

   delete p;
   return result;
}


int main()
{
    return 0;
}