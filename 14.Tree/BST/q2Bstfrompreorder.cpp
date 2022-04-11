// JSG BST using preorder
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
};Node*root=NULL;
class Stack
{
    public :
    int top;
    int sz;
    Node**S;
    Stack(int siz)
    {
     top=-1;sz=siz;
    S=new Node*[siz];
    }
    //void create(int siz);
    void push(Node* data);
    Node* Pop();
    int topOfstack();
    void display();
};
int Stack::topOfstack()
{
   if(top==-1)
    return INT_MAX;
    return S[top]->data;
}
void Stack::push(Node*data)
{
    if(top==sz-1)
    cout<<"stack overflow "<<endl;
    else{
        top=top+1;
        S[top]=data;
    }
}
void Stack :: display()
{
    if(top==-1)
    cout<<"stack is empty "<<endl;
    else{
    int i=top;
    while(i>=0)
    {
        cout<<S[i]<<"\n";i--;
    }
    cout<<"\n";
}
}
Node* Stack::Pop()
{
    Node* x=NULL;
    if(top==-1)
    cout<<"stack underflow"<<endl;
    else{
       x=S[top];
       top=top-1;
    }
    return x;
}
class Bst
{    public :
    
    void create(int pre[],int n);
    void preorder(Node*p);
};
void Bst::create(int pre[],int n)
{//if p->data<data logic before inseryion lchild first pushg p in to stack than creat lchild of p
  //if(p->data<data&&data<topstack data than assing p->rchild =t and don't need to push data else p=popo();)
     Node*t=NULL,*p;
     Stack st(n);int i=0;
     //if(n==0) return ;//array is empty;
      st.display();
     root= new Node();
     root->data=pre[i++];
     p=root;
     while(i<n)
     {
        if(pre[i]<p->data)
        {  
            t=new Node();
            t->data=pre[i++];
            p->lchild=t;
            st.push(p);
            p=t;
           
        }   
        else if((pre[i]>p->data)&&pre[i]<(st.topOfstack()))
        {     
             t=new Node();
             t->data=pre[i++]; 
            p->rchild=t;
            p=t;
        } 
        else
        {
           p=st.Pop();
        }
     }

}
void Bst::preorder(Node*p)
{
   
    if(p!=NULL){
       
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int main()
{
    Bst b;
    int a[8]={30,20,10,15,25,40,50,45};
    b.create(a,8);
    cout<<"Preoredr value : "<<endl; 
    b.preorder(root);
   

}