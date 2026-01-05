#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> elementPresent;
        int highestSequenceTillNow = 0;
        vector<int> startIndices;

        for (auto num : nums)
        {
            elementPresent[num] = true;

            if (elementPresent[num-1] == false)
            {
                startIndices.push_back(num);
            }
        }

        for(auto start : startIndices)
        {
            int current = start;
            int currentLength = 0;
            while(elementPresent[current])
            {
                currentLength++;
                highestSequenceTillNow = max(highestSequenceTillNow, currentLength);
                current++;
            }
        }

        return highestSequenceTillNow;
    }
};

// Test function to verify locally
int main() {
    Solution sol;
    
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Input: [100,4,200,1,3,2]\n";
    cout << "Output: " << sol.longestConsecutive(nums1) << endl;  // Expected: 4 (1,2,3,4)
    
    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    cout << "\nInput: [0,3,7,2,5,8,4,6,0,1]\n";
    cout << "Output: " << sol.longestConsecutive(nums2) << endl;  // Expected: 9 (0 to 8)
    
    vector<int> nums3 = {};
    cout << "\nInput: []\n";
    cout << "Output: " << sol.longestConsecutive(nums3) << endl;  // Expected: 0
    
    return 0;
}