#include<iostream>
using namespace std;
int maxsum(vector<int>nums)
{
    int n=nums.size();
    int max=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        max=sum>max?sum:max;
        if(sum<0){sum=0;}
    }
    return max;
}
int main()
{
     vector<int>nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    cout<<maxsum(nums);
}