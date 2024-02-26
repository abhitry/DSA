#include<iostream>
using namespace std;//Moore’s Voting Algorithm:

//  MAJORITY >N/2      O[N]         O[1]
int majorityElement(vector<int>&nums)
{
    int count=0;
    int el=nums[0];
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==el)
        {
            count++;
        }
        else{
            count--;
        }
        if(count==0)
        {
            el=nums[i];
            count++;
        }
    }
    return el; 
}

//  MAJORITY >N/3      O[N]         O[1]
void majorityelement3(vector<int>&nums)
{
    int n=nums.size();
    int c1=0,c2=0,el1=INT_MIN,el2=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(c1==0 && nums[i]!=el2)
        {
            el1=nums[i];
            c1++;
        }
        else if(c2==0 && nums[i]!=el1)
        {
            el2=nums[i];
            c2++;
        }
        else if(nums[i]==el1)
        {
            c1++;
        }
        else if(nums[i]==el2)
        {
            c2++;
        }
        else{
            c1--;c2--;
        }
    }
    cout<<el1<<" "<<el2;
    //calcute if they are greatre than n/3 by travesrsing one loop and counting 
    //number of occurance of el1 and el2 and check if >n/3
}

int main()
{
    vector<int> arr ;
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    majorityelement3(arr);
    return 0;
}