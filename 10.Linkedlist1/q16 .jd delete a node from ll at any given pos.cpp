// JSG Creat a linked list// and deletea node in shortest postion ;
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
};
int Count=0;
Node*first=NULL;
Node*last=NULL;
void InsertLast(int x)
{        Count++;
    Node*t=new Node;
       t->data=x;
       t->next=NULL;

   if(first==NULL)// that means there is no node avialable
   {
       first=t;
       last=t;
   }
   else
   {
   last->next=t;
   last=t;
   }
}
void Display(Node*p)
{
    cout<<"\nYour List : ";
    while(p)
    {
        cout<<"\nElement : "<<p->data;

        p=p->next;
    }
}
void DeleteNode(Node *p,int pos)
{
    Node*temp,*t;
    if(p==NULL){cout<<"\nList is already empty";return;}
    // it means u want to delete first node and if there is only one node;
    if(pos==1&&p->next==0)// Count==1
    {  temp=first;
        delete temp;
        first=NULL;
        cout<<"\nThere is only one node which is  delete";
        Count--;

    }
    else
      { int i;
        if(1<=pos&&pos<=Count)
        {
        for(i=1;i<pos-1;i++)
        {
            p=p->next;
        }//there is first node
        if(i==1&&pos==1)
        {
            temp=p;
            first=p->next;// that means delete first and move first to next node;
            delete temp;
            Count--;
        }
        else {if(pos>1&&pos<=Count-1)
            {
            temp=p->next;
            p->next=p->next->next;
            delete temp;
            Count--;
            }
            else
            {
                if(pos==Count)
                {
                   temp=p->next;
                   p->next=NULL;
                   delete temp;
                   Count--;
                }
            }
        }
        }
             else
                {  if(pos<1||pos>Count)
                    cout<<"\nthis is not a valid pos";
                }
    }
}

int main()
{   int n;
    while(1)
    {   int x,n;
        cout<<"\nDo you want to insert a node press 1\n";
        cin>>n;
        if(n!=1){break;}
        cout<<"\nEnter the data :";
        cin>>x;
        InsertLast(x);
    }
    Display(first);
    DeleteNode(first,5);
    Display(first);
    DeleteNode(first,3);
    Display(first);
    DeleteNode(first,1);
    Display(first);
    DeleteNode(first,0);
    Display(first);
    return 0;
}
