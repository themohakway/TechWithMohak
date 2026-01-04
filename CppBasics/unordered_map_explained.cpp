#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // =============================================
    // Section 1: Declaration and Initialization
    // =============================================
    // unordered_map<key_type, value_type>
    // Here: string keys → int values (e.g., fruit → quantity)
    unordered_map<string, int> fruits;

    cout << "Initial size: " << fruits.size() << endl << endl;

    // =============================================
    // Section 2: Insertion / Adding Elements
    // =============================================
    // Method 1: Using operator[] (inserts or overwrites)
    fruits["Apple"] = 10;
    fruits["Banana"] = 15;

    // Method 2: Using insert() with pair
    fruits.insert({"Orange", 8});

    // Method 3: Using insert() with make_pair
    fruits.insert(make_pair("Mango", 12));

    // Method 4: Bulk insert with initializer list (great for quick setup)
    // fruitInventory = {{"Grape", 20}, {"Kiwi", 5}};  // Uncomment if you want to reset

    cout << "After insertions:" << endl;
    cout << "Size: " << fruits.size() << endl << endl;

    // =============================================
    // Section 3: Accessing Elements
    // =============================================
    cout << "Quantity of Apple: " << fruits["Apple"] << endl;  // Uses []
    cout << "Quantity of Orange: " << fruits.at("Orange") << endl;  // Uses at()

    // Note: [] inserts 0 if key doesn't exist!
    cout << "\nTrying non-existent key with []:" << endl;
    cout << "Date (not present): " << fruits["Date"] << endl;  // Inserts "Date":0
    cout << "New size after [] access: " << fruits.size() << endl << endl;

    // =============================================
    // Section 4: Checking Existence - count() and find()
    // =============================================
    cout << "Does 'Banana' exist? " << (fruits.count("Banana") ? "Yes" : "No") << endl;
    cout << "Does 'Pineapple' exist? " << (fruits.count("Pineapple") ? "Yes" : "No") << endl << endl;

    // find() returns iterator (end() if not found)
    auto it = fruits.find("Mango");
    if (it != fruits.end()) {
        cout << "Found Mango: " << it->second << endl;
    } else {
        cout << "Mango not found!" << endl;
    }

    // =============================================
    // Section 5: Iteration
    // =============================================
    cout << "\nAll items in inventory (order is NOT sorted - hash-based):" << endl;
    for (const auto& pair : fruits) {  // Range-based for loop (C++11+)
        cout << pair.first << " : " << pair.second << endl;
    }
    cout << endl;

    // =============================================
    // Section 6: Removal / Erase
    // =============================================
    cout << "Erasing 'Banana'..." << endl;
    fruits.erase("Banana");  // Erase by key

    cout << "After erase:" << endl;
    cout << "Size: " << fruits.size() << endl;

    for (const auto& pair : fruits) {
        cout << pair.first << " : " << pair.second << endl;
    }
    cout << endl;

    // =============================================
    // Section 7: Clear the entire map
    // =============================================
    cout << "Clearing the entire map..." << endl;
    fruits.clear();

    cout << "Final size: " << fruits.size() << endl;  // Should be 0
    cout << "Is empty? " << (fruits.empty() ? "Yes" : "No") << endl;

    return 0;
}