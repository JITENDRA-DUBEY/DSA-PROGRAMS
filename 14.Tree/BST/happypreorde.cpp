#include<iostream>
#include<limits.h>
using namespace std;
class Node
{
    public:
int data;
Node* lchild;
Node *rchild;
public:
Node(){
    lchild=rchild=NULL;
} 
};
Node*root=NULL;
class Stack{
int size;
int top;
Node **S;
public:
Stack(int n){
    top=-1;
    size=n;
    S=new Node*[size];
}
void Push(Node *data){
    if(top==size-1)
     cout<<"Stack Overflow \n";
     else
S[++top]=data;
}
Node* Pop(){
 if(top==-1)
   cout<<"Stack Underflow \n";
 return S[top--];
}
int TopStack(){
    if(top==-1)
    return INT_MAX;
    return S[top]->data;
}
int TopStack2(){
    if(top==-1)
    return INT_MIN;
    return S[top]->data;
}
bool IsEmpty(){
  if(top==-1)
  return true;
  else
  return false;
}
};
class Bst
{    public :
    
    //Bst(){root=NULL;}
    void create(int a[],int n);
    void preorder(Node*p);
};
void Bst::create(int pre[],int n)
{ 
    Stack stk(100);
  Node *t,*p;
  p=new Node();
  p->data=pre[0];
  root=p;
  int i=1;
  while(i!=n){
      if(pre[i]<p->data){
          t=new Node;
          t->data=pre[i++];
          p->lchild=t;
          stk.Push(p);
          p=p->lchild;
          p=t;
      }
      else{
          if(pre[i]>p->data && pre[i]<stk.TopStack()){
              t=new Node;
              t->data=pre[i++];
              p->rchild=t;
              p=p->rchild;
          }
          else{
              p=stk.Pop();
          }
      }
  }
}
void Bst::preorder(Node*p)
{
   
    if(p!=NULL){
       
        preorder(p->lchild);
         cout<<p->data<<" ";
        preorder(p->rchild);
    }
}
int main()
{
    Bst b;
    int a[6]={2,5,4,3,7,6};
    b.create(a,6);
    cout<<"Preoredr value : "<<endl; 
    b.preorder(root);}