// File: queue_operations.cpp
// Topic: All Basic Queue Operations in C++ using STL
// Author: Mohak Maheshwari
// For: Coding Interviews | FAANG Preparation

#include <iostream>
#include <queue>      // STL Queue
#include <string>

using namespace std;

int main() {
    // 1. Create an empty queue
    queue<int> q;

    cout << "=== Basic Queue Operations ===\n\n";

    // 2. push() - Add element to the back (enqueue)
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "Pushed: 10, 20, 30, 40\n";

    // 3. size() - Get number of elements
    cout << "Current size: " << q.size() << "\n";

    // 4. front() - Access the front element (first in)
    cout << "Front element: " << q.front() << "\n";

    // 5. back() - Access the back element (last in)
    cout << "Back element: " << q.back() << "\n";

    // 6. pop() - Remove the front element (dequeue)
    cout << "Popping front...\n";
    q.pop();
    cout << "New front after pop: " << q.front() << "\n";
    cout << "New size after pop: " << q.size() << "\n";

    // 7. Check if queue is empty
    if (q.empty()) {
        cout << "Queue is empty!\n";
    } else {
        cout << "Queue is not empty.\n";
    }

    // 8. Empty the queue completely
    cout << "\nEmptying the queue...\n";
    while (!q.empty()) {
        cout << "Dequeued: " << q.front() << "\n";
        q.pop();
    }

    cout << "Queue is now empty. Size: " << q.size() << "\n";

    // Bonus: Queue of strings (common in interviews)
    queue<string> strQ;
    strQ.push("Mohak");
    strQ.push("Maheshwari");
    strQ.push("FAANG");
    cout << "\nString Queue Example:\n";
    cout << "Front: " << strQ.front() << "\n";

    return 0;
}