#include<iostream>
using namespace std;
#include <vector>

vector<vector<int> > subarraysWithSumK(vector<int> a, long long k) {
    int n = a.size();
    vector<vector<int> > ans;
    int left = 0, right = 0; // Renamed pointers
    long long sum = a[0]; // Start the sum with the first element

    while (left < n) { // Iterate through the array
        if (sum == k) { // If the sum equals k, store the subarray
            vector<int> temp;
            for(int i = left; i <= right; ++i) {
                temp.push_back(a[i]);
            }
            ans.push_back(temp);
        }

        if (sum <= k && right + 1 < n) { // Expand the window if sum is less than or equal to k and right is within bounds
            right++;
            sum += a[right];
        } else { // Shrink the window otherwise
            sum -= a[left];
            left++;
        }
    }

    return ans;
}


int main() {
    // Test array and target sum
    vector<int> nums ;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);

    long long k = 3;

    // Call the function and get the result
    vector<vector<int> > result = subarraysWithSumK(nums, k);

    // Print the result
    cout << "Subarrays with sum " << k << ":\n";
    for (int i=0;i<result.size();i++) {
        cout << "[ ";
        for (int j=0;j<result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << "]\n";
    }

    return 0;
}