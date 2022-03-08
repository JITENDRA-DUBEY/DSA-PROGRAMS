//jsg Doublly LinkesList
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    Node *prev;
    int data;
    Node*next;
}*first=NULL,*last=NULL;
int l=0;
void Create(int a[],int n)
{   l=n;
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
    last->next=first;
    first->prev=last;

}
    void Display(Node *p)
    {  cout<<"\n\nYour LIst:";
        while(p->next!=first)
        {
           cout<<"\nYour Element : "<<p->data;
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


void DeleteJd(int pos)
{   Node*p;
    if(pos<1||pos>l)
    {
        cout<<"\n\nInvalid Position we can't delete ";
        return;
    }
    if(pos==1)// delete first node
    {
     if(first==NULL)//there is no node
     {
         cout<<"\nList is already empty nothing to Delete";
     }
     else if(first->next==NULL)// there is single node only
     {
         delete first;l--;
     }
     else// deleting a node before first node;
        {
           p=first;
           first->next->prev=NULL;
           first=first->next;
           delete p;l--;

       }
    }
    else
        {  Node*temp;
            p=first;
            for(int i=1;i<pos-1;i++){p=p->next;}
            temp=p->next;//address off deleting node
            //p->next=p->next->next;
            if(p->next->next!=NULL)
            p->next->next->prev=p;
            p->next=p->next->next;
            delete temp;
            l--;

        }
}
void Reverse(Node*p)
{  cout<<"\nYour Reverse List :";
    Node*temp;
    while(p)
    {
       temp=p->next;
       p->next=p->prev;
       p->prev=temp;
       p=p->prev;//move p to next location
       if(p&&p->next==NULL)//vvmi
            {first=p;
            }
    }
}
int Delete(int pos)
{   Node*p;int x=-1;
    if(pos<1||pos>l)
    {
        cout<<"\n\nInvalid Position we can't delete ";
        return -1;
    }
    if(pos==1)// delete first node
    {
     if(first==NULL)//there is no node
     {
         cout<<"\nList is already empty nothing to Delete";
     }
     else if(first->next==NULL)// there is single node only
     {    x= first->data;
         delete first;l--;
     }
     else// deleting a node before first node;
        {
           p=first;
           x=first->data;
           first->next->prev=NULL;
           first=first->next;
           delete p;l--;

       }

    }
    else
        {
            p=first;
            for(int i=1;i<pos;i++){p=p->next;}

            p->prev->next=p->next;
            if(p->next!=NULL)
            p->next->prev=p->prev;
            x=p->data;
            delete p;
            l--;

        }return x;
}
int main()
{
    int a[5]={10,20,30,50,40};
    Create(a,5);
    /*/Length(first);
    //Display(first);
    //cout<<"\n\nDELETED ELE : "<<Delete(0);
     //DeleteJd(0);
    Display(first);
    cout<<"\n\nDELETED ELE : "<<Delete(1);
    //DeleteJd(1);
    Display(first);
    cout<<"\n\nDELETED ELE : "<<Delete(3);
    //DeleteJd(3);
    Display(first);
    cout<<"\n\nDELETED ELE : "<<Delete(3);
    //DeleteJd(3);
    Display(first);*/
    //Reverse(first);
    Display(first);




}
