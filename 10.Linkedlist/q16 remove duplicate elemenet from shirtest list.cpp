// JSG Creat a linked list// and deletea node in shortest postion ;
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
// print duplicate element in a shorted array
void PrintDupele(Node*p)
{
    Node*q=p;
    p=p->next;
    int x=-62556;
    int dup=1;
    while(p)
    {

        if(q->data==p->data)
        {
            dup++;
            if(x!=p->data)
            {
                cout<<"\nDuplicate Element : "<<p->data<<" ocuur at "<<dup<<" times !";
                x=q->data;
                dup==1;
            }
        }
        q=p;
        p=p->next;
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
     cout<<"\n duplicate ele\n";
    PrintDupele(first);
    Rmdupshort(first);
    cout<<"\nElement after removing duplicate ele\n";
    Display(first);

    return 0;
}
