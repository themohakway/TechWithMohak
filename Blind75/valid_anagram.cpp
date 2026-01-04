#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Quick check: different lengths can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        
        // Array to count frequency of each lowercase letter (a-z)
        int count[26] = {0};
        
        // Increment for characters in s, decrement for t
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        // If all counts are zero, they are anagrams
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};

// Demo with main function (useful for testing / YouTube explanation)
int main() {
    Solution sol;
    
    // Test cases
    cout << boolalpha;  // Print true/false instead of 1/0
    
    cout << "anagram & nagaram: " << sol.isAnagram("anagram", "nagaram") << "\n";  // true
    cout << "rat & car: " << sol.isAnagram("rat", "car") << "\n";                  // false
    cout << "hello & world: " << sol.isAnagram("hello", "world") << "\n";         // false
    cout << "race & care: " << sol.isAnagram("race", "care") << "\n";             // true
    cout << "a & a: " << sol.isAnagram("a", "a") << "\n";                         // true
    cout << "a & ab: " << sol.isAnagram("a", "ab") << "\n";                       // false
    
    return 0;
}