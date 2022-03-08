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
int  isShort(Node *p)
{
   int x=-65536;
   while(p)
   {
       if(p->data<x)
        return 0;
       x=p->data;
       p=p->next;

   }// that means list is shorted;
     return 1;
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
    //Display(first);
    if(isShort(first))
       {
            cout<<"\nLIST IS SHORTED :";
            Display(first);
       }
       else
       {
         cout<<"\nLIST IS NOT SHORTED :";
            Display(first);
       }

    return 0;
}
