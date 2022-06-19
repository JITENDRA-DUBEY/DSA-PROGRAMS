#include<iostream>
using namespace std;
int pow(int b,int e)
{
    if(e==0)
    return 1;
    else return b*pow(b,e-1);
}

// optimize power function
int calpower(int b,int e)
{
     if(e==0)
    return 1;
    if(e==1)
    return b;
    int ans=pow(b,e/2);
    if(e%2==0)
    {
        return ans*ans;// for even pow
    }
    else
    return b*ans*ans;
}
int main()
{
    cout<<"Pow of 2 is : "<<pow(3,0)<<endl;
    cout<<"odd Pow of 3 is : "<<calpower(3,5)<<endl;
     cout<<"even Pow of 3 is : "<<calpower(3,1)<<endl;

}