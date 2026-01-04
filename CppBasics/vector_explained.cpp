#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. Declaration and Initialization
    vector<int> v1;                                      // Empty vector
    vector<int> v2(5);                                   // Size 5, all elements 0
    vector<int> v3(5, 10);                               // Size 5, all elements 10
    vector<int> v4 = {1, 2, 3, 4, 5};                    // Initializer list
    int arr[] = {10, 20, 30, 40};
    vector<int> v5(arr, arr + 4);                        // From array
    cout << "1. Declaration and Initialization:\n";
    cout << "v1 (empty): size = " << v1.size() << "\n";
    cout << "v2 (5 zeros): "; for(int x : v2) cout << x << " "; cout << "\n";
    cout << "v3 (5 times 10): "; for(int x : v3) cout << x << " "; cout << "\n";
    cout << "v4 (initializer list): "; for(int x : v4) cout << x << " "; cout << "\n";
    cout << "v5 (from array): "; for(int x : v5) cout << x << " "; cout << "\n\n";

    // 2. Size, Capacity, Empty check
    cout << "2. Size, Capacity and Empty:\n";
    cout << "v4.size() = " << v4.size() << "\n";
    cout << "v4.capacity() = " << v4.capacity() << "\n";
    cout << "v1.empty() = " << (v1.empty() ? "true" : "false") << "\n";
    v1.reserve(100);                                     // Pre-allocate space
    cout << "After v1.reserve(100), capacity = " << v1.capacity() << "\n\n";

    // 3. Accessing elements
    cout << "3. Element Access:\n";
    cout << "v4[2] = " << v4[2] << "\n";                  // No bounds check (fast)
    cout << "v4.at(2) = " << v4.at(2) << "\n";            // With bounds check
    cout << "v4.front() = " << v4.front() << "\n";
    cout << "v4.back() = " << v4.back() << "\n\n";

    // 4. Adding elements
    vector<int> vb;
    vb.push_back(100);                                   // Add to end
    vb.push_back(200);
    vb.emplace_back(300);                                // In-place construction (faster for objects)
    cout << "4. After push_back and emplace_back:\n";
    for(int x : vb) cout << x << " "; cout << "\n";

    vb.insert(vb.begin() + 1, 999);                      // Insert at position
    vb.insert(vb.end(), 3, 555);                         // Insert 3 copies of 555 at end
    cout << "After insert operations: ";
    for(int x : vb) cout << x << " "; cout << "\n\n";

    // 5. Removing elements
    cout << "5. Removal operations:\n";
    vb.pop_back();                                       // Remove last element
    cout << "After pop_back(): ";
    for(int x : vb) cout << x << " "; cout << "\n";

    vb.erase(vb.begin() + 1);                            // Erase second element
    cout << "After erase one element: ";
    for(int x : vb) cout << x << " "; cout << "\n";

    vb.erase(vb.begin(), vb.begin() + 2);                // Erase first two
    cout << "After erase range: ";
    for(int x : vb) cout << x << " "; cout << "\n";

    vb.clear();                                          // Remove all
    cout << "After clear(): size = " << vb.size() << "\n\n";

    // 6. Resizing
    vector<int> vr = {1, 2, 3};
    vr.resize(7);                                        // Grow, new elements = 0
    cout << "6. After resize(7): ";
    for(int x : vr) cout << x << " "; cout << "\n";

    vr.resize(10, 99);                                   // Grow further, fill with 99
    cout << "After resize(10, 99): ";
    for(int x : vr) cout << x << " "; cout << "\n";

    vr.resize(4);                                        // Shrink
    cout << "After resize(4): ";
    for(int x : vr) cout << x << " "; cout << "\n\n";

    // 7. Sorting and Reversing
    vector<int> vs = {5, 2, 8, 1, 9};
    sort(vs.begin(), vs.end());                          // Ascending
    cout << "7. After sort ascending: ";
    for(int x : vs) cout << x << " "; cout << "\n";

    sort(vs.begin(), vs.end(), greater<int>());          // Descending
    cout << "After sort descending: ";
    for(int x : vs) cout << x << " "; cout << "\n";

    reverse(vs.begin(), vs.end());                       // Reverse
    cout << "After reverse: ";
    for(int x : vs) cout << x << " "; cout << "\n\n";

    // 8. Searching
    vector<int> search_vec = {10, 20, 30, 40, 50};
    auto it = find(search_vec.begin(), search_vec.end(), 30);
    cout << "8. Searching:\n";
    if (it != search_vec.end())
        cout << "30 found at index: " << (it - search_vec.begin()) << "\n";
    else
        cout << "Not found\n";

    sort(search_vec.begin(), search_vec.end());          // Required for binary_search
    bool found = binary_search(search_vec.begin(), search_vec.end(), 25);
    cout << "binary_search for 25 (sorted): " << (found ? "Yes" : "No") << "\n\n";

    // 9. Max and Min element
    cout << "9. Max/Min element:\n";
    cout << "Max in search_vec: " << *max_element(search_vec.begin(), search_vec.end()) << "\n";
    cout << "Min in search_vec: " << *min_element(search_vec.begin(), search_vec.end()) << "\n\n";

    // 10. Assign and Swap
    vector<int> va1 = {1, 1, 1};
    vector<int> va2 = {7, 8, 9};
    va1.assign(4, 42);                                   // Replace with 4 copies of 42
    cout << "10. After assign(4, 42) on va1: ";
    for(int x : va1) cout << x << " "; cout << "\n";

    va1.swap(va2);                                       // Swap contents
    cout << "After swap, va1: ";
    for(int x : va1) cout << x << " "; cout << "\n";
    cout << "After swap, va2: ";
    for(int x : va2) cout << x << " "; cout << "\n\n";

    // 11. Unique (remove consecutive duplicates)
    vector<int> vu = {1, 1, 2, 2, 3, 2, 2, 4};
    sort(vu.begin(), vu.end());
    auto last = unique(vu.begin(), vu.end());            // Moves unique elements to front
    vu.erase(last, vu.end());                            // Actually remove duplicates
    cout << "11. After sort + unique + erase: ";
    for(int x : vu) cout << x << " "; cout << "\n\n";

    // 12. 2D Vector (common in CP for grids/DP)
    int n = 3, m = 4;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            mat[i][j] = i * m + j + 1;
    cout << "12. 2D Vector (3x4 matrix):\n";
    for(auto& row : mat) {
        for(int x : row) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";

    // 13. shrink_to_fit (request to reduce capacity)
    vector<int> big_vec(1000, 1);
    cout << "13. Before shrink_to_fit: capacity = " << big_vec.capacity() << "\n";
    big_vec.clear();
    big_vec.shrink_to_fit();
    cout << "After clear + shrink_to_fit: capacity = " << big_vec.capacity() << "\n";

    return 0;
}