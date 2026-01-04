#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency of each number
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create vector of {frequency, number} pairs
        vector<pair<int, int>> freqToNumber;
        for (auto& kvPair : freq) {                  // Important: iterate over freq, not nums!
            freqToNumber.push_back({kvPair.second, kvPair.first});  // {frequency, number}
        }

        // Step 3: Sort by frequency in descending order
        sort(freqToNumber.begin(), freqToNumber.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;  // higher frequency first
        });

        // Step 4: Take the top k numbers
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqToNumber[i].second);  // extract the number (second)
        }

        return result;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    cout << "Input: nums = [1,1,1,2,2,3], k = 2\n";
    cout << "Output: ";
    printVector(sol.topKFrequent(nums1, k1));  // Expected: [1, 2]

    // Test Case 2
    vector<int> nums2 = {1};
    int k2 = 1;
    cout << "\nInput: nums = [1], k = 1\n";
    cout << "Output: ";
    printVector(sol.topKFrequent(nums2, k2));  // Expected: [1]

    // Test Case 3
    vector<int> nums3 = {4, 4, 4, 5, 5, 6};
    int k3 = 2;
    cout << "\nInput: nums = [4,4,4,5,5,6], k = 2\n";
    cout << "Output: ";
    printVector(sol.topKFrequent(nums3, k3));  // Expected: [4, 5]

    // Test Case 4: Negative numbers
    vector<int> nums4 = {-1, -1, 2, 2, 2, 3};
    int k4 = 2;
    cout << "\nInput: nums = [-1,-1,2,2,2,3], k = 2\n";
    cout << "Output: ";
    printVector(sol.topKFrequent(nums4, k4));  // Expected: [2, -1]

    // Test Case 5: k equals unique count
    vector<int> nums5 = {3, 0, 1, 0};
    int k5 = 2;
    cout << "\nInput: nums = [3,0,1,0], k = 2\n";
    cout << "Output: ";
    printVector(sol.topKFrequent(nums5, k5));  // Expected: [0, 3] or [0,1] etc.

    return 0;
}