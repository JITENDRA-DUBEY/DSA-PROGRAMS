// jsg Bst 
#include<iostream>
#include<conio.h>
using namespace std;
class Node
{   
    public:
    Node*lchild;int data;Node*rchild;
    Node()
    {lchild=rchild=NULL;}   
};
Node*root=NULL;
class Bst
{
    public://Node*root;
    //Bst(){root=NULL;}
    void insert (int data);
    void inorder(Node*p);void preorder(Node*p);
    Node* reccsearch(Node*p,int key);
    Node*deleted(Node*p,int key);
    int Height(Node*p);
    Node*inorderpre(Node*p);
    Node*inordersucc(Node*p);
};
Node* Bst::inorderpre(Node*p)
{
    while(p&&p->rchild)
    p=p->rchild;
    return p;
}
Node* Bst::inordersucc(Node*p)
{
    while(p&&p->lchild)
    p=p->lchild;
    return p;
}
int Bst::Height(Node*p)
{   int x,y;
    //if(p==NULL)return 0;
    if(p!=NULL)
    {
        x=Height(p->lchild);
        y=Height(p->rchild);
        return (x>y)?x+1:y+1;
     }
}
void Bst::insert(int data)
{
   Node *t=root,*r=NULL;
  if(root==NULL){
      t=new Node;
     t->data=data;
     root=t;
     return ;
  }
  while(t){
      r=t;
      if(t->data==data)
      return;
  if(data<t->data)
  t=t->lchild;
  else
  t=t->rchild;
}
  t=new Node();
  t->data=data;
  if(data<r->data)r->lchild=t;
  else
  r->rchild=t;
} 
void Bst::inorder(Node*p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
void Bst::preorder(Node*p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
Node* Bst::reccsearch(Node*p,int key)
{
    if(p==NULL)return NULL;
    if(p->data==key)
    return p;
    if(key<p->data)
    reccsearch(p->lchild,key);
    else if(key>p->data)
    reccsearch(p->rchild,key);
}
Node*Bst::deleted(Node*p,int key)//we are here using reccdelete 
{
    Node*q;
    if(p==NULL) return NULL;
    if(p->lchild==NULL&&p->rchild==NULL)// this is condition for leaf node
    {
        if(p==root)// that is root is not find
        {
          root=NULL;
          delete(p);
          return NULL;
        }
    }
    //like searching conditon
    if(key<p->data)
      p->lchild=deleted(p->lchild,key);
      else if (key>p->data)
      {
            p->rchild=deleted(p->rchild,key);
      }
      else{// if(key==p->data than we have delete and take care about the rest nodes by using inrder pre succ)
          if(Height(p->lchild)>Height(p->rchild))
          {// inorder pre
            q=inorderpre(p->lchild);
            p->data=q->data;
            p->lchild=deleted(p->lchild,q->data);
          }
          else
           {// inorder pre
            q=inordersucc(p->rchild);
            p->data=q->data;
            p->rchild=deleted(p->rchild,q->data);
          }
      }
      
   return p; 
}
int main()
{
    Bst b;Node*temp,*w;
    b.insert(10);
    b.insert(3); b.insert(5); b.insert(6); b.insert(7); b.insert(50);
    //cout<<"Preorder Traversal : "<<endl; 
   // b.preorder(b.root);
    cout<<"\nInorder Traversal : "<<endl; 
    b.inorder(root);
   /* temp=b.reccsearch(b.root,1);
    if(temp!=NULL)
    cout<<"\nserched data : "<<temp->data<<endl;
    else
    cout<<"\nNo element found : -1"<<endl;*/
  
   w=b.deleted(root,6);
    b.inorder(root);
   
   if(w!=NULL)
   {
        cout<<"\ndeleted data : "<<w->data<<endl;
   }
   else
   cout<<" NO";
 
}