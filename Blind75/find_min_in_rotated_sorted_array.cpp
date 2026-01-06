#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;  // Safe from overflow

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> tests = {
        {3,4,5,6,1,2},
        {4,5,6,7,0,1,2},
        {1,2,3,4,5},
        {5,1,2,3,4},
        {11,13,15,17},
        {1},
        {2,1}
    };

    cout << "Find Minimum in Rotated Sorted Array (Your Optimal Solution)\n\n";
    for (int i = 0; i < tests.size(); i++) {
        vector<int> nums = tests[i];
        int minVal = sol.findMin(nums);
        
        cout << "Test " << i+1 << ": [";
        for (int x : nums) cout << x << " ";
        cout << "] → Minimum = " << minVal << "\n";
    }

    return 0;
}