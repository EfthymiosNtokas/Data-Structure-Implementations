#include <iostream>
#include <cstdio>
using namespace std;
struct node{
   int info;
   node *left;
   node *right;
};
class bstree{
public:
    bstree(); //default constructor
    int height();//returns the height
    void insert(int x);//inserts x
    int search(int x);//searches for x
    int min();//returns the minimum element
    int max();//returns the maximum element
    void inorder();//prints the elements inorder
    void preorder();//prints teh elements preorder
    void postorder();//prints the elements postorder
private:

    node *root;

};
bstree::bstree(){
  root = nullptr;
}
int height_aux(node *t){
    if(t==nullptr) return 0;
    if(t ->left == nullptr && t->right == nullptr) return 1;
    else {
        return 1+max(height_aux(t->right), height_aux(t->left));
    }
}
int bstree::height(){
   node *p = root;
   if(p == nullptr) return 0;
   else{
    return height_aux(root);
   }

}
void bstree::insert(int x){
   node *n = new node;
   if(root == nullptr){
     n->info = x;
     n->right = n->left = nullptr;
     root = n;
   }
   else{
      n = root;
      while(true){

        if(n->info > x){
            if(n->left == nullptr){
                node *p = new node;
                n->left = p;
                p->info = x;
                p->left = p->right = nullptr;
                break;
            }
            n = (n->left);
        }
        else if(n->info < x){
            if(n->right == nullptr){
                node *p = new node;
                n->right = p;
                p->info = x;
                p->left = p->right = nullptr;
                break;
        }  n = n->right;
        }else{
            break;
        }
      }
   }
}
int bstree::search(int x){
   node *p = root;
   int k = 1;
   while(true){
   if(p == nullptr) return 0;
   if(p->info == x) return k;
   if(p->info > x) {p = p->left; k++;}
   else {p = p->right; k++;}
   }
}
int bstree::min(){
   node *n = root;
   while(n->left != nullptr){
     n = n->left;
   }
   return n->info;
}
int bstree::max(){
   node *n = root;
   while(n->right != nullptr){
      n = n->right;
   }
   return n->info;
}
void inorder_aux(node *ro){
   if(ro != nullptr){
   inorder_aux(ro->left);
   printf("%d ", ro->info);
   inorder_aux(ro->right);
   }
}
void bstree::inorder(){
    inorder_aux(root);
}
void preorder_aux(node *ro){
   if(ro != nullptr){
   printf("%d ", ro->info);
   preorder_aux(ro->left);
   preorder_aux(ro->right);
   }
}
void bstree::preorder(){
    preorder_aux(root);
}
void postorder_aux(node *ro){
  if(ro!=nullptr){
    postorder_aux(ro->left);
    postorder_aux(ro->right);
    printf("%d ", ro->info);
  }
}
void bstree::postorder(){
   postorder_aux(root);
}


int main()
{
    
    return 0;
}
