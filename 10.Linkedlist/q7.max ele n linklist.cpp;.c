// jsg LINKEDLIST FIRST PROGRAM
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
 int Maxel(Node*p)
 {
     int x=INT32_MIN;
     while(p)
     {
         if(p->data>x)
            x=p->data;
         p=p->next;
     }
     return x;
 }

int main()
{
    int a[5]={10,20,12,43,9};
    Createlink(a,5);
    Display(first);
    cout<<"\nSum of nodes : "<<Maxel(first);

    getch();
}
