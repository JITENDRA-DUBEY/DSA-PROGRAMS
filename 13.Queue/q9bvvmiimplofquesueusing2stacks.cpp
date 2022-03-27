//jsg Implementation of Queue using two Stack with the help of LL;
#include<iostream>
#include<conio.h>
using namespace  std;
class Node
{
    public:
    int data;
    Node*next;
    Node(){data=0;next=NULL;}
    Node(int data){this->data=data;this->next=NULL;} 
};
class stack
{
    public:
    Node*top,*last;
    stack(){top=NULL;last=NULL;}
    int isEmpty(){
        if(top==NULL)return 1;//if stack is empty than we return 1 else 0;
          else return 0;}
     void push(int data);
     int pop();
     void display();     
};
class Queue
{
    private:
    stack st1,st2;
    public :
    void enQueue(stack *st1,int data);
    void deQueue(stack *st1,stack *st2);
};
void Queue::enQueue(stack *st1,int data)
{
       st1->push(data);
}
void Queue::deQueue(stack *st1,stack *st2)
{
    int x=-1;
      if((st2->isEmpty()))//when we poped out all the element of stack or intiaaly when stack is empty
      {
          if(st1->isEmpty())
          {
              cout<<"Queue is empty jd"<<endl;
          }
          else{
              while(!(st1->isEmpty()))
              {
                  st2->push(st1->pop());
              }
               
           }
           
      }
       else{
            while(!(st2->isEmpty()))//when we again insert some ele than first transfer st2 elem in st1 //fifo
              {  
                  st1->push(st2->pop());
              }
       }
}
void stack::push(int data)
{
    Node*t=new Node(data);
    if(t==NULL){cout<<"stack overFlow"<<endl;}
    else
    {
        t->next=top;
        top=t;
    }
}
int stack:: pop()
{
    int x=-1;Node*temp=top;
    if(top==NULL){cout<<"stack underflow"<<endl;return x;}
    x=top->data;
    top=top->next;
    delete temp;
    return x;
}
void stack::display()
{
    cout<<"Your stack ele :"<<endl;
    if(top==NULL){cout<<"Stack is Empty"<<endl;}
    Node*p=top;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}
int main()
{
    Queue q1;stack st1,st2;
    int i=0;
    while(i++<=6)
    {
        q1.enQueue(&st1,10*i);
    }
    cout<<"Stack 1 data :"<<endl;
    st1.display();
       q1.deQueue(&st1,&st2);
       cout<<"Stack 2 data :"<<endl;
         st2.display();
     i=0;
    q1.deQueue(&st1,&st2);//VVVVVVMMMII****since st2 is not empty so using this function first we poped out all the element of st2 in st1 //here else part execute
    while(i++<=6)
    {
        q1.enQueue(&st1,1*i);
    }cout<<"Stack 1 data :"<<endl;
    st1.display();
     q1.deQueue(&st1,&st2);// now st2 is empty so tranfer st1 data in st2;
        cout<<"Stack 2 data :"<<endl;
        st2.display();
        cout<<"Queue data :"<<endl;
       
        while(!st2.isEmpty())
    {  
         cout<<" Queue ele: "<<st2.pop()<<endl;
       // cout<<" Queue ele: "<<q1.deQueue(&st1,&st2)<<endl;
    }
    cout<<"stack 2 value : "<<st2.pop()<<endl;
}
// if we want to print whole queue after performing both enque and deque than in first while loop we cant pop out st2
// because st2 became null ;