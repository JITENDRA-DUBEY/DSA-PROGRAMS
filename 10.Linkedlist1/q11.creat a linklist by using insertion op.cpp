//jsg q11.create a  linklist bt inserting a new node at  beginning;
#include<stdlib.h>
#include<iostream>
using namespace std;
int nnum=1;
struct Node
{
    int data;
    Node*next;
};
Node*first=NULL;
void Display(Node*p)
{
    while(p)
    {
        cout<<nnum++<<":"<<p->data<<"\n";
        p=p->next;
    }
}
void Insert(Node*p)
{
    Node*t;
    int temp;
    if(p==NULL)
    {
       t=new Node;
       cout<<"\nEnter your data :";
        cin>>temp;
        t->data=temp;
        t->next=NULL;
        first=t;
    }
    else
    {
        t=new Node;
        cout<<"\nEnter your data :";
        cin>>temp;
        t->data=temp;
        t->next=first;
        first=t;
    }
}
int main()
{
     Display(first);
    while(1)
    {
            int h;
         Insert(first);
        cout<<"\nDo you want add node at begning tha press 1\n";
       fflush(stdin);
       cin>>h;
       if(h!=1)
       {
           break;
       }

    }
   // Insert(first);
    //Insert(first);

    Display(first);

}
