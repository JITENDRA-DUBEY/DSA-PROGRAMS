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
    return INT_MIN;
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
    //Node* x=NULL;
    if(top==-1)
    cout<<"stack underflow"<<endl;
    return S[top--];
}
class Bst
{    public :
    
    void create(int post[],int n);
    void postorder(Node*p);
};
void Bst::create(int post[],int n)
{//if p->data<data logic before inseryion lchild first pushg p in to stack than creat lchild of p
  //if(p->data<data&&data<topstack data than assing p->rchild =t and don't need to push data else p=popo();)
     Node*t=NULL,*p;
     Stack st(n);int i=n-1;
     //if(n==0) return ;//array is empty;
     root= new Node();
     root->data=post[i--];
     p=root;
     while(i>=0)
     {
        if(post[i]>p->data)
        {  
            t=new Node();
            t->data=post[i--];
            p->rchild=t;
            st.push(p);
            p=t;
           
        }   
        else if((post[i]<p->data)&&post[i]>(st.topOfstack()))
        {     
             t=new Node();
             t->data=post[i--]; 
            p->lchild=t;
            p=t;
        } 
        else
        {
           p=st.Pop();
        }
     }

}
void Bst::postorder(Node*p)
{
   
    if(p!=NULL){
        
         
    
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }   
}
int main()
{
    Bst b;
    int a[8]={15,10,25,20,45,50,40,30};
    b.create(a,8);
    cout<<"Postoredr value : "<<endl; 
    b.postorder(root);
}