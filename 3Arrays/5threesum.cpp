#include <iostream>
using namespace std;

vector<vector<int > > triplet(int n, vector<int> &nums) {
    vector<vector<int> > ans;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++)
    {
        if(i>0 && nums[i]==nums[i-1]){continue;}
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    ans.push_back(v);
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;
                }
            }
    }
    return ans;
}
int main()
{
    vector<int> arr ;
    arr.push_back(-1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(-1);
    arr.push_back(-4);

    int n = arr.size();
    vector<vector<int> > ans = triplet(n, arr);
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
