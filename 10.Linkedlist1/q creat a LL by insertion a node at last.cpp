// JSG Creat a linked list by insertion a node at last
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
};
Node*first=NULL;
Node*last=NULL;
void InsertLast(int x)
{
 Node *t;//*last;//we can't take last as local var;
t=new Node;
t->data=x;
t->next=NULL;
if(first==NULL)
{first=last=t;}
else{
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
    return 0;
}
