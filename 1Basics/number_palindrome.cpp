#include<iostream>
using namespace std;
int cal(int x)
{
    if(x<0 ||(x!=0 && x%10==0))
    {
        return false;
    }
    int rev=0;
    while(x>rev)
    {
        rev=rev*10+x%10;
        x=x/10;
    }
    return (x==rev || x==rev/10);
}
int main()
{
    int x;
    cout<<"enter values=";
    cin>>x;
    int n=x;
    // int ans=0;
    // while(x!=0)
    // {
    //     int digit=x%10;
    //     ans=ans*10+digit;
    //     x=x/10;
    // }
    // cout<<(n==ans);

    //STRING 
    // string s=to_string(x);
    // int i=0,j=s.size()-1;
    // while(i<=j)
    // {
    //     if(s[i]!=s[j])
    //     {
    //         cout<<"no";
    //         return 0;
    //     }
    //     i++;j--;
    // }
    // cout<<"yes";
    // return 0;

    //HALF NUMBER 
    cout<<cal(x);
  
}