#include<iostream>
using namespace std;
class node{
    public:
int data;
node* lchild;
node *rchild;
public:
node(){
    lchild=rchild=NULL;
}
};
node *root=NULL;
class BST{
    public:
void Icreate(int);
void inorder(node*);
node* search(node*,int);
node* Isearch(node*,int);
node* create(node*,int);
node* Delete(node*,int);
int Height(node*);
node* InOrderPre(node*);
node* InOrderSucc(node*);

};
node *inPre(node *root){
    root=root->lchild;
    while(root->rchild!=NULL)
    root=root->rchild;
    return root;
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
node* BST::Delete(node* p,int key){
     if(p==NULL)
     return NULL;
     if(p->lchild==NULL && p->rchild==NULL && p->data==key){
         if(p==root)
         root=NULL;
         delete p;
         return NULL;
     }
     node *q;
     if(key<p->data)
     p->lchild=Delete(p->lchild,key);
     else if(key>p->data)
     p->rchild=Delete(p->rchild,key);
     else if(key==p->data){
        if(Height(p->lchild)>Height(p->rchild))
        {
          q=InOrderPre(p->lchild);
          p->data=q->data;
          p->lchild=Delete(p->lchild,q->data);
        }
        else{
             q=InOrderSucc(p->rchild);
          p->data=q->data;
          p->rchild=Delete(p->rchild,q->data);
        }
     }
     return p;
}
node* BST::create(node* root,int key){
        if(root==NULL){
            node *p=new node;
            p->data=key;
            return p;
        }
         if(key<root->data)
        root->lchild=create(root->lchild,key);
        else if(key>root->data)
        root->rchild=create(root->rchild,key);
        return root; //For duplicating element return adress of same node only
}
node* BST::Isearch(node *root,int key){
    while(root){
        if(root->data==key)
        return root;
        else if(key<root->data)
        root=root->lchild;
        else
        root=root->rchild;
    }
    return NULL;
}
node* BST::search(node*root,int key){
    if(root==NULL)
    return NULL;
    if(root->data==key)
    return root;
    else if(key<root->data)
     search(root->lchild,key);
    else
    search(root->rchild,key);
}

void BST::inorder(node *p){
    if(p){
    inorder(p->lchild);
    cout<<p->data<<" ";
    inorder(p->rchild);
    }
}
void BST::Icreate(int key){
    node *t=root,*r=NULL;
  if(root==NULL){
      t=new node;
     t->data=key;
     root=t;
     return ;
  }
  while(t){
      r=t;
      if(t->data==key)
      return;
  if(key<t->data)
  t=t->lchild;
  else
  t=t->rchild;
}
  t=new node();
  t->data=key;
  if(key<r->data)r->lchild=t;
  else
  r->rchild=t;
}
int main(){
    node *p;
    int x;
  BST t;
   root=t.create(root,10);
    t.create(root,40);
    t.create(root,20);
    t.create(root,80);
    t.create(root,30);
    t.create(root,70);
    t.inorder(root);
    cout<<endl;
     t.Delete(root,10);
     cout<<endl;
    t.inorder(root);
    p=t.search(root,30);
    cout<<endl;
    cout<<p->data<<" ";
}