// jsg//whole codeis correct recuserach gave error
#include<iostream>
using namespace std;
class node{
    public:
node* lchild;
int data;
node *rchild;
public:
node(){
    lchild=rchild=NULL;}

};
node *root=NULL;
class BST{
    public:
void Icreate(int);
void inorder(node*);
node* Rsearch(node*,int);
node* Isearch(node*,int);
node* Rcreate(node*,int);
node* Delete(node*,int);
int Height(node*);
node* InOrderPre(node*);
node* InOrderSucc(node*);
};
// jsg 
node* BST::Rcreate(node*p,int data)//insertion always done at leaf node that is when p is null
{
    node*t;
    if(p==NULL)// that is there is no node so insertionm happining at root node
    {
        t= new node();
        t->data=data;
        if(root==NULL)//this step for assign the address in root node
        root =t;
        return t;
    }
    if(p->data==data) return NULL;// not inserting a duplicate element
    if(data<p->data)
    {
        p->lchild=Rcreate(p->lchild,data);
    }
    else if(data>p->data)
    {
         p->rchild=Rcreate(p->rchild,data);
    }
}
void BST::inorder(node *p){
    if(p){
    inorder(p->lchild);
    cout<<p->data<<" ";
    inorder(p->rchild);
    }
}
node*BST::Isearch(node*p,int key)
{ 
   while(p!=NULL)
   {
       if(p->data==key)
       return p;
       if(key<p->data)
       p=p->lchild;
       else  
       p=p->rchild;
   }
   return NULL;// when element not found

}
void BST::Icreate(int data)
{
    node*p,*r=NULL,*t;
    t=new node();
    t->data=data;
    if(root==NULL)// there is no node
     {
       root=t; return;
     }
     p=root;
     while(p!=NULL)// for foinding leadf node r is taling pointer
     {
         r=p;
         if(data==p->data) return ;//for dublicate ele;
          if(data<p->data)
        {
        p=p->lchild;
        }
    else if(data>p->data)
         {
           p=p->rchild;
        }
     }
     if(data<r->data)
     r->lchild=t;
     else
     r->rchild=t;
}
node*BST::Rsearch(node*p,int key)// there is sum bug
{
    if(p==NULL)   return NULL;
  if(p->data==key)
  return p;  
    if(key<p->data)
    Rsearch(p->lchild,key);
    else  //if(key>root->data)
     {Rsearch(p->rchild,key);}
   
}
node* BST ::Delete(node*p,int key)
{
    node*q;
    if(p==NULL) return NULL;
    if(p->lchild==NULL&&p->rchild==NULL&&p->data==key)
    {
        if(p==root)// there is only single root
            root=NULL;
            //if(p->data==key)// this is very very most imp line otherwise ut delete some unwanted result 
           //// here it gave error when we del 75;
             //{ 
                 delete p;
            return NULL;//}
        
    }
        // like searching
       if(key<p->data)
     p->lchild=Delete(p->lchild,key);
     else if(key>p->data)
     p->rchild=Delete(p->rchild,key);
     else{
         if(Height(p->lchild)>Height(p->rchild))
         {
             q=InOrderPre(p->lchild);
             p->data=q->data;//copying inorder data in to p
             p->lchild=Delete(p->lchild,q->data);// for remaing node
         }
          else{
             q=InOrderSucc(p->rchild);
          p->data=q->data;
          p->rchild=Delete(p->rchild,q->data);
        }
     }
     return p;
}
node* BST::InOrderPre(node *p){
    while(p && p->rchild)
    p=p->rchild;
    return p;
}
node* BST::InOrderSucc(node *p){
    while(p && p->lchild)
    p=p->lchild;
    return p;
}
int BST::Height(node *p){
    int x,y;
    if(p){
        x=Height(p->lchild);
        y=Height(p->rchild);
        if(x>y)
        return x+1;
        else
        return y+1;
    }
    return 0;
}
int main(){
    node *temp;
    int x;
  BST t;
   /*t.Rcreate(root,3);
   t.Rcreate(root,5);
   t.Rcreate(root,6);
   t.Rcreate(root,3);
   t.Rcreate(root,4);
   cout<<"\nInoreder Traversal : "<<endl;
   t.inorder(root);
     //t.Delete(root,2);
      cout<<"\nInoreder Traversal : "<<endl;
    t.inorder(root);/*/
   /*  t.Icreate(3);
   t.Icreate(5);
   t.Icreate(6);
   t.Icreate(3);
   t.Icreate(4);
   cout<<"\nInoreder Traversal : "<<endl;
   t.inorder(root);
     t.Delete(root,7);
      cout<<"\nInoreder Traversal : "<<endl;
    t.inorder(root);/*/
    t.Icreate(10);
   t.Icreate(40);
   t.Icreate(20);
   t.Icreate(80);
   t.Icreate(30); t.Icreate(70);
   
    
     t.inorder(root);
     t.Delete(root,75);
     cout<<"\n";
    t.inorder(root);

  temp=t.Isearch(root,40);
  if(temp)
  cout<<"\n data : "<<temp->data<<endl;
  else
  cout<<"\nNo";
}