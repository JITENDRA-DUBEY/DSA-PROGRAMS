//jsg
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
};
Node *first=NULL;
void Create(int x)
{  Node *t,*p;
    t=new Node;
    t->data=x;
    t->next=NULL;
  if(first==NULL)// that means there is no node
  {
   first =t;
  }
  else
    {
        p=first;
        while(p->next!=0)
        {
            p=p->next;
        }
        p->next=t;
    }
}
void Display(Node*p)
{
    cout<<"\nyour list :-";
    while(p)
    {
        cout<<"\nELement :-"<<p->data;
       p=p->next;
    }
}
//chcek your list is shorted or not;
int CheckShort(Node*p)
{
    if(p==NULL){cout<<"\nList is already empty so we can't perform short";return 0;}
   // that means there is wh
    //if(p->next==NULL){}
    while(p->next!=NULL)
    {
        if(p->data>(p->next->data))
        {
            cout<<"\nList is not shorted";
            return 0;
        }
        p=p->next;

    }// that means we traverse all the node and all are shorted;
        cout<<"\nList is in shorted form";
}
int main()
{
    int x,n;
    while(1)
    {
        cout<<"\nDo you want insert a node than press Y/y\n";
        cin>>n;
        if(n!=1)
            {break;}
        cout<<"\nplzz enter the data:";
        cin>>x;
        Create(x);

    }//Checkshort(first);
     Display(first);
     CheckShort(first);

}
