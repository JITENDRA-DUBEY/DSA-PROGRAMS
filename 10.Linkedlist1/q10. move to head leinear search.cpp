// JSG q2 wap to  print  linkedlist recurresilvely;// dobut it not showing desired result,
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

 Node* MTHKeySearch(Node*p,int key)
 {
     Node *q=NULL;
     while(p!=NULL)
     {
         //cout<<"\yesfz";
         if(key==p->data)
         {//cout<<"\yesj";
            q->next=p->next;
             // cout<<"\yes1";
            p->next=first;
            // cout<<"\yes2";
            first=p;
            //cout<<"\yes";
             return p;
         }
         q=p;
         p=p->next;
     }cout<<"no";
     return NULL;
 }


int main()
{
    Node*temp;
    int a[5]={10,20,12,43,9};
     //cout<<"\nTHe VAlue OF First : "<<first;
    Createlink(a,5);
    //cout<<"\nTHe VAlue OF First : "<<first;
    RDisplay(first);
    temp=MTHKeySearch(first,9);
    if(temp)
        cout<<"\nKey Found :"<<temp->data;
    else
        cout<<"\nNot Found";
    //cout<<"\nKey element:"<<MTHKeySearch(first,20);
     //cout<<"\nTHe VAlue OF First : "<<first;
    RDisplay(first);
     //cout<<"\nTHe VAlue OF First : "<<first;
     //cout<<"\n"<<a[0];
       // cout<<"\n"<<first->data;
        temp=MTHKeySearch(first,12);
    if(temp)
        cout<<"\nKey Found :"<<temp->data;
    else
        cout<<"\nNot Found";
    //cout<<"\nKey element:"<<MTHKeySearch(first,120);
    RDisplay(first);
    cout<<"\nKey element:"<<MTHKeySearch(first,120);
     RDisplay(first);
    getch();
}
