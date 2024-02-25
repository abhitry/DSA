#include<iostream>
using namespace std;
void rec_insertion(int *nums,int  i,int n)
{
    if(i==n)
    {
        return; 
    }
    int j=i-1;
    int temp=nums[i];
    while(j>=0 && nums[j]>temp)
    {
        nums[j+1]=nums[j];
        j--;
    }
    nums[j+1]=temp;
    rec_insertion(nums,i+1,n);
}
int main()
{
    int nums[10]={9,2,7,4,5,8,1,0,6,3};
    int n=10;
    int j;
    // for(int i=0;i<n;i++)
    // {
    //     int temp=nums[i];
    //     for( j=i-1;j>=0;j--)
    //     {
    //         if(nums[j]>temp)
    //         {
    //             nums[j+1]=nums[j];
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     nums[j+1]=temp;
    // }
    rec_insertion(nums,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
}
