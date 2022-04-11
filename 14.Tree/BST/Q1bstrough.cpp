// jsg creation of a binary search tree using insertion and deletion
#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
    
    public :Node*lchild;int data;Node*rchild;
    Node(){lchild=rchild=NULL;}     
};
class BsTree
{
      public : struct Node*root;
   
    BsTree(){root=NULL;}
    void insert(int data);
    void reccinorder(Node*p);
    Node*search(int key);
    Node*reccsearch(Node*p,int key);
    int minnode(Node*p);
    int maxnode(Node*p);
};

void BsTree::insert(int data)
{
    Node*p,*t,*r=NULL;// r is a tailing pointer
    t=new Node(); t->data=data;
    if(root==NULL)
    {
        root=t;  return ;
    }
    p=root;
    while(p!=NULL)
    {
        r=p;
        if(p->data==data)// for duplicate el
        return ;
        if(p->data>data)
        {
            p=p->lchild;
        }
        else if(p->data<data)
        {
            p=p->rchild;
        }
    }
    if(r->data<data)
    r->rchild=t;
    else
     r->lchild=t;
}
void BsTree::reccinorder(Node*p)
{
    if(p!=NULL)
    {
        reccinorder(p->lchild);
        cout<<p->data<<" ";
        reccinorder(p->rchild);
    }
}
 Node* BsTree ::search(int key)// iterative search
 {
     Node*p=root;
     if(p==NULL)
     return NULL;
     while(p!=NULL)
     {
         if(p->data==key)
           return p;
           if(p->data<key){p=p->rchild;}
           else if(p->data>key){p=p->lchild;}
     }
     // if not found than return null;
     return NULL;
 }
 // 

Node* BsTree::reccsearch(Node*p,int key)
{
    if(p==NULL)
    return NULL;
   
        if(p->data==key)
        return p;
        if(p->data<key){reccsearch(p->rchild,key);}
         else if(p->data>key){reccsearch(p->lchild,key);}
    
   
}
int BsTree::minnode(Node*p)
{
  int x=INT64_MAX;Node*r=NULL;
  if(p==NULL) return x;
  // as we know in bst min node is leftmost node value
  while(p!=NULL)
  {
      r=p;
      p=p->lchild;
  }
  return r->data;

}
int BsTree::maxnode(Node*p)
{
  int x=INT64_MIN;Node*r=NULL;
  if(p==NULL) return x;
  // as we know in bst min node is leftmost node value
  while(p!=NULL)
  {
      r=p;
      p=p->rchild;
  }
  return r->data;

}
int main()
{
    BsTree b; Node*temp;
    b.insert(30);b.insert(20);b.insert(40);b.insert(10);b.insert(25);b.insert(35);b.insert(45);b.insert(42);b.insert(43);
    cout<<"\nInorder traversal :: "<<endl;
    b.reccinorder(b.root);
   /*
     temp=b.search(30);
     if(temp)
    cout<<"\nsearched ele is : "<<temp->data<<endl;
    else
    cout<<"\nElement not found : "<<endl;
    temp=b.search(47);
    if(temp)
    cout<<"\nsearched ele is : "<<temp->data<<endl;
    else
    cout<<"\nElement not found : "<<endl;/*/
    temp=b.reccsearch(b.root,30);
     if(temp)
    cout<<"\nsearched ele is : "<<temp->data<<endl;
    else
    cout<<"\nElement not found : "<<endl;
    temp=b.reccsearch(b.root,47);
    if(temp)
    cout<<"\nsearched ele is : "<<temp->data<<endl;
    else
    cout<<"\nElement not found : "<<endl;
    cout<<"Min Node value  : "<<b.minnode(b.root)<<endl;
    cout<<"Min Node value  : "<<b.maxnode(b.root)<<endl;
    
}