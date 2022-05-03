//jsg open chaining
#include<iostream>
using namespace std;
class Node// node of linked list
{
     public :
    int data;
    Node*next;
    Node(int key)
    {
        data=key;next=NULL;
    }
};
Node* G[10];
void insertkey(int k,int key)
{    Node*t=new Node(key);
    if(G[k]==NULL)
    {
        G[k]=t;
    }
    else// insert that key at sorted pos
    {
      Node*p=G[k],*q=NULL;
      while(p&&p->data<key)// for finding the last location
      {
          q=p;p=p->next;
      }
      
        if(p==G[k])
        {
             t->next=G[k];
             G[k]=t;
        }
        else{
            t->next=p;
           q->next=t;
        }
      
    }
}
void insert(int a[],int n)
{
   
    for(int i=0;i<n;i++)
    {
       int k=a[i]%10;
       insertkey(k,a[i]);
    }
}
//Node*head=NULL;
void display()
{
    for(int i=0;i<10;i++)
    {
        Node*p=G[i];
        cout<<"\n"<<i<<" . list data :- ";
        while(p)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
    }
}
/* here first find index by using key%10 than find that key in corresponding chain if u got than perform delteion 
like delete a key in sorted ll */
void deletekey(int key)
{
  //key%10;// index number in G[]
   Node*p=G[(key)%10],*q=NULL,*t;
  if(p){// that is there is atleast one element in in every chain than we can delete
   while(p&&p->data<key)// because lists are stored in ascending order
   {
       q=p;
       p=p->next;
   }
   if(p->data==key&&p==G[(key)%10])// first node
   {
       t=p;
      G[(key)%10]=t->next;
      delete t; 
   }
   else{
       if(p->data==key)
       {
           q->next=p->next;
           delete p;
       }
   }

}
}
int  searchkey(int key)
{
     Node*p=G[(key)%10];
     if(p)
     {
         while(p&&p->data<key)
         {
             p=p->next;
             
         }
         if(p==NULL)return 0;
         if(p->data==key)
         return 1;
         else
         return 0;
     }
}
int main()
{
    int a[9]={16,12,25,39,6,122,5,68,75};
    //int a[10]={0,12,1,3,8,14,24,5,6,7};
   // int a[5]={25,15,35,5,45};
    insert(a,9);
    display();
   deletekey(24);
  // deletekey(25);deletekey(5);deletekey(45);deletekey(15);
   
   deletekey(25);deletekey(5);deletekey(6); display();
  cout<<"\n"<<searchkey(122);
  cout<<"\n"<<searchkey(39);
  cout<<"\n"<<searchkey(2);

    cout <<"\ngd";
  
}