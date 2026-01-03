#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for (int num : nums) {  // using int directly (auto deduces int here)
            if (freq[num] > 0) {  // freq[num] defaults to 0 if not present
                return true;
            }
            freq[num] = 1;  // mark as seen
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: No duplicates
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << "Test 1: [1,2,3,4,5] -> "
         << (sol.hasDuplicate(nums1) ? "true" : "false") << endl;  // false
    
    // Test Case 2: Has duplicate
    vector<int> nums2 = {1, 2, 3, 2, 4};
    cout << "Test 2: [1,2,3,2,4] -> "
         << (sol.hasDuplicate(nums2) ? "true" : "false") << endl;  // true
    
    // Test Case 3: All same (early detection)
    vector<int> nums3 = {7, 7, 7, 7};
    cout << "Test 3: [7,7,7,7] -> "
         << (sol.hasDuplicate(nums3) ? "true" : "false") << endl;  // true
    
    // Test Case 4: Empty vector
    vector<int> nums4 = {};
    cout << "Test 4: [] -> "
         << (sol.hasDuplicate(nums4) ? "true" : "false") << endl;  // false
    
    // Test Case 5: Single element
    vector<int> nums5 = {42};
    cout << "Test 5: [42] -> "
         << (sol.hasDuplicate(nums5) ? "true" : "false") << endl;  // false
    
    return 0;
}