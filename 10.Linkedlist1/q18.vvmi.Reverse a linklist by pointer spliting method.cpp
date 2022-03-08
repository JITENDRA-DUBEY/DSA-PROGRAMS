// JSG Creat a linked list and reverse it revering links by using pointer spilting method ;
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
};
//int Count=0;
Node*first=NULL;
Node*last=NULL;
void InsertLast(int x)
{
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
void Rmdupshort(Node *p)
{
    Node*q;
    p=first;
    q=first->next;
    while(q)// q!=NULL
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
            {
                p->next=q->next;
                delete q;
                q=p->next;

            }
    }
}
void Reversell(Node*p)
{
    Node*q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        if(p->next==NULL){first=p;}// we have to move our first poinmter to last node which is now first node ;
        p=p->next;
        //Reverse the link
        q->next=r;

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
     Reversell(first);
    cout<<"\nReverse List : ";

    Display(first);
    Rmdupshort(first);
    cout<<"\nElement after removing duplicate ele\n";
    Display(first);
    return 0;
}
