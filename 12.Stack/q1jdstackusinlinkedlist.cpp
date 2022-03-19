#include<iostream>
#include<stdlib.h>
using namespace std;
 class Node
{
    public:
    int data;
    Node*next;
};
class Stack:public Node
{
    private :
    Node*Top;
    public:
    Stack()
    {
        Top=NULL;
    }
    void Display();
    void Push(int x);
    int Pop();
    int isMatch(char*);
    int isBalenced(char *);

};
void Stack::Push(int x)
{
    Node*t=new Node;
    if(t==NULL)//when heap is full;
    {
        cout<<"\nStack OverFlow";
    }
    else
    {
        t->data=x;
        t->next=Top;
        Top=t;
    }
}
void Stack::Display()
{
    Node*p=Top;
    cout<<"\nYour Satack Data";
    while(p)
    {
        cout<<"\nData Element : "<<p->data;
        p=p->next;
    }
}
int Stack::Pop()
{
    int x=-1;
    if(Top==NULL)
    cout<<"\nStack UnderFlow";
    else
    { 
        Node*temp=Top;
        x=Top->data;
        Top=Top->next;
        delete temp;
    }
    return x;
}
int Stack:: isBalenced(char *exp)
{
    int i;
    for( i=0;exp[i];i++)
    {
        if(exp[i]=='(')
        Push(exp[i]);
        else if((exp[i]==')'))
        {if(Top==NULL||Top->data!='(')
        {return 0;}// stack is empty;
          Pop();
        }
        else if(exp[i]=='{')
        Push(exp[i]);
        else if((exp[i]=='}'))
        {if(Top==NULL||(Top->data!='{'))
        {return 0;}// stack is empty;
        Pop();
        }
        else if(exp[i]=='[')
        Push(exp[i]);
        else if((exp[i]==']'))
        {if(Top==NULL||(Top->data!='['))
        {return 0;}// stack is empty;
        Pop();
       }

    } if(Top==NULL)
        return 1;//par mathces
        else return 0;
}
int Stack::isMatch(char *exp)
{
   int i;
   for(i=0;exp[i];i++)
   {
       if(exp[i]=='(')
       Push(exp[i]);
       else if(exp[i]==')')
       {
         if(Top)//stack is not empty
         {
             Pop();
         }
         else return 0;// when your stack is full;
       }
   }  if(Top==NULL)
       return 1;
       else 
       return 0;
}
int main()
{
    Stack st;
    /*int n,x;
    cout<<"\nEnter How Many Data U want to Push in to Stack";
    cin>>n;
    cout<<"\nEnter Your Data";
    while(n--)
    {
       cin>>x;
       st.Push(x);
      
    }
    st.Display();
    cout<<"\nPoped UP Data : "<<st.Pop();
    cout<<"\nPoped UP Data : "<<st.Pop();
    st.Display();/*/
    char str1[]="((a+b)(*(c-)d))";
    char str2[]="{([a+b]*[c-d)])/e}";
    if(st.isMatch(str1))
    cout<<"\nYes Expression Mathches";
    else
    {cout<<"\nexpression not Match";}
    if(st.isBalenced(str2))
    cout<<"\nYes Expression Mathches";
    else
    cout<<"\nexpression not Match";
}