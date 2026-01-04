// Major Array Operations in C++ for Competitive Programming & Interviews

#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. Fixed-size array declaration
    int arr[10];                    // Uninitialized array of 10 ints
    int arr2[5] = {1, 2, 3, 4, 5};   // Initialized
    int arr3[] = {10, 20, 30};      // Size inferred (3)
    int n = 5;
    // int dynamic[n];              // NOT allowed in standard C++ (VLA - GCC extension only)

    cout << "1. Fixed-size arrays:\n";
    cout << "arr2: ";
    for(int i = 0; i < 5; i++) cout << arr2[i] << " ";
    cout << "\n\n";

    // 2. Size and bounds (manual tracking needed)
    cout << "2. Size handling:\n";
    cout << "sizeof(arr2) = " << sizeof(arr2) << " bytes\n";
    cout << "Number of elements = " << sizeof(arr2)/sizeof(arr2[0]) << "\n\n";

    // 3. Accessing and modifying elements
    arr2[0] = 100;                  // Modify
    cout << "3. After arr2[0] = 100: " << arr2[0] << "\n";
    cout << "Last element (arr2[4]): " << arr2[4] << "\n\n";

    // 4. Looping over array
    cout << "4. Looping techniques:\n";
    cout << "Classic for loop:\n";
    for(int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << "\n";

    cout << "Range-based for (read-only):\n";
    for(int x : arr2) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Range-based for (modifiable):\n";
    for(int &x : arr2) {
        x *= 2;                     // Double each element
    }
    for(int x : arr2) cout << x << " ";
    cout << "\n\n";

    // 5. Filling array
    int arr_fill[10];
    fill(arr_fill, arr_fill + 10, 42);  // All elements = 42
    memset(arr_fill, 0, sizeof(arr_fill)); // Fast zero-fill (for int/char/byte)

    cout << "5. After fill and memset:\n";
    cout << "First few of arr_fill: ";
    for(int i = 0; i < 5; i++) cout << arr_fill[i] << " ";
    cout << "...\n\n";

    // 6. Sorting array
    int arr_sort[] = {64, 34, 25, 12, 22, 11, 90};
    int sz = sizeof(arr_sort)/sizeof(arr_sort[0]);

    sort(arr_sort, arr_sort + sz);              // Ascending
    cout << "6. Sorted ascending: ";
    for(int i = 0; i < sz; i++) cout << arr_sort[i] << " ";
    cout << "\n";

    sort(arr_sort, arr_sort + sz, greater<int>()); // Descending
    cout << "Sorted descending: ";
    for(int i = 0; i < sz; i++) cout << arr_sort[i] << " ";
    cout << "\n\n";

    // 7. Reversing
    reverse(arr_sort, arr_sort + sz);
    cout << "7. After reverse: ";
    for(int i = 0; i < sz; i++) cout << arr_sort[i] << " ";
    cout << "\n\n";

    // 8. Finding min and max
    int arr_mm[] = {3, 7, 2, 9, 1};
    int sz_mm = sizeof(arr_mm)/sizeof(arr_mm[0]);
    int min_val = *min_element(arr_mm, arr_mm + sz_mm);
    int max_val = *max_element(arr_mm, arr_mm + sz_mm);
    cout << "8. Min = " << min_val << ", Max = " << max_val << "\n\n";

    // 9. Binary search (on sorted array)
    sort(arr_sort, arr_sort + sz);
    bool found = binary_search(arr_sort, arr_sort + sz, 25);
    cout << "9. Is 25 present (after sorting)? " << (found ? "Yes" : "No") << "\n";

    auto it = lower_bound(arr_sort, arr_sort + sz, 25);  // First >= 25
    if (it != arr_sort + sz)
        cout << "lower_bound(25) at index: " << (it - arr_sort) << "\n\n";

    // 10. Unique elements (remove consecutive duplicates)
    int arr_unique[] = {1, 1, 2, 2, 3, 3, 4};
    int sz_u = sizeof(arr_unique)/sizeof(arr_unique[0]);
    sort(arr_unique, arr_unique + sz_u);
    auto last = unique(arr_unique, arr_unique + sz_u);  // Moves uniques to front
    int new_size = last - arr_unique;
    cout << "10. After unique (new size = " << new_size << "): ";
    for(int i = 0; i < new_size; i++) cout << arr_unique[i] << " ";
    cout << "\n\n";

    // 11. Multi-dimensional arrays
    int mat[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    cout << "11. 3x4 Matrix:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // 12. Passing arrays to functions
    auto print_arr = [](int a[], int size) {
        for(int i = 0; i < size; i++) cout << a[i] << " ";
        cout << "\n";
    };
    cout << "12. Printing via lambda function:\n";
    print_arr(arr2, 5);

    return 0;
}