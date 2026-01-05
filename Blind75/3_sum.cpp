#include <iostream>
#include <vector>
#include <algorithm>  // for std::sort
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 3) return result;  // Edge case
        
        // Step 1: Sort the array (key to avoid duplicates and use two pointers)
        sort(nums.begin(), nums.end());
        
        // Step 2: Fix the first element (i)
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // Two pointers for the remaining sum: nums[j] + nums[k] = -nums[i]
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // Skip duplicates for right
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;   // Need larger sum
                }
                else {
                    right--;  // Need smaller sum
                }
            }
        }
        
        return result;
    }
};

// Test function - Great for live demo!
int main() {
    Solution sol;
    
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Input: [-1, 0, 1, 2, -1, -4]\n";
    vector<vector<int>> ans1 = sol.threeSum(nums1);
    cout << "Output:\n";
    for (auto& triplet : ans1) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }
    // Expected: [-1,-1,2], [-1,0,1]
    
    cout << "\nInput: [0, 0, 0, 0]\n";
    vector<int> nums2 = {0, 0, 0, 0};
    vector<vector<int>> ans2 = sol.threeSum(nums2);
    cout << "Output: [0, 0, 0]\n";
    
    cout << "\nInput: [1, -1, -1, 0]\n";
    vector<int> nums3 = {1, -1, -1, 0};
    vector<vector<int>> ans3 = sol.threeSum(nums3);
    cout << "Output:\n";
    for (auto& triplet : ans3) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }
    
    return 0;
}