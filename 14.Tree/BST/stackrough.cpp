// jsg;
#include<iostream>
using namespace std;
class Stack
{
    public :
    int top;
    int sz;
    int*S;
    Stack(int siz)
    {
        top=-1; sz=siz;
        S=new int[siz];
    }
    //void create(int siz);
    void push(int data);
    int Pop();
    void display();
};
/*void Stack::create(int siz)
{
    top=-1;sz=siz;
    S=new int[siz];
}*/
void Stack::push(int data)
{
    if(top==sz-1)
    cout<<"\nstack overflow "<<endl;
    else{
        top=top+1;
        S[top]=data;
    }
}
void Stack :: display()
{
    if(top==-1)
    cout<<"\n stack is empty ";
    else{
    int i=top;
    while(i>=0)
    {
        cout<<S[i]<<" ";i--;
    }
}
}
int Stack::Pop()
{
    int x=-1;
    if(top==-1)
    cout<<"\n stack underflow ";
    else{
       x=S[top];
       top=top-1;
    }
    return x;
}

int main()
{
    Stack st(2);
    //st.create(1);
    st.display();
    int i=0;
    while(i++<4)
    {st.push(10*i);}
    cout<<"\nstack value : \n";
    st.display();
    cout<<"\nStack poped our value :"<< st.Pop();
    cout<<"\nStack poped our value :"<< st.Pop();
     //cout<<"\nStack poped our value :"<< st.Pop();

}