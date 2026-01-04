#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. Declaration and Initialization
    set<int> s1;                                           // Empty set
    set<int> s2 = {5, 2, 8, 2, 9};                          // Duplicates ignored -> {2,5,8,9}
    multiset<int> ms1 = {1, 1, 3, 2, 3};                    // Allows duplicates -> {1,1,2,3,3}
    set<int, greater<int>> s_desc = {10, 20, 15};          // Descending order -> {20,15,10}
    
    cout << "1. Declaration and Initialization:\n";
    cout << "s2 (unique sorted): ";
    for(int x : s2) cout << x << " "; cout << "\n";
    cout << "ms1 (multiset): ";
    for(int x : ms1) cout << x << " "; cout << "\n";
    cout << "s_desc (descending): ";
    for(int x : s_desc) cout << x << " "; cout << "\n\n";

    // 2. Insertion
    set<int> s;
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10);                                           // Duplicate - ignored
    s.emplace(40);                                         // In-place insertion
    
    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);                                           // Duplicate allowed
    
    cout << "2. After insertions:\n";
    cout << "set s: ";
    for(int x : s) cout << x << " "; cout << "\n";          // 10 20 30 40
    cout << "multiset ms: ";
    for(int x : ms) cout << x << " "; cout << "\n\n";       // 5 5

    // 3. Size and Empty check
    cout << "3. Size and Empty:\n";
    cout << "s.size() = " << s.size() << "\n";
    cout << "s.empty() = " << (s.empty() ? "true" : "false") << "\n\n";

    // 4. Search / Find / Count
    cout << "4. Search operations on set s:\n";
    auto it = s.find(20);
    if (it != s.end())
        cout << "20 found\n";
    else
        cout << "20 not found\n";

    cout << "count(20) = " << s.count(20) << "\n";         // 1 or 0
    cout << "count(999) = " << s.count(999) << "\n\n";

    cout << "Multiset ms count(5) = " << ms.count(5) << "\n\n";  // 2

    // 5. lower_bound and upper_bound
    cout << "5. lower_bound and upper_bound on set s:\n";
    auto lb = s.lower_bound(25);                           // First >= 25
    if (lb != s.end()) cout << "*lower_bound(25) = " << *lb << "\n";
    
    auto ub = s.upper_bound(20);                           // First > 20
    if (ub != s.end()) cout << "*upper_bound(20) = " << *ub << "\n";
    
    auto eq = s.equal_range(20);                           // Pair: lower and upper for 20
    cout << "equal_range(20): [" << *eq.first << ", " << (eq.second == s.end() ? "end" : to_string(*eq.second)) << ")\n\n";

    // 6. Min and Max
    cout << "6. Min and Max:\n";
    cout << "Smallest in s: " << *s.begin() << "\n";
    cout << "Largest in s: " << *s.rbegin() << "\n\n";

    // 7. Iteration (forward and reverse)
    cout << "7. Forward iteration:\n";
    for(auto x : s) cout << x << " "; cout << "\n";
    
    cout << "Reverse iteration:\n";
    for(auto it = s.rbegin(); it != s.rend(); ++it)
        cout << *it << " "; cout << "\n\n";

    // 8. Erasure
    cout << "8. Erasure operations:\n";
    s.erase(20);                                           // Erase value 20
    cout << "After erase(20): ";
    for(int x : s) cout << x << " "; cout << "\n";          // 10 30 40

    auto it_erase = s.find(30);
    s.erase(it_erase);                                     // Erase by iterator
    cout << "After erase iterator (30): ";
    for(int x : s) cout << x << " "; cout << "\n";          // 10 40

    ms.erase(ms.find(5));                                  // Erase only ONE occurrence of 5
    cout << "Multiset after erasing one 5: ";
    for(int x : ms) cout << x << " "; cout << "\n";         // 5

    s.clear();                                             // Remove all
    cout << "After s.clear(): size = " << s.size() << "\n\n";

    // 9. Custom comparator example (pair set)
    set<pair<int, int>> sp;
    sp.insert({2, 10});
    sp.insert({1, 20});
    sp.insert({2, 5});                                      // Sorted by first, then second
    cout << "9. Set of pairs (sorted by first, then second):\n";
    for(auto& p : sp) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n\n";

    // 10. Practical example: Unique sorted elements from vector
    vector<int> vec = {4, 2, 4, 1, 3, 2, 5};
    set<int> unique_sorted(vec.begin(), vec.end());
    cout << "10. Unique sorted from vector {4,2,4,1,3,2,5}:\n";
    for(int x : unique_sorted) cout << x << " "; cout << "\n\n";

    // Note: Policy-based data structures (ordered_set) are GCC-specific
    // and require extra headers. They are very powerful in advanced CP
    // for order statistics (k-th element, number of elements < x).
    // Example (commented out as it needs <ext/pb_ds/...>):
    /*
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
    
    ordered_set os;
    os.insert(10); os.insert(5); os.insert(15);
    cout << "0-th smallest: " << *os.find_by_order(0) << "\n";  // 5
    cout << "Number of elements < 12: " << os.order_of_key(12) << "\n";  // 2
    */

    cout << "All major set and multiset operations demonstrated!\n";
    return 0;
}