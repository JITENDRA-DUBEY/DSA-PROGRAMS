//JSG Complete singlly ll
//note insertlast function only work when your list is empty 
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int menu();
class Node
{
    public:
    int data;
    Node*next;
    Node()// this is constructor
    {
        data=0;
        next=NULL;
    }
    Node(int data)// this is param. constructor
    {
        this->data=data;
        this-> next=NULL;
    }

};
class Linkedlist
{
  public : Node*first,*last=NULL;
  Linkedlist(){first=NULL;}// for assinging head pointer with null
  void create(int arr[],int n);
  void display();
  void reccPrint(Node *p); 
  void reccrevPrint(Node *p);
  void insertLast(int data);
  void insertFirst(int data);
  int countNode(Node*p);
  int sumofNoderec(Node*p);
  int maxelerec(Node*p);
  int keymtohsearch(Node*p,int key);
  void insertatPos(int pos,int data);
  void insertatshortpos(int x);
  int deleteatpos(int pos);
  void removeDuplicate(Node*p);
  void reverseList(Node*p);
  void mergeList(Node*f,Node*s);
};
void Linkedlist :: create(int arr[],int n)
{
  Node*last=NULL;
  Node*p=first;
  Node*t=new Node(arr[0]);
  last=t;first=t;
  int i;
  for(i=1;i<n;i++)
  {
    Node*t=new Node(arr[i]);
    last->next=t;
    last=t;
  }
}
void Linkedlist :: display()
{
   Node*p=first;
   cout<<"\nYour List : ";
   if(first==NULL)
   {cout<<"\nList is Empty";
     return;
   }
   while(p!=NULL)
   {
       cout<<"\nElement : "<<p->data;
       p=p->next;
   }
   
}
void Linkedlist :: reccPrint(Node*p)
{
 
   if(p!=NULL)
   {   
       cout<<"\nElement : "<<p->data;
       reccPrint(p->next);

   }
} 
void Linkedlist :: reccrevPrint(Node*p)
{
   if(p!=NULL)
   {  
       reccrevPrint(p->next);
       cout<<"\nElement : "<<p->data;
       
   }
} 
void Linkedlist::insertLast(int data)
{
      Node*t=new Node(data);
      if(first==NULL)//there is no Node
      {
          first=last=t;
      }
      else{
          last->next=t;
          last=t;
      }//this works only when our listy is empty or we dont use create function or insert first;
}
void Linkedlist::insertFirst(int data)
{
      Node*t=new Node(data);
      if(first==NULL)//there is no Node
      {
          first=t;
      }
      else{
           t->next=first;
          first=t;
      }
}
int  Linkedlist::countNode(Node *p)
{
    int x=0;
    while(p!=NULL){x++;p=p->next;}
    return x;

}
int  Linkedlist::sumofNoderec(Node *p)
{
   if(p==NULL)
   return 0;
   return (p->data)+sumofNoderec(p->next);

}
int  Linkedlist::maxelerec(Node *p)
{
   static int x=-65536;
   if(p==NULL)
   return x;
   else{
       if(p->data>x){
           x=p->data;
           maxelerec(p->next);
       }
   }return x;
}
int Linkedlist::keymtohsearch(Node*p,int key)
{
    Node*q=NULL;
    int x=-1;
    if(p==NULL)
    {
        cout<<"\nList is Empty so we can't search";
        return x;
    }
    if(key==first->data)//this is first node not need to move head
    {
         x=first->data;
         return x;
    }
    while(p!=NULL)
    {
        if(p->data==key)
        {
           x=key;
           q->next=p->next;
           p->next=first;
           first=p;
           break;
        }
        else
        q=p;p=p->next;
    } return x;
}
void Linkedlist::insertatPos(int pos,int data)
{
    Node *t=new Node(data);
  if(pos<0||pos>countNode(first))
  {
      cout<<"\nThis is Invalid Position We can't Insert";
  }
  else
  { 
      if(pos==0&&first==NULL)//there is no node
      {
            first=t;
      }
      else if(pos==0)// insert a node before head
      {
          t->next=first;
          first=t;
      }
      else
      {
         Node*p=first;
         for(int i=1;i<pos&&p;i++){p=p->next;}
         t->next=p->next;
         p->next=t;
      }
  }

}
void Linkedlist::insertatshortpos(int x)
{
    Node *p,*q=NULL,*t=new Node(x);
    if(first==NULL)// ionsert node when list is empty
    {
        first=t;
    }//doubt
   /*else if(x<first->data)//data insert befre first node
    {
        t->next=first;
        first=t;
    }
    else
    {  p=first;
      while((p->data<x)&&(p!=NULL)){q=p;p=p->next;}
       t->next=p;
      q->next=t;
    }*/
    else{
        p=first;
        while(p&&p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}
int Linkedlist:: deleteatpos(int pos)
{
  Node*p=first,*q=NULL;
  int x=-1,i;
  if(pos<=0||pos>countNode(first))
  {
      cout<<"Invalid Pos we Can't delete\n";
  }
  else{
      for(i=1;i<pos;i++)
      {
          q=p;p=p->next;
      }
      if(p==first)//here we delete first node
      {
          x=first->data;
         p=first;
         first=first->next;
         delete p;
      }
      else{
           x=p->data;
          q->next=p->next;
          delete p;
      }
  }return x;
}
void Linkedlist:: removeDuplicate(Node*first)
{
   Node*p=first,*q=first->next;
   while(q!=NULL)
   {
       if(p->data!=q->data)
       {
           p=q;
           q=q->next;
       }
       else
       {
         p->next=q->next;
         delete q;
         q=p->next;
       }
   }
}
void Linkedlist::reverseList(Node*p)
{
    // by using sliding pointer concept
   Node*q=NULL,*r=NULL;
   while(p!=NULL)
   {
       r=q;
       q=p;p=p->next;
       q->next=r;
   }
   first =q;
}
void Linkedlist::mergeList(Node*f,Node*s)
{
  Node*third,*last=NULL;
  if(f->data<s->data)
  {
      third=f;
      last =f;
      f=f->next;
      last->next=NULL;//not complusory
  }
  else{
       third=s;last =s;
       s=s->next;
      last->next=NULL; 
  }
  while(f!=NULL&&s!=NULL)
  {
     if(f->data<s->data) 
     {
         last->next=f;last=f;f=f->next,last->next=NULL;
     }
     else{
        last->next=s;last=s;s=s->next,last->next=NULL; 
     }
  }
  if(f!=NULL)
  last->next=f;
  else
  last->next=s;
  //this is for after mergning i want to print ll by using object first
   first=third;
}
int main()
{
  int key,x,pos,arr[]={10,20,30,40,50};
  int b[]={20,28,104,151};
  int c[]={4,7,12,14};
   Linkedlist myList,myList1,myList2;
   myList1.create(b,4);
   //myList2.create(c,4);
   while(1)
   {   system("CLS");
       switch (menu())
   {   
   case 1: myList.create(arr,5);
       break;
   case 2: myList.display();
           break;
    case 3: 
      cout<<"Plzz enter the value: ";
      cin>>x;
        myList.insertLast(x);
           break;       
    case 4: 
        if(myList.first==NULL)
      {cout<<"\nList is Empty"; }
      else
        {cout<<"\nYour List : ";
           myList.reccPrint(myList.first);
       } break; 
    case 5: if(myList.first==NULL)
      {cout<<"\nList is Empty"; }
      else
        {cout<<"\nYour List : ";
           myList.reccrevPrint(myList.first);
        } 
        break;  
        case 6:cout<<"Plzz enter the value: ";
           cin>>x;
            myList.insertFirst(x);
           break;
           case 7: 
           cout<<"\nNumber Of Nodes : "<<myList.countNode(myList.first);                    
               break;
          case 8: 
           cout<<"\nsum Of Nodes : "<<myList.sumofNoderec(myList.first);                    
               break;     
               case 9: 
           cout<<"\nMax Of Nodes : "<<myList.maxelerec(myList.first);                    
               break; 
         case 10: 
         cout<<"\nEnter ehich ele do you want search out : ";
            cin>>key;
           cout<<"\nKey Ele: "<<myList.keymtohsearch(myList.first,key);                    
               break;
      case 11: cout<<"Enter position and data value";
             cin>>pos>>x;
              myList.insertatPos( pos,x);  
              break;   
    case 12: cout<<"Enter your data ";
             cin>>x;
              myList.insertatshortpos(x);  
              break; 
        case 13: cout<<"Enter your Pos ";
             cin>>pos;
              cout<<"Delted Value : "<<myList.deleteatpos(pos);  
              break;  
    case 14 :myList.removeDuplicate(myList.first);
      break;
      case 15 :myList.reverseList(myList.first);
      break;
      case 16 :myList.mergeList(myList.first,myList1.first);
      break;
    case 17: exit(0);       
   default:
   cout<<"\nPlzz select right choice";
       break;
   }
     getch();
   }
}
int menu()
{
    int n;
   
   cout<<"\n1.For Creatingf LL with the help of array ";
   cout<<"\n2.For Display ";
   cout<<"\n3.For Creatingf LL wih the help of insert at last function  ";
   cout<<"\n4.For Display by using recuursion ";
   cout<<"\n5.For Display in Reverse order by using recuursion ";
   cout<<"\n6.For Creatingf LL wih the help of insert at First pos function  ";
   cout<<"\n7.For Number of Nodes ";
   cout<<"\n8.For Sum of Nodes ";
   cout<<"\n9.For Max of Nodes ";
   cout<<"\n10.For MovetoheadKeysearch : ";
   cout<<"\n11.For InsertNode at given pos : ";
   cout<<"\n12.For InsertNode at shortest pos : ";
   cout<<"\n13.For Delete a Node at given pos : ";
   cout<<"\n14.For Remove Duplicate ele from ll: ";
   cout<<"\n15.For Reverse Linkeld List : ";
   cout<<"\n16.For merginig two list";
   cout<<"\n17.for exit";
   cout<<"\nEnter Your Choice";
   cin>>n;
  return n;
}
