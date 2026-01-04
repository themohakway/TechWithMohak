#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for (const string& str : strs) {
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        size_t i = 0;  // Use size_t or int, but be careful with bounds

        while (i < s.size()) {
            // Find the position of '#'
            size_t j = i;
            while (j < s.size() && s[j] != '#') {
                j++;
            }

            // Safety check: if no '#' found, something went wrong
            if (j == s.size()) {
                cerr << "Error: No delimiter '#' found!\n";
                return decoded;  // or throw exception
            }

            // Extract length as string
            string lengthStr = s.substr(i, j - i);
            int length = stoi(lengthStr);

            // Move past '#'
            j++;

            // Extract the actual string
            if (j + length > s.size()) {
                cerr << "Error: String length exceeds remaining data!\n";
                return decoded;
            }

            string singleStr = s.substr(j, length);
            decoded.push_back(singleStr);

            // Move i to the start of the next length prefix
            i = j + length;
        }

        return decoded;
    }
};

// Complete testing code with multiple test cases
void printVector(const vector<string>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Test Case 1: Normal strings
    vector<string> input1 = {"Hello", "World", "Blind", "75"};
    cout << "Input: "; printVector(input1);
    string encoded1 = sol.encode(input1);
    cout << "Encoded: \"" << encoded1 << "\"\n";
    vector<string> decoded1 = sol.decode(encoded1);
    cout << "Decoded: "; printVector(decoded1);
    cout << "Match: " << (input1 == decoded1 ? "Yes" : "No") << "\n\n";

    // Test Case 2: Empty string in list
    vector<string> input2 = {"", "abc", ""};
    cout << "Input: "; printVector(input2);
    string encoded2 = sol.encode(input2);
    cout << "Encoded: \"" << encoded2 << "\"\n";
    vector<string> decoded2 = sol.decode(encoded2);
    cout << "Decoded: "; printVector(decoded2);
    cout << "Match: " << (input2 == decoded2 ? "Yes" : "No") << "\n\n";

    // Test Case 3: Empty list
    vector<string> input3 = {};
    cout << "Input: "; printVector(input3);
    string encoded3 = sol.encode(input3);
    cout << "Encoded: \"" << encoded3 << "\"\n";
    vector<string> decoded3 = sol.decode(encoded3);
    cout << "Decoded: "; printVector(decoded3);
    cout << "Match: " << (input3 == decoded3 ? "Yes" : "No") << "\n\n";

    // Test Case 4: Strings with special characters and numbers
    vector<string> input4 = {"4#abc", "hello#world", "123", "#special"};
    cout << "Input: "; printVector(input4);
    string encoded4 = sol.encode(input4);
    cout << "Encoded: \"" << encoded4 << "\"\n";
    vector<string> decoded4 = sol.decode(encoded4);
    cout << "Decoded: "; printVector(decoded4);
    cout << "Match: " << (input4 == decoded4 ? "Yes" : "No") << "\n\n";

    // Test Case 5: Single string
    vector<string> input5 = {"neetcode"};
    cout << "Input: "; printVector(input5);
    string encoded5 = sol.encode(input5);
    cout << "Encoded: \"" << encoded5 << "\"\n";
    vector<string> decoded5 = sol.decode(encoded5);
    cout << "Decoded: "; printVector(decoded5);
    cout << "Match: " << (input5 == decoded5 ? "Yes" : "No") << "\n";

    return 0;
}