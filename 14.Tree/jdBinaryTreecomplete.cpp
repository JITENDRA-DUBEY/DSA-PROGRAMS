/* JSG Binary Tree Creation complete 
1.first create a Queue by using ll ll data contain the address of node trees;.
2.create a class tree/*/
#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
    public:
    Node*lchild;
    int data;Node*rchild;
    Node(){data=0;lchild=rchild=NULL;}
    
};//Node*root=NULL;
class nodeQ// this is linked list node which store the adress of tree nodes
{
    public:
    Node* data;
    nodeQ*next;
    nodeQ(){data=NULL;next=NULL;}
    //nodeQ(nodeQ** data){this->data=data;next=NULL;}
};

class Queue
{
   public:
   nodeQ*front,*rear;
   Node*data;
   Queue(){front=rear=NULL;}  
   void enQueue(Node*data);
   Node* deQueue();
   int isEmpty();
};
void Queue::enQueue(Node* data)//insertion from rare
{
    nodeQ*t=new nodeQ();
    t->data=data;
    if(front==NULL)
    {  
        front=rear=t;
    }
    else{
        rear->next=t;
        rear=t;
    }
}
Node* Queue::deQueue()
{
    Node* x=NULL;
   if(front==NULL)
   return x;
   nodeQ*temp=front;
   x=front->data;
   front=front->next;
   delete temp;
   return x;
}
int Queue::isEmpty()
{
    if(front==NULL)
    return 1;
    else 
    return 0;
}
// Jsg
class Tree
{
    //private:
    //Queue q;
    public:
    Node*root;
    Tree(){root=NULL;}
    void create();
    void preorder(Node*p);
    void inorder(Node*p);
    void postorder(Node*p);
    void itrpreorder(Node*p);
    void itrinorder(Node*p);
    void itrpostorder(Node*p);
    void levelordertrav(Node*p);
    int Countnode(Node*p);
    int sumNode(Node*p);
    int heightofTree(Node*p);
     int nodedeg2(Node*p);
     int leafNode(Node*p);
     int degonenode(Node*p);
};
void Tree::create()
{
    Node*p,*t;  int x;
    //or we can also create a object of queue here
     Queue q;
    cout<<"Enter the root data "<<endl;
    cin>>x;
    root=new Node();
    root->data=x;
    //root->lchild=root->rchild=NULL;
    q.enQueue(root);
    while(!(q.isEmpty()))
    {
        p=q.deQueue();
        cout<<"enter the value of left node of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node();
            t->data=x;
            p->lchild=t;
            q.enQueue(t);
        }
         cout<<"enter the value of ryt node of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node();
            t->data=x;
            p->rchild=t;
            q.enQueue(t);
        }
    }


}
void Tree::preorder(Node*p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void Tree::inorder(Node*p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
void Tree::postorder(Node*p)
{
    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}
class stack
{
    public:
    nodeQ*top;
    stack(){top=NULL;}
    void push(Node*data);
    Node*pop();
    int isEmpty();
};
void stack::push(Node*data)
{
    nodeQ*t=new nodeQ();
    // insertion always before first node;
              t->data=data;
              t->next=top;
              top=t;
}
Node* stack::pop()
{
    Node* x=NULL;
    if(top==NULL){return NULL;}
    else
    {
        nodeQ*temp=top;
        x=top->data;
        top=top->next;
        delete temp;
    }
    return x;
}
int stack :: isEmpty()
{
    if(top==NULL){return 1;}
    else 
    return 0;
}
void Tree::itrpreorder(Node*p)
{
    stack st;
    while(p!=NULL||!(st.isEmpty()))
    {
        if(p!=NULL)
        {
            cout<<p->data <<" ";
            st.push(p);
            p=p->lchild;
        }
        else{
            p=st.pop();
            p=p->rchild;
        }
    }
}
void Tree::itrinorder(Node*p)
{
    stack st;
    while(p!=NULL||!(st.isEmpty()))
    {
        if(p!=NULL)
        {
           
            st.push(p);
             p=p->lchild;
        }
        else{
            p=st.pop();
            cout<<p->data <<" ";
            p=p->rchild;
        }
    }
}
void Tree::itrpostorder(Node*p)
{
    stack st;
     long int x;
    while(p!=NULL||!(st.isEmpty()))
    {
        if(p!=NULL)
        {
           
            st.push(p);
             p=p->lchild;
        }
        else{
            x=(int)st.pop();
            if(x>0)
            {   
                st.push((Node*)(-x));
                p=((Node*)x)->rchild;
            }
            else{
                  p=(Node*)(-x);
              cout<<p->data <<" ";
              p=NULL;
        }
    }
}
}
void Tree::levelordertrav(Node*p)
{
    Queue ql;
    ql.enQueue(p);
    while(!ql.isEmpty())
    {
         p=ql.deQueue();
          cout<<p->data<<" ";
         if(p->lchild!=NULL)
         {
             ql.enQueue(p->lchild);
         }
          if(p->rchild!=NULL)
         {
             ql.enQueue(p->rchild);
         }
    
    }

}
int Tree::Countnode(Node*p)
{
   int x,y;
    if(p==NULL)
    return 0;
    if(p!=NULL)
    {
       x=Countnode(p->lchild);
       y=Countnode(p->rchild);
       return x+y+1;
    }
}
int Tree::sumNode(Node*p)
{
   int x,y;// similer to recc postorder
   // if(p==NULL)
    //return 0;
    if(p!=NULL)
    {
       x=sumNode(p->lchild);
       y=sumNode(p->rchild);
       return x+y+(p->data);
    }
    return 0;
}
int Tree::heightofTree(Node*p)
{
   int x,y;
    if(p==NULL)
    return 0;
    if(p!=NULL)
    {
       x=heightofTree(p->lchild);
       y=heightofTree(p->rchild);
       if(x>y)
       return x+1;
       else
       return 1+y;
    }
    
}

// node having degree two strictly
int Tree::nodedeg2(Node*p)
{
   int x,y;
    if(p!=NULL)
    {
       x=nodedeg2(p->lchild);
       y=nodedeg2(p->rchild);
       if(p->lchild!=NULL&&p->rchild!=NULL)// both left and ryt child exist;
       return x+y+1;
       else
        return x+y;
    }
    return 0;
}
int Tree::leafNode(Node*p)// degree 0
{
   int x,y;
    if(p!=NULL)
    {
       x=leafNode(p->lchild);
       y=leafNode(p->rchild);
       if(!p->lchild&&!p->rchild)// when botrh are null;
       return x+y+1;
       else
        return x+y;
    }
    return 0;
}
int Tree::degonenode(Node*p)// degree 1 that is either left child will be NULL or ryt child;
{
   int x,y;
    if(p!=NULL)
    {
       x=degonenode(p->lchild);
       y=degonenode(p->rchild);
      if((p->lchild!=NULL)^(p->rchild!=NULL))
       return x+y+1;
       else
        return x+y;
    }
    return 0;
}

int main()
{
   
     Tree t;
     t.create();
     cout<<"\nPreorder Travesal of Tree : "<<endl;
     t.preorder(t.root);
     cout<<"\nInorder Travesal of Tree : "<<endl;
     t.inorder(t.root);
     cout<<"\nPostorder Travesal of Tree : "<<endl;
     t.postorder(t.root);
     cout<<"\nIterative Preorder Travesal of Tree : "<<endl;
     t.itrpreorder(t.root);
     cout<<"\nIterative Inorder Travesal of Tree : "<<endl;
     t.itrinorder(t.root);
     cout<<"\nItr Postorder Travesal of Tree : "<<endl;
     t.itrpostorder(t.root);
      cout<<"\nLevel Order Travesal of Tree : "<<endl;
     t.levelordertrav(t.root);
      cout<<"\nNumber of Node in Tree: "<<t.Countnode(t.root)<<endl;
     cout<<"\nSum of Node in Tree: "<< t.sumNode(t.root)<<endl;
      cout<<"\nHeight of a Tree: "<< t.heightofTree(t.root)-1<<endl;
      cout<<"\nNumber of node with deg 2 of a Tree: "<< t.nodedeg2(t.root)<<endl;
       cout<<"\nNumber of node with deg 0(leaf) of a Tree: "<< t.leafNode(t.root)<<endl;
        cout<<"\nNumber of node with deg 1 of a Tree: "<< t.degonenode(t.root)<<endl;
    

}
