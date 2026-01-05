#include <iostream>
#include <string>
#include <cctype>   // for tolower, isalnum
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric from left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Skip non-alphanumeric from right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};

// Test function - Perfect for live demo
int main() {
    Solution sol;
    
    cout << "Test 1: \"A man, a plan, a canal: Panama\"\n";
    cout << "Result: " << (sol.isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false") << "\n\n";  // true
    
    cout << "Test 2: \"race a car\"\n";
    cout << "Result: " << (sol.isPalindrome("race a car") ? "true" : "false") << "\n\n";  // false
    
    cout << "Test 3: \"Was it a car or a cat I saw?\"\n";
    cout << "Result: " << (sol.isPalindrome("Was it a car or a cat I saw?") ? "true" : "false") << "\n\n";  // true
    
    cout << "Test 4: \" \" (empty after filtering)\n";
    cout << "Result: " << (sol.isPalindrome(" ") ? "true" : "false") << "\n";  // true (edge case)
    
    return 0;
}