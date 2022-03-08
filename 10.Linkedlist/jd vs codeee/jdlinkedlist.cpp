// jsg circular doublly linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    Node*prev;
    int data;
    Node*next;
};
Node*head=NULL,*last=NULL;
int l=0;
void Create(int a[],int n)
{ 
    Node*t=new Node;
   // t->prev=NULL;
    //t->data=x;
    //t->next=head;
    head=new Node;
    head->prev=head;//this is single node of circular ll;
    head->data=a[0];
    head->next=head;
    //head=t;
    last=head;
    for(int i=1;i<n;i++)
    {  
        Node*t=new Node;
        t->data=a[i];
        t->next=last->next;//head
        last->next=t;
        t->prev=last;
        last=t;
    }

}
void Display(Node*p)
{
    while(p->next!=head)
    {
        cout<<"\nYour Element : "<<p->data;
        p=p->next;
    }
}
int main()
{
    int a[5]={10,30,20,50,40};
    Create(a,5);
    Display(head);
}