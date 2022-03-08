// JSG q2 wap to insert a node at any given position ;
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
    int data;
    Node*next;
};
Node*first=NULL;
void Createlink(int a[],int n)
{
    int i;
    Node*t,*last;
    first=new Node;
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
int Count(Node*p)
{   int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

 void RDisplay(Node*p)
 {
     if(p!=NULL)
     {
         cout<<"\nElement : "<<p->data;
         RDisplay(p=p->next);
     }
 }
void Insertp(Node*p,int x,int pos)
{    Node *t;
    if(pos<0||pos>Count(p))
        {cout<<"\n we can't add note at this index";
         return;}
    if(pos==0)
    {
       t=new Node;
       t->data=x;
       t->next=first;
       first=t;
    }
    else if(pos>0)
    {
        p=first;
        for(int i=0;i<pos-1&&p;i++)
        {
            p=p->next;
        }
        if(p)
        {
            t=new Node;
            t->data=x;
            t->next=p->next;
            p->next=t;
        }
    }
}


int main()
{
    Node*temp;
    int a[5]={10,20,12,43,9};
    Createlink(a,5);
    cout<<"\nDATA OF LIST";
    RDisplay(first);
   Insertp(first,100,0);
   cout<<"\nDATA OF LIST";
   RDisplay(first);
  Insertp(first,200,3);
  cout<<"\nDATA OF LIST";
   RDisplay(first);
   cout<<"\nDATA OF LIST";
   Insertp(first,500,-1);
   RDisplay(first);
   /* we can creat linklist directly without passing array or without using creating function
   we can use   Insertp(first,index,val)function for crating a link;\list
   */
    getch();
}
