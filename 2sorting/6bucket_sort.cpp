#include<iostream>
using namespace std;
int main()
{
    int nums[10]={7,2,7,4,4,0,1,0,3,3};
    int n=10;
    int max=*max_element(nums,nums+n);
    int *bucket=new int[max+1];
    for(int i=0;i<=max;i++)
    {
        bucket[i]=0;
    }
    for(int i=0;i<n;i++)
    { 
        bucket[nums[i]]++;
    }
    for(int i=0;i<=max;i++)
    {
        while(bucket[i]>0)
        {
            cout<<i<<"  ";
            bucket[i]--;
        }
    }
}
