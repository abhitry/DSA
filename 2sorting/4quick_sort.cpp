#include<iostream>
using namespace std;
int partition(int *nums,int low,int up)
{
    int pivot=nums[low];
    int p=low+1;
    int q=up;
    while (1)
    {
        while(p<=up && nums[p]<pivot)
        {
            p++;
        }
        while(nums[q]>pivot)
        {
            q--;
        }
        if(p<q)
        {
            swap(nums[p],nums[q]);
        }
        else{
            break;
        }
    }
    swap(nums[q],nums[low]);
    return q;
    
}
void mergesort(int *nums,int low,int up)
{
    if(low<up)
    {
        int k=partition(nums,low,up);
        mergesort(nums,low,k-1);
        mergesort(nums,k+1,up);
    }
}
int main()
{
    int nums[10]={9,2,7,4,5,8,1,0,6,3};
    int n=10;
    int j;
    mergesort(nums,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<"  ";
    }
}
