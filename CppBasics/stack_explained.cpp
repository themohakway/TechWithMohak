#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // 1. Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Stack size after pushes: " << s.size() << endl;           // 4

    // 2. Access top element (peek)
    cout << "Top element: " << s.top() << endl;                        // 40

    // 3. Pop (remove top)
    s.pop();   // removes 40
    cout << "After pop, new top: " << s.top() << endl;                 // 30

    // 4. Check if empty
    if (s.empty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is NOT empty, size = " << s.size() << endl;     // size = 3
    }

    // 5. Pop everything (useful in many problems)
    cout << "\nPopping all elements:\n";
    while (!s.empty()) {
        cout << "Top = " << s.top() << " → popping..." << endl;
        s.pop();
    }

    // 6. After all pops
    cout << "Is stack empty now? " << (s.empty() ? "Yes" : "No") << endl;

    // Bonus: You can also use clear() (C++11+)
    // s.clear();  // instantly empty the stack

    return 0;
}