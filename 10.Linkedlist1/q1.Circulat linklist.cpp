//jsg circular link list;
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node*next;
};
Node*head=NULL;
Node*last=NULL;
int Count=0;
/*void Create(int a[],int n)
{
    Node*t=new Node;
    t->data=a[0];
    t->next=NULL;
    last=t;
    head=t;
    for(int i=1;i<n;i++)
    {
       Node*t=new Node;
       t->data=a[i];
       t->next=NULL;
       last->next=t;
       last=t;
    }// for circular ll ass head in last node next;
    last->next=head;
}*/
void CreateAb(int a[],int n)
{
    Count=n;
    Node*t;
    head=new Node;
    head->data=a[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++)
    {
       Node*t=new Node;
       t->data=a[i];
       t->next=last->next;//assgn head in each node
       last->next=t;
       last=t;
    }
}
void Display(Node*p)
{
    cout<<"\nYour List : ";
    do
    {
        cout<<"\nElement : "<<p->data;
        p=p->next;
    }while(p!=head);
}
void ReccDisplay(Node*p)
{
    static int flag=0;
    if(p!=head||flag==0)
    {
         cout<<"\nElement Recc: "<<p->data;
         flag=1;
         ReccDisplay(p->next);
    }
    // at last make flag==0
    flag=0;
}

int RJDDisplay(Node*p)
{
   cout<<"\nElement RcJd: "<<p->data;
   if(p->next==head)
      return-1;
   RJDDisplay(p->next);
}
void Insert(int pos,int x)
{
    Node*p=head,*t;
    int i;
    t=new Node;
    t->data=x;
    if(pos==0)// before first node
    {
        if(head==NULL)//i.e now LL is empty so creat a node;
        {
            head=t;
            head->next=head;
        }
        else
        {
            // travese till last node
           while(p->next!=head)
           p=p->next;
           t->next=head;
           p->next=t;
           // we can move head to new node not necc
           head=t;
        }
    }
    else
    {
        if(pos>=1&&pos<=Count+1)
        {
           for(i=1;i<pos;i++)
             p=p->next;
             t->next=p->next;
             p->next=t;
        }
        else
        {
           cout<<"\nWe Can't Insert Invalid Pos";
        }
    }
}
int main()
{

    int a[5]={10,20,30,40,50};
    CreateAb(a,5);
    Display(head);
    cout<<"\nYour List Recc: ";
    ReccDisplay(head);
    cout<<"\nYour List By Jd : ";
    RJDDisplay(head);
    Insert(3,19);
    Display(head);
    Insert(5,21);
    Display(head);
    Insert(0,1);
    Display(head);
    Insert(1,12);
    Display(head);

}

