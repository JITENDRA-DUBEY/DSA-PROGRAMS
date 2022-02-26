// jsg LINKEDLIST PROGRM FOR FINDING MIN EL;
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
 void Display(Node*p)
 {
     if(p==NULL)
        cout<<"LIST IS EMPTY :";// because in creat function we assign first->next ==null and first is global var;
     else
     while(p!=NULL)
     {
         cout<<"\nElement : "<<p->data;
         p=p->next;
     }
 }
 int Minel(Node*p)
 {
     int x=INT32_MAX;
     while(p)
     {
         if(p->data<x)
            x=p->data;
         p=p->next;
     }
     return x;
 }//imp**
 int RMinel(Node*p)
 {   int m=0;
     int x=INT32_MAX;
    if(p==0)
        return x;
    else
        x=RMinel(p->next);
      return x<p->data?x:p->data;
    }


int main()
{
    int a[5]={10,20,12,43,9};
    Createlink(a,5);
    Display(first);
    cout<<"\nMin Element : "<<Minel(first);
    cout<<"\nRec Min Element : "<<RMinel(first);


    getch();
}
