#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store value -> index
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // If complement exists in map, we found the pair
            if (mp.count(complement)) {
                return {mp[complement], i};  // smaller index first (since we iterate left to right)
            }
            
            // Store current element's index
            mp[nums[i]] = i;
        }
        
        // Problem guarantees exactly one solution, so we never reach here
        return {};
    }
};

// Demo / Testing code (great for YouTube explanation)
int main() {
    Solution sol;
    
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> ans1 = sol.twoSum(nums1, target1);
    cout << "Indices: [" << ans1[0] << ", " << ans1[1] << "]\n";  // Output: [0, 1]
    
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> ans2 = sol.twoSum(nums2, target2);
    cout << "Indices: [" << ans2[0] << ", " << ans2[1] << "]\n";  // Output: [1, 2]
    
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> ans3 = sol.twoSum(nums3, target3);
    cout << "Indices: [" << ans3[0] << ", " << ans3[1] << "]\n";  // Output: [0, 1]
    
    return 0;
}