#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. Declaration and Initialization
    string s1;                          // Empty string
    string s2 = "Hello, World!";         // From string literal
    string s3(5, 'A');                   // "AAAAA" - 5 copies of 'A'
    string s4(s2);                       // Copy of s2
    cout << "1. Initial strings:\n";
    cout << "s1 (empty): '" << s1 << "'\n";
    cout << "s2: " << s2 << "\n";
    cout << "s3: " << s3 << "\n";
    cout << "s4 (copy of s2): " << s4 << "\n\n";

    // 2. Length/Size and empty check
    cout << "2. Size and empty check:\n";
    cout << "s2.size() = " << s2.size() << "\n";
    cout << "s2.length() = " << s2.length() << "\n";  // same as size()
    cout << "s1.empty() = " << (s1.empty() ? "true" : "false") << "\n\n";

    // 3. Accessing characters
    cout << "3. Character access:\n";
    cout << "s2[0] = " << s2[0] << "\n";              // No bounds check
    cout << "s2.at(0) = " << s2.at(0) << "\n";        // Throws if out of range
    cout << "s2.front() = " << s2.front() << "\n";
    cout << "s2.back() = " << s2.back() << "\n\n";

    // 4. Modification of characters
    s2[0] = 'h';                                // Modify directly
    cout << "4. After modifying s2[0] to 'h': " << s2 << "\n\n";

    // 5. Concatenation and Append
    string a = "Competitive";
    string b = " Programming";
    string c = a + b;                           // Concatenation (new string)
    a += " Coding";                             // Append to existing
    a.append(" Rocks!");                        // Another way to append
    a.push_back('!');                           // Add single char (very fast)
    cout << "5. Concatenation and append:\n";
    cout << "a + b = " << c << "\n";
    cout << "After appends and push_back: " << a << "\n\n";

    // 6. Substring
    string sub = s2.substr(7, 5);                // From pos 7, length 5 -> "World"
    cout << "6. Substring:\n";
    cout << "s2.substr(7,5) = " << sub << "\n";
    cout << "s2.substr(7) = " << s2.substr(7) << "\n\n";  // Till end

    // 7. Insertion
    string ins = "abcxyz";
    ins.insert(3, "DEF");                       // Insert "DEF" at position 3
    cout << "7. Insertion:\n";
    cout << "After insert(3, \"DEF\"): " << ins << "\n\n";

    // 8. Erasure and pop_back
    string era = "HelloWorld";
    era.erase(5, 5);                            // Remove 5 chars from pos 5 ("World")
    era.pop_back();                             // Remove last char if needed
    cout << "8. Erasure:\n";
    cout << "After erase(5,5): " << era << "\n";
    era.pop_back();                             // Remove 'o'
    cout << "After pop_back(): " << era << "\n\n";

    // 9. Replacement
    string rep = "I love Java";
    rep.replace(7, 4, "C++");                   // Replace "Java" with "C++"
    cout << "9. Replacement:\n";
    cout << "After replace: " << rep << "\n\n";

    // 10. Searching
    string search_str = "abracadabra";
    size_t pos = search_str.find("abra");       // First occurrence
    cout << "10. Searching:\n";
    if (pos != string::npos)
        cout << "\"abra\" found at position: " << pos << "\n";
    else
        cout << "Not found\n";

    cout << "Last \"abra\" at: " << search_str.rfind("abra") << "\n";
    cout << "First vowel at: " << search_str.find_first_of("aeiou") << "\n\n";

    // 11. Comparison
    string cmp1 = "apple";
    string cmp2 = "banana";
    cout << "11. Comparison:\n";
    cout << "cmp1 < cmp2: " << (cmp1 < cmp2 ? "true" : "false") << "\n";
    cout << "cmp1.compare(cmp2): " << cmp1.compare(cmp2) << "\n\n";

    // 12. Conversion to/from numbers
    string num_str = "12345";
    int num = stoi(num_str);
    long long big_num = stoll("9876543210");
    string back_to_str = to_string(num + 100);
    cout << "12. Conversions:\n";
    cout << "stoi(\"12345\") = " << num << "\n";
    cout << "stoll(\"9876543210\") = " << big_num << "\n";
    cout << "to_string(num + 100) = " << back_to_str << "\n\n";

    // 13. Reversing
    string pal = "racecar";
    string rev = pal;
    reverse(rev.begin(), rev.end());
    cout << "13. Reversing:\n";
    cout << "Original: " << pal << "\n";
    cout << "Reversed: " << rev << "\n";
    cout << "Is palindrome? " << (pal == rev ? "Yes" : "No") << "\n\n";

    // 14. Case conversion
    string cases = "MixED CaSe";
    transform(cases.begin(), cases.end(), cases.begin(), ::tolower);
    cout << "14. Case conversion:\n";
    cout << "To lowercase: " << cases << "\n";
    transform(cases.begin(), cases.end(), cases.begin(), ::toupper);
    cout << "To uppercase: " << cases << "\n\n";

    // 15. Clearing
    string temp = "Temporary";
    temp.clear();
    cout << "15. After clear(): length = " << temp.size() << ", empty = " 
         << (temp.empty() ? "true" : "false") << "\n";

    return 0;
}