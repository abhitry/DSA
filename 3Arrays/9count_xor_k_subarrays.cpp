#include<iostream>
#include<map>
#include<vector>
using namespace std;

//HASHMAP O[NLOGN]        O[N]
//finding the reming part in the hashmap sum=k+reming 
int findAllSubarraysWithGivenXor(vector<int>&nums,int k)
{
    map<int,int>mpp;
    mpp[0]=1;
    int xr=0;
    int cnt=0;
    for(int i=0;i<nums.size();i++)
    {
        xr=xr^nums[i];
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main()
{
    vector<int> arr ;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(4);
    int k = 6;
    int cnt = findAllSubarraysWithGivenXor(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}