#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//OPTIMAL     O[NLOGN]    O[N]
vector<vector<int> > merge(vector<vector<int> >& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int> >ans;
    int n=intervals.size();
    for(int i=0;i<n;i++)
    {
        if(ans.empty() || intervals[i][0]>ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        ans.back()[1]=max(ans.back()[1],intervals[i][1]);
    }
    return ans;
}




int main()
{
    vector<vector<int> > arr ;
    vector<int>v;
    v.push_back(1);
    v.push_back(3);
    arr.push_back(v);
    v.clear();
    v.push_back(8);
    v.push_back(10);
    arr.push_back(v);
    v.clear();
    v.push_back(2);
    v.push_back(6);
    arr.push_back(v);
    v.clear();
    v.push_back(15);
    v.push_back(18);
    arr.push_back(v);
    vector<vector<int> > ans = merge(arr);
    cout << "The merged intervals are: " << "\n";
    vector<vector<int> >::iterator itr=ans.begin();
    vector<int>::iterator it;
    int i=0;
    for ( int i=0;i<ans.size();i++) 
    {
        cout<<ans[i][0]<<" "<<ans[i][1];
        cout<<endl;
    }
    cout << endl;
    return 0;
}