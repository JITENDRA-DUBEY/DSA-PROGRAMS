/*JSG logic same as we insert in BST while inserting anew node we have to take care
about balence factor(-1,0,+1) and at (-2,2) it is imbale so we have balence it by using
rotations*/
// first lets creat a BST using recurrsion
#include<iostream>
#include<conio.h>
using namespace std;
//int NodeHeight(Node*p);
class Node//Node of Avl tree
{
    public:
   Node*lchild;
   int data;int height;
   Node*rchild;
   Node(){lchild=rchild=NULL;}
};Node*root=NULL;
class Avl
{
    public:
   // Node*root;
   // Avl(){root=NULL;}
    Node* insert(Node*p,int data);
    Node* inorder(Node*p);
    int NodeHeight(Node*p);
    int balFactor(Node*p); 
    Node*LLRotation(Node*p);
    Node*LRRotation(Node*p);
     Node*RRRotation(Node*p);
    Node*RLRotation(Node*p);
};
int Avl::NodeHeight(Node*p)
{
    int hl,hr;
    hl=p&&p->lchild?p->lchild->height:0;
    hr=p&&p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}
int Avl:: balFactor(Node*p)
{
    int hl,hr;
    hl=p&&p->lchild?p->lchild->height:0;
    hr=p&&p->rchild?p->rchild->height:0;
    return hl-hr;
}
Node* Avl:: LLRotation(Node*p)
{
    Node*pl=p->lchild;
    Node*plr=pl->rchild;//p->lchlils->rchild;
    // here we have to update 2 links
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    if(root==p)
    root=pl;//pl became root node
    return pl;
}
Node* Avl:: LRRotation(Node*p)
{
    Node*pl=p->lchild,*plr=pl->rchild;//p->lchlils->rchild;
    // here we have to update 2 links
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
     plr->height=NodeHeight(plr);
    if(root==p)
    root=plr;//plr became root node
    return plr;
}
Node* Avl:: RLRotation(Node*p)
{
    Node*pr=p->rchild,*prl=pr->lchild;//p->lchlils->rchild;
    // here we have to update 2 links
    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;
    prl->rchild=pr;
    prl->lchild=p;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
     prl->height=NodeHeight(prl);
    if(root==p)
    root=prl;//plr became root node
    return prl;
}
Node*Avl:: RRRotation(Node*p)
{
    Node*pr=p->rchild;
    Node*prl=pr->lchild;//p->lchlils->rchild;
    // here we have to update 2 links
    pr->lchild=p;
    p->rchild=prl;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    if(root==p)
    root=pr;//pl became root node
    return pr;
}

Node* Avl::insert(Node*p,int data)// insertion always done at leaf node
{
  Node*t=NULL;
  if(p==NULL)
  {
      t=new Node();
      t->data=data;
      t->height=1;//when we insert a node than assign height 1 // vvmi;
      if(root==NULL)
      {root=t;}
      //p=t;
      return t;
  }
   if(data<p->data)
     p->lchild= insert(p->lchild,data);
     else if(data>p->data)// this condtion execute when we insert pre inserted data(dup)
       p->rchild= insert(p->rchild,data);
       //here we have to update our Bst code for Avl tree;
       p->height=NodeHeight(p);
        if(balFactor(p)==2&&balFactor(p->lchild)==1)
           return LLRotation(p);
        else if(balFactor(p)==2&&balFactor(p->lchild)==-1)
              return LRRotation(p);
               else if(balFactor(p)==-2&&balFactor(p->rchild)==-1)
              return RRRotation(p);
        else if(balFactor(p)==-2&&balFactor(p->rchild)==1)
              return RLRotation(p);
       return p;
}
Node* Avl::inorder(Node*p)
{
    if(p!=NULL)
    {

      cout<<p->data <<" ";
        inorder(p->lchild);
        
        inorder(p->rchild);
    }
}
int main()
{
     Avl b;
    b.inorder(root);
    //b.insert(b.root,10);  b.insert(b.root,40); b.insert(b.root,20); b.insert(b.root,80); b.insert(b.root,30); b.insert(b.root,70);
    b.insert(root,10);  b.insert(root,40); b.insert(root,20); b.insert(root,80); b.insert(root,30); b.insert(root,70);
    cout<<"Preorder  Traversal : "<<endl;
     b.inorder(root);

}
