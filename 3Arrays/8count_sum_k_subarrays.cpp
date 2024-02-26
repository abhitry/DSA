#include<iostream>
#include<map>
#include<vector>
using namespace std;

//HASHMAP O[NLOGN]        O[N]
//finding the reming part in the hashmap sum=k+reming 

int findAllSubarraysWithGivenSum(vector < int > & nums, int k) 
{
    int n=nums.size();
    int presum=0;
    int cnt=0;
    map<int,int>mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++)
    {
        presum+=nums[i];
        int rem=presum-k;
        cnt+=mpp[rem];
        mpp[presum]+=1;
    }
    return cnt;
}

int main()
{
    vector<int> arr ;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}