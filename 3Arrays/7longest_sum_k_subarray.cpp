#include<iostream>
#include<map>
#include<vector>
using namespace std;

//BOTH POSITIVE AND NEGATIVE NUMBERS  O[NLOGN]     O[N]
//HASHMAP
int getLongestSubarray(vector<int>&nums,int k)
{
    int n=nums.size();
    int sum=0;
    int maxlen=0;
    map<int,int>presum;
    for(int i=0;i<n;i++) 
    {
        sum+=nums[i];
        if(sum==k)
        {
            maxlen=i+1;
        }
        int rem=k-sum;
        if(presum.find(rem)!=presum.end())
        {
            int len=i-presum[rem];
            maxlen=max(maxlen,len);
        }
        if(presum.find(sum)==presum.end())
        {
            presum[sum]=i;
        }
    }
    return maxlen;
}

//ONLY POSITIVE     O[2N]        0[1]
//TWO POINTERS
int getlongestpositive(vector<int>&nums,int k)
{
    int n=nums.size();
    int left=0,right=0;
    int sum=nums[0];
    int maxlen=0;
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=nums[left];
            left++;
        }
        if(sum==k)
        {
            maxlen=max(maxlen,right-left+1);
        }  
        right++;
        if(right<n)
        {
            sum+=nums[right];
        }
    }
    return maxlen;
}
int main()
{
    vector<int> a ;
    //1 2 1 3 
    a.push_back(1);
    a.push_back(2);
    a.push_back(1);
    a.push_back(3);
    //a.push_back(1);
    //a.push_back(1);
    //a.push_back(1);
    long long k = 2;
    int len = getlongestpositive(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
