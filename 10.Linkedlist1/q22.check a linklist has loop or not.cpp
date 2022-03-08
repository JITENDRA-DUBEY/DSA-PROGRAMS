//jsg check a ll has loop or not;
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

     while(p!=NULL)
     {
         cout<<"\nElement : "<<p->data;
         p=p->next;
     }
 }
 // by using teo pointers move p one step and q q 2 steps
 int isLoop(Node*f)
 {
    Node*p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
    }while((p&&q)&&(p!=q));
    return p==q?1:0;
 }



int main()
{   Node*t,*r;
    int a[5]={10,20,12,43,9};
    Createlink(a,5);
    Display(first);
    //creat a loop note we can go max last element in r and t never be first node ;
    t=first->next->next;
    r=first->next->next->next->next;
    r->next=t;
    if(isLoop(first))
    cout<<"\nThere is a Loop";
    else
        cout<<"\nLink is Linear";
    getch();
}
