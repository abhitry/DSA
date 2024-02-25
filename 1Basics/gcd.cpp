#include<iostream>
using namespace std;
int optimizecal(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return optimizecal(b,a%b);
}
int cal(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return cal(min(a,b),abs(a-b));
}
int main()
{
    int a,b;
    cout<<"enter numbers = ";
    cin>>a>>b;
    int gcd=1;
    // for(int i=2;i<=min(a,b);i++)
    // {
    //     if(((a%i)==0) && ((b%i)==0))
    //     {
    //         gcd=i;
    //     }
    // }
    // cout<<gcd;
    cout<<cal(a,b)<<endl;
    cout<<optimizecal(a,b);

}