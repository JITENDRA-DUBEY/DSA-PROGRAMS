//jsg Doublly LinkesList
#include<iostream>
#include<stdlib.h>
struct Node
{
    Node *prev;
    int data;
    Node*next;
}*first=NULL,*last=NULL;
int l=0;
void Create(int a[],int n)
{
    Node*t;
    first=new Node;
    first->prev=NULL;
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=a[i];
        t->next=last->next;//NULL
        t->prev=last;
        last->next=t;
        last=t;
    }
}
    void Display(Node *p)
    {  std ::cout<<"\n\nYour LIst:";
        while(p)
        {
          std::  cout<<"\nYour Element : "<<p->data;
            p=p->next;
        }
    }
    int Length(Node *p)
    {

        while(p)
        {
          l++;
            p=p->next;
        }
        return l;
    }
    void Insert(int pos,int x)
    {
      Node*p;
        if(pos<0||pos>l)
        {
            std ::cout<<"\n\nInvalid position :";
            return;
        }


        if(pos==0)
        {    Node*t=new Node;
             t->data=x;
            if(first==NULL) //there is no node
            {
                t->prev=NULL;
                t->next=NULL;
                first=t;l++;
            }
           else //Insert a node before first node
           {   t->prev=NULL;
               t->next=first;
               first->prev=t;
               first=t;l++;
           }
        }
           else

            // that any other valid pos after the 1 node
           {
              p=first;//vvmi
              for(int i=1;i<pos;i++){p=p->next;}// reach till the pos numb
              Node*t=new Node;
               t->data=x;

            t->next=p->next;
            t->prev=p;
            if(p->next)
            p->next->prev=t;
            p->next=t;
            l++;
          }

       }


int main()
{
    int a[5]={10,20,30,50,40};
    //Create(a,5);
    Length(first);
    Display(first);
    Insert(1,11);
    Display(first);
     Insert(10,2);
     Display(first);
      Insert(0,1);
      Display(first);
      Insert(3,101);
      Display(first);
       Insert(8,1010);
      Display(first);
      Insert(10,0);
      Display(first);

}
