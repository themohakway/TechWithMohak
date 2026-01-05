#include <iostream>
#include <vector>
#include <algorithm>  // for std::max
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            // Current container width and height
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            int currentWater = width * currentHeight;
            
            // Update maximum
            maxWater = max(maxWater, currentWater);
            
            // Move the pointer with smaller height
            // Because moving the taller one can't give more height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};

// Test function - Great for live demo in video!
int main() {
    Solution sol;
    
    vector<int> heights1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Input: [1,8,6,2,5,4,8,3,7]\n";
    cout << "Maximum water: " << sol.maxArea(heights1) << endl;  // Expected: 49
    
    vector<int> heights2 = {1, 1};
    cout << "\nInput: [1,1]\n";
    cout << "Maximum water: " << sol.maxArea(heights2) << endl;  // Expected: 1
    
    vector<int> heights3 = {4, 3, 2, 1, 4};
    cout << "\nInput: [4,3,2,1,4]\n";
    cout << "Maximum water: " << sol.maxArea(heights3) << endl;  // Expected: 16
    
    vector<int> heights4 = {1, 2, 1};
    cout << "\nInput: [1,2,1]\n";
    cout << "Maximum water: " << sol.maxArea(heights4) << endl;  // Expected: 2
    
    return 0;
}