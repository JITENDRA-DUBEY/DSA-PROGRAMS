// JSG Creat a linked list// and deletea node in shortest postion ;
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
};
int Count=0;
Node*first=NULL;
Node*last=NULL;
void InsertLast(int x)
{        Count++;
    Node*t=new Node;
       t->data=x;
       t->next=NULL;

   if(first==NULL)// that means there is no node avialable
   {
       first=t;
       last=t;
   }
   else
   {
   last->next=t;
   last=t;
   }
}
void Display(Node*p)
{
    cout<<"\nYour List : ";
    while(p)
    {
        cout<<"\nElement : "<<p->data;

        p=p->next;
    }
}
int  DeleteNode(Node *p,int pos)
{
    Node*t,*q=NULL;int x;
    if(Count==0){cout<<"\nThere is no node in the list";return -1; }
    if(pos<1||pos>Count){cout<<"\nInvalid Position we can't delete form here";
    return 0;}
    // if there is n
    if(pos==1)
    {
        x=first->data;
        p=first;
        first=first->next;
        delete(p);
        return x;
    }//trace tail pointer
    else
    {
      p=first;
    for(int i=0;i<pos-1;i++)
    {
        q=p;
        p=p->next;
    }
    if(p)
    {
        q->next=p->next;
        x=p->data;
        delete p;

    }return x;
    }

}

int main()
{   int n;
    while(1)
    {   int x,n;
        cout<<"\nDo you want to insert a node press 1\n";
        cin>>n;
        if(n!=1){break;}
        cout<<"\nEnter the data :";
        cin>>x;
        InsertLast(x);
    }
    Display(first);
    cout<<"\nDelete number :"<<DeleteNode(first,5);
    Display(first);
    cout<<"\nDelete number :"<<DeleteNode(first,3);
    Display(first);
    cout<<"\nDelete number :"<<DeleteNode(first,1);
    Display(first);
    cout<<"\nDelete number :"<<DeleteNode(first,10);
    Display(first);
     cout<<"\nDelete number :"<<DeleteNode(first,0);
    Display(first);
    return 0;
}
