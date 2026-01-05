#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>    // for std::sort, std::stable_sort, std::reverse
#include <utility>      // for std::pair
#include <map>
#include <set>
#include <unordered_map>  // Note: Unordered_map can't be sorted directly
#include <functional>     // for std::greater
using namespace std;

// Custom comparator for pairs: Sort by first ascending, then second descending
bool customPairComp(const pair<int, string>& a, const pair<int, string>& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    cout << "=== C++ STL Sorting Demo: Ascending, Descending, Custom ===" << endl << endl;

    // 1. Vector<int> - Basic sort
    vector<int> vec = {5, 2, 8, 1, 9};
    cout << "Vector<int> Original: ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    // Ascending (default)
    sort(vec.begin(), vec.end());
    cout << "Ascending: ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    // Descending (using greater<int>())
    sort(vec.begin(), vec.end(), greater<int>());
    cout << "Descending: ";
    for (int n : vec) cout << n << " ";
    cout << endl << endl;

    // 2. Vector<pair<int, string>> - Custom sort
    vector<pair<int, string>> vecPairs = {{3, "Apple"}, {1, "Banana"}, {3, "Cherry"}, {2, "Date"}};
    cout << "Vector<pair> Original: ";
    for (auto& p : vecPairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;

    // Ascending by first (default)
    sort(vecPairs.begin(), vecPairs.end());
    cout << "Ascending (by first): ";
    for (auto& p : vecPairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;

    // Custom: first asc, second desc
    sort(vecPairs.begin(), vecPairs.end(), customPairComp);
    cout << "Custom (first asc, second desc): ";
    for (auto& p : vecPairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl << endl;

    // 3. Array<int, N> - Sort like vector
    array<int, 5> arr = {7, 3, 9, 4, 1};
    cout << "Array<int> Original: ";
    for (int n : arr) cout << n << " ";
    cout << endl;

    // Ascending
    sort(arr.begin(), arr.end());
    cout << "Ascending: ";
    for (int n : arr) cout << n << " ";
    cout << endl;

    // Descending
    sort(arr.begin(), arr.end(), greater<int>());
    cout << "Descending: ";
    for (int n : arr) cout << n << " ";
    cout << endl << endl;

    // 4. String - Sort characters
    string str = "helloWORLD";
    cout << "String Original: " << str << endl;

    // Ascending (case-sensitive)
    sort(str.begin(), str.end());
    cout << "Ascending (case-sensitive): " << str << endl;

    // To make case-insensitive, use custom comp or tolower (simplified reverse for desc)
    reverse(str.begin(), str.end());  // Quick reverse for descending effect
    cout << "Descending (via reverse): " << str << endl << endl;

    // 5. Set<int> - Always sorted ascending (can't change order directly)
    set<int> s = {5, 1, 9, 3};
    cout << "Set<int> (auto ascending): ";
    for (int n : s) cout << n << " ";
    cout << endl;

    // For descending set: Use set<int, greater<int>>
    set<int, greater<int>> descSet = {5, 1, 9, 3};
    cout << "Descending Set: ";
    for (int n : descSet) cout << n << " ";
    cout << endl << endl;

    // 6. Multiset - Similar to set, allows duplicates
    multiset<int> ms = {5, 1, 5, 3};
    cout << "Multiset (auto ascending with dups): ";
    for (int n : ms) cout << n << " ";
    cout << endl << endl;

    // 7. Map<int, string> - Sorted by key ascending
    map<int, string> m = {{3, "Three"}, {1, "One"}, {2, "Two"}};
    cout << "Map (auto sorted by key asc): ";
    for (auto& p : m) cout << p.first << ":" << p.second << " ";
    cout << endl;

    // For descending keys: map<int, string, greater<int>>
    map<int, string, greater<int>> descMap = {{3, "Three"}, {1, "One"}, {2, "Two"}};
    cout << "Descending Map by key: ";
    for (auto& p : descMap) cout << p.first << ":" << p.second << " ";
    cout << endl;

    // To sort by value: Copy to vector<pair> and sort
    vector<pair<int, string>> vecFromMap(m.begin(), m.end());
    sort(vecFromMap.begin(), vecFromMap.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;  // Asc by value
    });
    cout << "Map sorted by value asc: ";
    for (auto& p : vecFromMap) cout << p.first << ":" << p.second << " ";
    cout << endl << endl;

    // 8. Unordered_map - NOT sorted! (Hash-based)
    // To sort: Copy to vector and sort like above
    unordered_map<int, string> um = {{3, "Three"}, {1, "One"}, {2, "Two"}};
    cout << "Unordered_map (no order): Varies by hash" << endl << endl;

    // Bonus: Stable_sort (preserves relative order of equals)
    vector<int> stableVec = {5, 2, 5, 1};
    stable_sort(stableVec.begin(), stableVec.end());
    cout << "Stable_sort (preserves equal order): ";
    for (int n : stableVec) cout << n << " ";
    cout << endl;

    return 0;
}