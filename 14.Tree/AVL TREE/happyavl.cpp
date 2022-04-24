
#include<iostream>
using namespace std;
struct node{
int data;
int height;
node *lchild,*rchild;
node(){
    lchild=rchild=NULL;
}
};
node *root=NULL;
class AvlTree{
    public:
node* create(node *p,int key);
node* LLRotation(node*);
int BalanceFactor(node*);
int NodeHeight(node*);
void inorder(node*);
int height(node*);
node* RRRotation(node*);
node* LRRotation(node*);
node* RLRotation(node*);
node* Delete(node*,int);
node* InOrderPre(node*);
node* InOrderSucc(node*);
};
node* AvlTree::LRRotation(node *p){
node *pl=p->lchild;
node *plr=pl->rchild;
p->lchild=plr->rchild;
pl->rchild=plr->lchild;
plr->rchild=p;
plr->lchild=pl;
p->height=NodeHeight(p);
plr->height=NodeHeight(plr);
pl->height=NodeHeight(pl);
if(p==root)
root=plr;
return plr;
}
node* AvlTree::RLRotation(node *p){
  
   node *pr=p->rchild;
node *prl=pr->lchild;
p->rchild=prl->lchild;
pr->lchild=prl->rchild;
prl->lchild=p;
prl->rchild=pr;
p->height=NodeHeight(p);
pr->height=NodeHeight(pr);
prl->height=NodeHeight(prl);
if(p==root)
root=prl;
return prl;
}
node* AvlTree::RRRotation(node *p){
      node *pr=p->rchild;
    node *prl=pr->lchild;
    pr->lchild=p;
    p->rchild=prl;
        p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
      if(p==root)
      root=pr;
   return pr;
}
node* AvlTree::InOrderPre(node *p){
    while(p && p->rchild)
    p=p->rchild;
    return p;
}
node* AvlTree::InOrderSucc(node *p){
    while(p && p->lchild)
    p=p->lchild;
    return p;
}
node* AvlTree::Delete(node* p,int key){
     if(p==NULL)
     return NULL;
     if(p->lchild==NULL && p->rchild==NULL){
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
     else{
        if(height(p->lchild)>height(p->rchild))
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
    
       p->height=NodeHeight(p);
       if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
       return LLRotation(p);
       if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
       return LRRotation(p);
       if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0)
       return LRRotation(p); //We can perform LL Rotation also
       if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
       return RLRotation(p);
       if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
       return RRRotation(p);
       
       if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==0)
       return RRRotation(p);//We can perform RL Rotation also
        
     return p;
}
int AvlTree::height(node *p){
    int x,y;
    if(p){
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y)
    return x+1;
    else
    return y+1;
    }
    return 0;
}
void AvlTree::inorder(node *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
int AvlTree::NodeHeight(node *p){
  int hl,hr;
  if(p && p->lchild)
  hl=p->lchild->height;
  else
  hl=0;
  if(p && p->rchild)
  hr=p->rchild->height;
  else 
  hr=0;
  if(hl>hr)
  return hl+1;
  else
  return hr+1;
}

int AvlTree::BalanceFactor(node *p){
     int hl,hr;
  if(p && p->lchild)
  hl=p->lchild->height;
  else
  hl=0;
  if(p && p->rchild)
  hr=p->rchild->height;
  else
  hr=0;
  return hl-hr;
}
node* AvlTree::LLRotation(node *p){
    node *pl=p->lchild;
    node *plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
        p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

      if(p==root)
      root=pl;
   return pl;
}

node* AvlTree::create(node *p,int key){
    if(p==NULL)
    {
        node *t=new node;
        t->data=key;
        t->height=1;
        return t;
    }
     if(key<p->data)
    p->lchild=create(p->lchild,key);
    else if(key>p->data)
    p->rchild=create(p->rchild,key);
      p->height=NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
    return  LLRotation(p);
     if((BalanceFactor(p)==-2) && (BalanceFactor(p->rchild)==-1))
     return RRRotation(p);
     if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1 )
     return LRRotation(p);
    if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1 )
     return RLRotation(p);
     
return p;
}

int main(){
    AvlTree t;
  root=t.create(root,10);
 t.create(root,5);
 t.create(root,20);
 t.create(root,15);
  t.create(root,30);
 t.Delete(root,5);
    cout<<root->data<<" "<<endl;
  cout<<t.height(root)<<endl;
  t.inorder(root);
}
