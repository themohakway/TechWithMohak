#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);  // We'll compute answer directly in result
        
        // Step 1: Fill result with prefix products
        // result[i] = product of all elements before i
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        
        // Step 2: Multiply with suffix products on the fly
        // We use a variable to keep track of suffix product from right
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        
        return result;
    }
};

// Test function for local verification
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = sol.productExceptSelf(nums);
    
    for (int x : ans) {
        cout << x << " ";
    }
    // Expected output: 24 12 8 6
    return 0;
}