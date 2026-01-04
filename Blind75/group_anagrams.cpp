#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Generates a unique hash string based on character frequencies.
     * All anagrams will produce the exact same hash string.
     * 
     * Example:
     *   "eat"  -> "a1e1t1"
     *   "tea"  -> "a1e1t1"  (same as "eat")
     *   "bat"  -> "a1b1t1"
     * 
     * This works because we always iterate from 'a' to 'z' and append
     * the character followed by its count as a string.
     */
    string string_hash(string str) {
        int freq[26] = {0};                    // Frequency array for a-z

        // Count occurrences of each character
        for (auto c : str) {
            freq[c - 'a']++;
        }

        string hash;
        // Build hash: for each letter a-z, append char + its count
        for (int i = 0; i < 26; i++) {
            hash = hash + char('a' + i);       // the character itself
            hash += to_string(freq[i]);        // its frequency as string
        }

        return hash;
    }

    /**
     * Groups all anagrams together.
     * 
     * Approach:
     * 1. For each string, generate its frequency hash using string_hash().
     * 2. Use a map where key = hash, value = list of strings with that hash.
     * 3. All strings with the same hash are anagrams.
     * 4. Finally, collect all groups into the answer vector.
     * 
     * Time Complexity:  O(N × K)  where N = number of strings, K = max length of string
     * Space Complexity: O(N)
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result;  // hash -> list of anagrams

        // Group strings by their hash
        for (auto &s : strs) {
            string hash = string_hash(s);
            result[hash].push_back(s);
        }

        // Collect all groups into the final answer
        vector<vector<string>> ans;
        for (auto &p : result) {
            ans.push_back(p.second);
        }

        return ans;
    }
};

// Helper function to print the grouped anagrams nicely
void printGroups(const vector<vector<string>>& groups) {
    cout << "[";
    for (size_t i = 0; i < groups.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < groups[i].size(); ++j) {
            cout << "\"" << groups[i][j] << "\"";
            if (j < groups[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < groups.size() - 1) cout << ", ";
    }
    cout << "]\n\n";
}

// Complete running demo with multiple test cases
int main() {
    Solution sol;

    // Test Case 1: Standard example
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << "Input: " << "{\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"}\n";
    cout << "Output: ";
    printGroups(sol.groupAnagrams(strs1));

    // Test Case 2: Empty string and duplicates
    vector<string> strs2 = {"", "", "a"};
    cout << "Input: " << "{\"\", \"\", \"a\"}\n";
    cout << "Output: ";
    printGroups(sol.groupAnagrams(strs2));

    // Test Case 3: No anagrams
    vector<string> strs3 = {"hello", "world", "code"};
    cout << "Input: " << "{\"hello\", \"world\", \"code\"}\n";
    cout << "Output: ";
    printGroups(sol.groupAnagrams(strs3));

    // Test Case 4: All same characters
    vector<string> strs4 = {"a", "aa", "aaa"};
    cout << "Input: " << "{\"a\", \"aa\", \"aaa\"}\n";
    cout << "Output: ";
    printGroups(sol.groupAnagrams(strs4));

    // Test Case 5: Empty input
    vector<string> strs5 = {};
    cout << "Input: " << "{}\n";
    cout << "Output: ";
    printGroups(sol.groupAnagrams(strs5));

    return 0;
}