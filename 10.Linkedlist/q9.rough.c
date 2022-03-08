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
 void KeySearch(Node*p,int key)
 {
     if(p==0)
        cout<<"\nThis is an empty list:";
        else{
       while(p)
      {
         if(key==p->data)
         {
             cout<<"\nYes present: ";
             break;
         }
         p=p->next;
      }
      if(p==NULL)
        cout<<"\nNo";
     }
 }
 Node* RKeySearch(Node*p,int key)
 {
     if(p==0)
     return NULL;
     if(key==p->data)
     return p;
     return RKeySearch(p->next,key);

	 }


int main()
{
    int a[5]={10,20,12,43,9};
    Createlink(a,5);
    RDisplay(first);
    KeySearch(first,9);
    cout<<"\nKey element:"<<RKeySearch(first,9);
    getch();
}
