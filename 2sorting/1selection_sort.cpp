#include<iostream>
using namespace std;
void selection(int nums[],int n)
{
    int j;
    for(int i=0;i<n-1;i++)
    {
        int min=nums[i+1];
        int ind=i+1;
        for( j=i+1;j<n;j++)
        {
            if(nums[j]<min)
            {
                min=nums[j];
                ind=j; 
            }
        }
        if(nums[i]>nums[j])
        {
            swap(nums[i],nums[ind]);
        }
    }
}
int main()
{
    int nums[10]={9,2,7,4,5,8,1,0,6,3};
    int n=10;
    // for(int i=0;i<n-1;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(nums[i]>nums[j])
    //         {
    //             swap(nums[i],nums[j]);
    //         }
    //     }
    // }
    selection(nums,10);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
}
