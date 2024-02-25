#include<iostream>
using namespace std;
void rec_bubble(int *nums,int n)
{
    if(n==1)
    {
        return;
    }
    for(int j=0;j<n-1;j++)
    {
        if(nums[j]>nums[j+1])
        {
            swap(nums[j],nums[j+1]);
        }
    }
    rec_bubble(nums,n-1);
}
int main()
{
    int nums[10]={9,2,7,4,5,8,1,0,6,3};
    int n=10;
    int flag=0;
    // for(int i=0;i<n-1;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(nums[i]>nums[j])
    //         {
    //             swap(nums[i],nums[j]);
    //             flag=1;
    //         }
    //     }
    //     if(flag==0)
    //     {
    //         break;
    //     }
    // }
    rec_bubble(nums,n);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
}