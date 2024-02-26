#include<iostream>
using namespace std;
int maxProduct(vector<int>& nums) {
    //if(nums.size()==1)return nums[0];
    int pre=1,suff=1;
    int ans=INT_MIN;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        if(pre==0)pre=1;
        if(suff==0)suff=1;
        pre*=nums[i];
        suff*=nums[n-i-1];
        ans=max(ans,max(pre,suff));
    }
    return ans;
}
int main()
{
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(-2);
    nums.push_back(4);
    cout<<maxProduct(nums);
}