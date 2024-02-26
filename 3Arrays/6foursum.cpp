#include <iostream>
using namespace std;

vector<vector<int > > fourplet(int n, vector<int> &nums,int target) {
    vector<vector<int> > ans;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++)
    {
        if(i>0 && nums[i]==nums[i-1]){continue;}
        for(int j=i+1;j<n;j++)
        {
            if(j>i+1 && nums[j]==nums[j-1]){continue;}
            int k=j+1;
            int l=n-1;
            while(k<l)
            {
                int sum=nums[i]+nums[j]+nums[k]+nums[l];
                if(sum<target)
                {
                    k++;
                }
                else if (sum>target)
                {
                    l--;
                }
                else
                {
                    vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    v.push_back(nums[l]);
                    ans.push_back(v);
                    l--;
                    k++;
                    while(k<l && nums[k]==nums[k-1]){k++;}
                    while(k<l && nums[l]==nums[l+1]){l--;}
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr ;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(1);
    int target=9;
    int n = arr.size();
    vector<vector<int> > ans = fourplet(n, arr,target);
    vector<vector<int> >:: iterator itr=ans.begin();
    vector<int>::iterator it;
    for(itr=ans.begin();itr!=ans.end();itr++)
    {
        it=itr->begin();
        for(it=itr->begin();it!=itr->end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cout << "\n";
    return 0;
}
