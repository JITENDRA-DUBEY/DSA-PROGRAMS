// JSG q2 wap to count number of nodes itrratively;
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

 void RevDisplay(Node*p)
 {
     if(p!=NULL)
     {
         RevDisplay(p->next);
         cout<<"\nElement : "<<p->data;

     }
 }
 int Itrcount(Node*p)
 {
     int c=0;
     while(p)
     {
         c++;
         p=p->next;
     }
     return c;
 }

int main()
{
    int a[5]={10,20,12,43,9};
    Createlink(a,5);
    RevDisplay(first);
    cout<<"\nNumber of nodes in linked list : "<<Itrcount(first);
    getch();
}
