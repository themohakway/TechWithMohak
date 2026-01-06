#include <bits/stdc++.h>
using namespace std;

// Step 1: Define the Node structure
// Each node holds data and a pointer (memory address) to the next node
struct Node {
    int data;       // The actual value we want to store
    Node* next;     // Pointer to the NEXT node (holds memory address)
    
    // Constructor - called when we create a new node
    Node(int val) {
        data = val;
        next = nullptr;  // Initially, this node points to nothing (NULL)
    }
};

// Step 2: LinkedList class to manage the entire list
class LinkedList {
private:
    Node* head;  // Pointer to the first node of the list
                 // Why pointer? Because head must point to a node on HEAP (long lifetime)

public:
    // Constructor - initializes empty list
    LinkedList() {
        head = nullptr;  // List is empty initially
        cout << "Linked List created!\n";
    }
    
    // Insert at beginning (head)
    void insertAtHead(int val) {
        // Create new node on HEAP using 'new'
        Node* newNode = new Node(val);  // new returns memory address
        
        // Link new node to current head
        newNode->next = head;
        
        // Update head to point to new node
        head = newNode;
        
        cout << val << " inserted at head\n";
    }
    
    // Insert at end (tail)
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        
        // If list is empty, new node becomes head
        if (head == nullptr) {
            head = newNode;
        } else {
            // Traverse to the last node
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;  // Move to next node
            }
            // Link last node to new node
            temp->next = newNode;
        }
        cout << val << " inserted at tail\n";
    }
    
    // Delete first occurrence of a value
    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "List empty! Cannot delete.\n";
            return;
        }
        
        // Special case: delete head
        if (head->data == val) {
            Node* temp = head;
            head = head->next;   // Move head forward
            delete temp;         // Free memory (important!)
            cout << val << " deleted (was head)\n";
            return;
        }
        
        // Search for the node
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }
        
        // If found
        if (temp->next != nullptr) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;  // Bypass the node
            delete nodeToDelete;            // Free memory
            cout << val << " deleted\n";
        } else {
            cout << val << " not found\n";
        }
    }
    
    // Search for a value
    bool search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }
    
    // Print entire list
    void printList() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        cout << "Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }
    
    // Destructor - clean up all nodes (prevent memory leak)
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        cout << "Linked List destroyed - memory freed!\n";
    }
};

// Main function - demo for your video
int main() {
    LinkedList ll;
    
    ll.printList();           // Empty list
    
    ll.insertAtHead(10);
    ll.insertAtHead(5);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    
    ll.printList();           // Expected: 5 -> 10 -> 20 -> 30 -> NULL
    
    cout << "Search 20: " << (ll.search(20) ? "Found" : "Not found") << "\n";
    cout << "Search 999: " << (ll.search(999) ? "Found" : "Not found") << "\n";
    
    ll.deleteNode(10);
    ll.deleteNode(5);
    ll.deleteNode(999);       // Not found
    
    ll.printList();           // Expected: 20 -> 30 -> NULL
    
    return 0;
}