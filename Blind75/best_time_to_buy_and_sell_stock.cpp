#include <bits/stdc++.h>
using namespace std;

// Function to find maximum profit using Sliding Window (Two Pointers)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;
    
    int left = 0;                    // Buy pointer (lowest price seen so far)
    int maxProfit = 0;
    
    for (int right = 1; right < n; right++) {
        if (prices[right] < prices[left]) {
            left = right;           // Found a better (cheaper) day to buy
        } else {
            // Current day is profitable compared to our best buy day
            maxProfit = max(maxProfit, prices[right] - prices[left]);
        }
    }
    
    return maxProfit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Multiple test cases for demonstration
    vector<vector<int>> testCases = {
        {7, 1, 5, 3, 6, 4},    // Expected: 5 (buy at 1, sell at 6)
        {7, 6, 4, 3, 1},       // Expected: 0 (prices only decreasing)
        {1, 2, 3, 4, 5},       // Expected: 4 (buy at 1, sell at 5)
        {3, 3, 5, 0, 0, 3, 1, 4}, // Expected: 6
        {1},                   // Expected: 0 (single day)
        {}                     // Expected: 0 (empty)
    };
    
    for (int i = 0; i < testCases.size(); i++) {
        vector<int> prices = testCases[i];
        
        cout << "Test Case " << (i + 1) << ":\n";
        cout << "Prices: [";
        for (int j = 0; j < prices.size(); j++) {
            cout << prices[j];
            if (j < prices.size() - 1) cout << ", ";
        }
        cout << "]\n";
        
        int profit = maxProfit(prices);
        cout << "Maximum Profit: " << profit << "\n\n";
    }
    
    return 0;
}