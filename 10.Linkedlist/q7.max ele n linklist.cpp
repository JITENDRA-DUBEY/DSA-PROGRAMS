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
int x=INT32_MIN;// thats by we have to
 int RMaxel(Node*p)
 {
   //int x=INT32_MIN; here we can take it because in each recc call it again initialize;
     if(p)
     {
         if(p->data>x)
            x=p->data;
         return RMaxel(p->next);
     }
     return x;
 }
 int RecMaxel(Node*p)
 {   int m=0;
     int x=INT32_MIN;
    if(p==0)
        return x;
    else
        x=RMaxel(p->next);
      return x>p->data?x:p->data;
    }


int main()
{
    int a[5]={10,20,12,43,9};
    Createlink(a,5);
    Display(first);
    cout<<"\nMax Element : "<<Maxel(first);
    cout<<"\nRec Max Element : "<<RMaxel(first);
    cout<<"\nReccu Max Element : "<<RecMaxel(first);


    getch();
}
