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
int L=0;
void Create(int a[],int n)
{   L++;
    head=new Node;
    head->prev=head;//this is single node of circular ll;
    head->data=a[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++)
    {   L++;
        Node*t=new Node;
        t->data=a[i];
        t->next=head;//head//last->next
        head->prev=t;
        last->next=t;
        t->prev=last;
        last=t;
    }

}

void Display(Node*p)
{   cout<<"\nYour List : ";
    if(head==NULL)
    return;

    do
    {
        cout<<"\nYour Element : "<<p->data;
        p=p->next;
    } while(p!=head);

}
void Insert(int pos,int x)
{   Node*t;
    if(pos<0||pos>L)
    {
        cout<<"\n\nInvalid Positon for Insertion";
                return;
    }

    if(pos==0)
    {
        if(head==NULL)// that means there is no node
        {   L++;
           head=new Node;
           head->prev=head;//this is single node of circular ll;
           head->data=x;
           head->next=head;

        }

        else// if there is more than one node
        {   L++;
            t=new Node;
            t->data=x;
            t->prev=head->prev;//assign last node add
            t->next=head;
            head->prev->next=t;//head->prev;//link to new first node;
            head->prev=t;
            head=t;
        }
    }
    else
        {   Node*p=head;
            t=new Node;
            t->data=x;
            for(int i=1;i<pos;i++){p=p->next;}
            t->prev=p;
            t->next=p->next;
            if(p->next!=NULL)
                p->next->prev=t;
            p->next=t;
            L++;
        }
}
int main()
{
    int a[5]={10,30,20,60,40};
    Create(a,5);
    Display(head);
    Insert(0,5);
    Display(head);
    Insert(1,19);
    Display(head);
    Insert(3,19);
    Display(head);
    Insert(8,100);
    Display(head);
}
