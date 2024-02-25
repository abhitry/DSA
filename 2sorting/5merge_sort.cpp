#include<iostream>
using namespace std;
void merge(int *nums,int low,int mid,int up)
{
    int i=low;
    int j=mid+1;
    int* temp=new int[up-low+1];
    int k=0;
    while(i<=mid && j<=up)
    {
        if(nums[i]<nums[j])
        {
            temp[k]=nums[i];
            k++;i++;
        }
        else
        {
            temp[k]=nums[j];
            k++;
            j++;
        }   
    }
    while(i<=mid)
    {
        temp[k]=nums[i];
        k++;i++;
    }
    while(j<=up)
    {
        temp[k]=nums[j];
        k++;j++;
    }
    for(int i=low;i<=up;i++)
    {
        nums[i]=temp[i-low];
    }
}
void mergesort(int *nums,int low,int up)
{
    if(low<up)
    {
        int mid=(low+up)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,up);
        merge(nums,low,mid,up);
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
