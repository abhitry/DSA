#include<iostream>
using namespace std;
int main()
{
    int nums[10]={9,2,7,4,5,8,1,0,6,3};
    int n=10;
    int j;
    for(int i=0;i<n;i++)
    {
        int temp=nums[i];
        for( j=i-1;j>=0;j--)
        {
            if(nums[j]>temp)
            {
                nums[j+1]=nums[j];
            }
            else{
                break;
            }
        }
        nums[j+1]=temp;
    }
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
}