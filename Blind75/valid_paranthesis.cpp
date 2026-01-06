#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        
        for (char c : s) {
            if (c == '{' || c == '[' || c == '(') {
                stck.push(c);
            }
            else {  // closing bracket
                if (stck.empty()) {
                    return false;
                }
                
                char top = stck.top();
                stck.pop();
                
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
                if (c == ')' && top != '(') return false;
            }
        }
        
        return stck.empty();
    }
};

// Driver code to test multiple cases (Perfect for YouTube demo)
int main() {
    Solution sol;
    
    vector<string> testCases = {
        "()[]{}",          // true
        "({[()]})",        // true
        "([)]",            // false - wrong order
        "{[]}",            // true
        "",                // true - empty
        "(",               // false
        ")",               // false
        "(({}[]))",        // true
        "({})[",           // false
    };
    
    cout << "Valid Parentheses - Test Results\n\n";
    for (int i = 0; i < testCases.size(); i++) {
        string input = testCases[i];
        bool result = sol.isValid(input);
        
        cout << "Test " << (i + 1) << ": \"" << input << "\" → "
             << (result ? "Valid " : "Invalid ") << "\n";
    }
    
    return 0;
}