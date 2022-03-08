// jsg stack impletation by using array;
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Stack
{
    int Size;
    int Top;
    int *S;
};
void Create(Stack*st)
{
    cout<<"\nEnter the size of stack";
    cin>>st->Size;
    st->Top=-1;
    st->S=new int[st->Size];
}
void Push(Stack*st,int x)
{
    if(st->Top==st->Size-1)
    cout<<"\nStack OverFlow";//stack is already full;
    else
    {
        st->S[++(st->Top)]=x;
    }
}
int Pop(Stack*st)
{   int x=-1;
    if(st->Top==-1)
    cout<<"\nStack UnderFlow";//stack is already Empty;
    else
    {
        x=st->S[st->Top--];
    }
    return x;
}
int isEmpty(Stack st)
{
    if(st.Top==-1)
    return 1;
    else
    return 0;
}
int Stack_Top(Stack st)
{   
    if(!isEmpty(st))
    return st.S[st.Top];
    else
    return-1;
    /*if(st.Top==-1)
    return -1;
    else
    return st.S[st.Top];
    /*/
}
int Peek(Stack st,int index)
{   int x=-1;
    if(st.Top-index+1<0||index==0)
    cout<<"\nInvalid Position";
    else
     {x= st.S[st.Top-index+1];}
     return x;
}

void Display(Stack*st)
{
    cout<<"\nYour Stack Elemenet\n";
    for(int i=st->Size-1;i>=0;i--)//if u want print from top than took i=st->Top
    {
        cout<<st->S[i]<<"\n";
    }
}

int isFull(Stack st)
{
    if(st.Top==st.Size-1)
    return 1;
    else
    return 0;
}
int main()
{
    struct Stack st;
    Create(&st);
    Push(&st,4);
    Push(&st,8);
    Push(&st,10);
    Push(&st,12);
    Display(&st);
     cout<<"\nTop of Stack Value :"<<Stack_Top(st);
    //cout<<"\nPop Ele 1: "<<Pop(&st);
    cout<<"\nTop of Stack Value :"<<Stack_Top(st);
    //cout<<"\nPop Ele 2: "<<Pop(&st);
    //cout<<"\nPop Ele 3: "<<Pop(&st);
    cout<<"\nPeek Value :"<<Peek(st,0);
    cout<<"\nPeek Value :"<<Peek(st,2);
    cout<<"\nPeek Value :"<<Peek(st,1);
    cout<<"\nStack is : "<<isFull(st);
    cout<<"\nStack is : "<<isEmpty(st);


}