#include<iostream>
using namespace std;
//I<J    NUMS[I]>NUMS[J];
int merge(vector<int>nums,int low,int mid,int up)
{
    int i=low,j=mid+1;
    int *temp=new int [up-low+1];
    int k=0;
    int cnt=0;
    while(i<=mid && j<=up)
    {
        if(nums[i]<=nums[j])
        {
            temp[k++]=nums[i++];
        }
        else
        {
            temp[k++]=nums[j++];
            cnt=cnt+(mid-i+1);
        }
    }
    while(i<=mid)
    {
        temp[k++]=nums[i++];
    }
    while(j<=up)
    {
        temp[k++]=nums[j++];
    }
    for(int i=low;i<=up;i++)
    {
        nums[i]=temp[i-low];
    }
    return cnt;
}
int mergesort(vector<int>nums,int low,int up)
{
    int cnt=0;
    if(low<up)
    {
        int mid=(low+up)/2;
        cnt+=mergesort(nums,low,mid);
        cnt+=mergesort(nums,mid+1,up);
        cnt+=merge(nums,low,mid,up);
    }
    return cnt;
}
int countInversions(vector<int>nums,int n)
{
    return mergesort(nums,0,n-1);
}
int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    int n = 5;
    int cnt = countInversions(nums, n);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;

}