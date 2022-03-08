// JSG q2 wap to  print  linkedlist recurresilvely;
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

 void RDisplay(Node*p)
 {
     if(p!=NULL)
     {
         cout<<"\nElement : "<<p->data;
         RDisplay(p=p->next);
     }
 }

int main()
{
    int a[5]={10,20,12,43,9};
    Createlink(a,5);
    RDisplay(first);
    getch();
}
