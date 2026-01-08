#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Edge cases: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;  // Start fast one step ahead (your smart optimization)
        
        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast) {
                return true;  // Cycle detected!
            }
            
            slow = slow->next;          // Moves 1 step
            fast = fast->next->next;    // Moves 2 steps
        }
        
        return false;  // No cycle
    }
};

// Helper function to create a linked list with optional cycle
ListNode* createList(vector<int> values, int pos = -1) {
    if (values.empty()) return nullptr;
    
    vector<ListNode*> nodes;
    for (int val : values) {
        nodes.push_back(new ListNode(val));
    }
    
    for (int i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    
    // Create cycle if pos >= 0
    if (pos >= 0 && pos < nodes.size()) {
        nodes.back()->next = nodes[pos];
    }
    
    return nodes[0];
}

// Main function - Full demo for your video
int main() {
    Solution sol;
    
    // Test Case 1: Cycle at position 1 (3 -> 2 -> 0 -> -4 -> back to 2)
    ListNode* list1 = createList({3, 2, 0, -4}, 1);
    cout << "Test 1 (Cycle at index 1): " << (sol.hasCycle(list1) ? "Cycle Detected " : "No Cycle ") << "\n";
    
    // Test Case 2: Cycle at head (1 -> 2 -> back to 1)
    ListNode* list2 = createList({1, 2}, 0);
    cout << "Test 2 (Cycle at head): " << (sol.hasCycle(list2) ? "Cycle Detected " : "No Cycle ") << "\n";
    
    // Test Case 3: No cycle
    ListNode* list3 = createList({1, 2, 3, 4, 5});
    cout << "Test 3 (No cycle): " << (sol.hasCycle(list3) ? "Cycle Detected " : "No Cycle ") << "\n";
    
    // Test Case 4: Single node, no cycle
    ListNode* list4 = createList({1});
    cout << "Test 4 (Single node): " << (sol.hasCycle(list4) ? "Cycle Detected " : "No Cycle ") << "\n";
    
    // Test Case 5: Empty list
    ListNode* list5 = nullptr;
    cout << "Test 5 (Empty list): " << (sol.hasCycle(list5) ? "Cycle Detected " : "No Cycle ") << "\n";
    
    // Note: Don't delete nodes in cycle lists (infinite loop risk)
    
    return 0;
}