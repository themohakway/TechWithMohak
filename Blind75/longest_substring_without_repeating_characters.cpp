#include <bits/stdc++.h>
using namespace std;

// Function to find length of longest substring without repeating characters
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    
    // Map to store the last index of each character
    unordered_map<char, int> charIndex;
    
    int maxLength = 0;
    int left = 0;                    // Left pointer of the window
    
    for (int right = 0; right < n; right++) {
        char currentChar = s[right];
        
        // If current char is already in the current window [left, right]
        if (charIndex.count(currentChar) && charIndex[currentChar] >= left) {
            // Move left pointer to just after the previous occurrence
            left = charIndex[currentChar] + 1;
        }
        
        // Update the last seen index of current character
        charIndex[currentChar] = right;
        
        // Update max length
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Multiple test cases for demonstration
    vector<string> testCases = {
        "abcabcbb",     // Expected: 3 ("abc")
        "bbbbb",        // Expected: 1 ("b")
        "pwwkew",       // Expected: 3 ("wke")
        "dvdf",         // Expected: 3 ("vdf") — note: 'd' repeats but not in window
        "abcdef",       // Expected: 6
        "a",            // Expected: 1
        "",             // Expected: 0 (empty string)
        "abba"          // Expected: 2 ("ab" or "ba")
    };
    
    cout << "Longest Substring Without Repeating Characters\n\n";
    
    for (int i = 0; i < testCases.size(); i++) {
        string s = testCases[i];
        int result = lengthOfLongestSubstring(s);
        
        cout << "Test Case " << (i + 1) << ":\n";
        cout << "Input: \"" << s << "\"\n";
        cout << "Output: " << result << "\n\n";
    }
    
    return 0;
}