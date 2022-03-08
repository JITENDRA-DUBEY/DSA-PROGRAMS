//jsg
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node*next;
};
Node*first=NULL;
Node*last=NULL;
int Count=0;
void InsertLast(int x)
{
    Node*t=new Node;
    t->data=x;
    t->next=NULL;
   if(first==NULL)
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
    cout<<"\nYour List :-";
    while(p)
    {
        cout<<"\n"<<p->data;
        p=p->next;

    }
}
int a[Count];
void Reversell()
{
    Node*p=first;
    //take nodes data inside array;
    int i=0;
    while(p)
    {
        a[i++]=p->data;
        p=p->next;
    }
    //revers nodes data;
    p=first;i=i-1;
    while(p)
    {
        p->data=a[i--];
        p=p->next;
    }
}
int main()
{
    int n,x;
    while(1)
    {
        cout<<"\nDo You want to insert a node than press 1";
        cin>>n;
        if(n!=1)
          {break;}
          Count++;
          cout<<"\nplzz enter the value of data";
          cin>>x;
          InsertLast(x);

    }

    Display(first);
}
