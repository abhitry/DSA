#include<iostream>
using namespace std;
//I<J    NUMS[I]>NUMS[J];
void merge(vector<int>&nums,int low,int mid,int up)
{
    int i=low,j=mid+1;
    int *temp=new int [up-low+1];
    int k=0;
    while(i<=mid && j<=up)
    {
        if(nums[i]<=nums[j])
        {
            temp[k++]=nums[i++];
        }
        else
        {
            temp[k++]=nums[j++];
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
}
int count_pairs(vector<int>&nums,int low,int mid,int up)
{
    int right=mid+1;
    int c=0;
    for(int i=low;i<=mid;i++)
    {
        while(right<=up && nums[i]>2*nums[right])
        {
            right++;
        }
        c+=right-(mid+1);
    }
    return c;
}
int mergesort(vector<int>&nums,int low,int up)
{
    int cnt=0;
    if(low<up)
    {
        int mid=(low+up)/2;
        cnt+=mergesort(nums,low,mid);
        cnt+=mergesort(nums,mid+1,up);
        cnt+=count_pairs(nums,low,mid,up);
        merge(nums,low,mid,up);
    }
    return cnt;
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(1);
    int n = 5;
    int cnt = mergesort(nums,0, 4);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;

}