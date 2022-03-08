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
 int Recrcount(Node*p)
 {
    if(p==0)
        return 0;
    else
      return Recrcount(p->next)+1;// or we can write 1+Recrcount(p->next); both add 1 at run time;
    /*
    we can write
    int x=0;
     if(p)
     {
     x=Reccount(p->next);
     return x+1;
     }
     else
        return x;
    */
 }

int main()
{
    int a[6]={10,20,12,43,9,11};
    Createlink(a,6);
    RevDisplay(first);
    cout<<"\nNumber of nodes in linked list : "<<Recrcount(first);
    getch();
}
