//jsg
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node*next;
}*first=NULL,*last=NULL;
int L=0;
void Insert(int x)
{
    Node*t;
    t=new Node;
    t->data=x;
     t->next=NULL;
    if(first==NULL)
    {
        first=last=t;
    }
    else
    {
       last->next=t;
       last=t;
    }
}
void Display(Node*p)
{   
    if(p==NULL)
      return;
    while(p)
    {
        cout<<"\nYour Element : "<<p->data;
        p=p->next;
    }
}
//find middle ele in single scan;
int MiddleNode()
{
    Node*p=first,*q=first;
    //if there is only one node
    if(p->next==NULL)
       return p->data;
    while(q)
    {
        q=q->next;
        if(q)
        {
           q=q->next;
        }
         if(q)
         p=p->next;//move p by one node
    }  
    return p->data;
}
int main()
{
    int n,x;
    cout<<"\npll enter total number of node";
    cin>>n;
    while(n--)
    {
         cin>>x;
         Insert(x);
    }
    Display(first);
    cout<<"\nMiddle Element : "<<MiddleNode();
}