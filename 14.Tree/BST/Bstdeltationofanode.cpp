// jdf BST Bug when we delete a node which is not presnt and less than from largest ele
#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
 public: Node*lchild; int data; Node*rchild;
  Node(){lchild=rchild=NULL;}
};
class Bst
{
   public : Node*root;
   Bst(){root=NULL;}
    void insert(int data);
    Node* reccinsert(Node*p,int data);// i have a doubt in this function
    Node* search(int key);
    void inorder(Node *t);
    Node* reccsearch(Node *p,int key);
    Node*Delete(Node*p,int key);
    int Height(Node*p);
    Node*inpre(Node*p);
    Node*insucc(Node*p);
    int minnode(Node*p);
    int maxnode(Node*p);

}; //Bst*root=NULL;
void Bst::insert(int data)
{
   Node*t,*p,*r=NULL;// r is tailing pointer
   t=new Node();
   t->data=data;
   if(root==NULL)
   {
       root=t;return;
   }
   p=root;
   while(p!=NULL)
   {    r=p;
       if(data==p->data) return ;// when duplicate ele found
       if(data<p->data)
       {
         p=p->lchild;
       }
       else if(data>p->data)
       {
           p=p->rchild;
       }
   }
   
     if(data>r->data) 
       r->rchild=t;
       else
       r->lchild=t; 

}
// recurssive version of insertion ;

void Bst :: inorder(Node* t)
{
    if(t!=NULL)
    {
        inorder(t->lchild);
         cout<<t->data<<" ";
        inorder(t->rchild);
    }
}
Node* Bst ::reccinsert(Node*p,int data)
{
   Node*t=new Node();
   t->data=data;
   if(p==NULL)
   {
       return t ;  //address of newly inserted node
   }
   if(data<p->data)
   {
       p->lchild=reccinsert(p->lchild, data);
   }
   else if(data>p->data)
   {
       p->rchild=reccinsert(p->rchild, data); 
   }
   return p;
}
Node* Bst ::search(int key)
{
    Node*p=root;
    if(root==NULL)
    return NULL;
    while(p!=NULL)
    {
        if(key==p->data)
        return p;
        if(key<p->data)
        p=p->lchild;
        else if(key>p->data)
        {
            p=p->rchild;
        }
    } return NULL;// when element not found
}
Node* Bst :: reccsearch(Node *p,int key)
{
    if(p==NULL)
    return NULL;
    if(p->data==key)
    return p;
    if(p->data<key)
     return reccsearch(p->rchild,key);
    else if(p->data>key)
    return  reccsearch(p->lchild,key);
}
int Bst::Height(Node*p)
{
    if(p==NULL)return 0;
    int x,y;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}
Node* Bst::inpre(Node*p)// rightmost child of lst
{   //p=p->lchild;
   while(p&&p->rchild!=NULL)
   p=p->rchild;
   return p;
}
Node* Bst::insucc(Node*p)// leftmost child of rst
{  //p=p->rchild;
   while(p&&p->lchild!=NULL)
   p=p->lchild;
   return p;
}
Node* Bst::Delete(Node*p,int key)
{
    Node*q;
    if(p==NULL)return NULL;// there is no node;
    if(p->lchild==NULL&&p->rchild==NULL)//leaf Node
    {
        if(p==root)// if there is only single node and that is root node
        root=NULL; delete(p);
        return NULL;
    }
    //like searching
    if(key<p->data)
    p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
    p->rchild=Delete(p->rchild,key);
    else  {// when key==p->data
       
       if(Height(p->lchild)>Height(p->rchild))
       {// find inorder preceder
           q=inpre(p->lchild);
           p->data=q->data;
           //again caall delete function so that inorderprecedor remains
           p->lchild=Delete(p->lchild,q->data);
       }
       else
       {// find inorder preceder
           q=insucc(p->rchild);
           p->data=q->data;
           //again caall delete function so that inorderprecedor remains
           p->rchild=Delete(p->rchild,q->data);
       }
    }
    
   return p;
}
int Bst::minnode(Node*p)
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
int Bst::maxnode(Node*p)
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
    Bst  b;int i=1;
   
     
    /* b.root=b.reccinsert(b.root,9);
    b.reccinsert(b.root,5);b.reccinsert(b.root,15);b.reccinsert(b.root,3);b.reccinsert(b.root,8);b.reccinsert(b.root,12);b.reccinsert(b.root,20);b.reccinsert(b.root,16);b.reccinsert(b.root,6);
    cout<<"Inorder traversal value :: "<<endl;/*
    b.inorder(b.root);/*/
  b.insert(9);b.insert(5);b.insert(15);b.insert(3);b.insert(8);b.insert(12);b.insert(20);b.insert(16);b.insert(6);
    std::cout<<"Inorder traversal value :: "<<endl;
    b.inorder(b.root);
   /* Node*temp=b.search(2);
    if(temp)
    cout<<"\nsearched ele is : "<<temp->data<<endl;
    else
    cout<<"\nElement not found : "<<endl;
     temp=b.search(20);
    if(temp)
    cout<<"\nsearched ele is : "<<temp->data<<endl;
    else
    cout<<"\nElement not found : "<<endl;
    Node*temp=b.reccsearch(b.root,12);
    if(temp)
    cout<<"\nsearched ele is : "<<temp->data<<endl;
    else
    cout<<"\nElement not found : "<<endl;
     temp=b.reccsearch(b.root,2);
    if(temp)
    cout<<"\nsearched ele is : "<<temp->data<<endl;
    else
    cout<<"\nElement not found : "<<endl;*/
    //cout<<"Min Node value  : "<<b.minnode(b.root)<<endl;
    //cout<<"Min Node value  : "<<b.maxnode(b.root)<<endl;
     b. Delete(b.root,2);// herer it showing error i have to fix this
    cout<<"\nInorder traversal value :: "<<endl;
    b.inorder(b.root);
    cout<<"Min Node value  : "<<b.minnode(b.root)<<endl;
    cout<<"Min Node value  : "<<b.maxnode(b.root)<<endl;
}