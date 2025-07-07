#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <map>

using namespace std;

int main() {
    // VECTOR: Dynamic array, fast random access, slow insert/erase except at end
    vector<int> vec = {1, 2, 3};
    vec.push_back(4); // Add at end
    cout << "Vector: ";
    for (int v : vec) cout << v << " ";
    cout << endl;

    // LIST: Doubly linked list, fast insert/erase anywhere, slow random access
    list<int> lst = {1, 2, 3};
    lst.push_back(4);
    lst.push_front(0);
    cout << "List: ";
    for (int l : lst) cout << l << " ";
    cout << endl;

    // STACK: LIFO structure, only top accessible
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout << "Stack (top to bottom): ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    // MAP: Key-value pairs, sorted by key, fast lookup by key
    map<string, int> mp;
    mp["apple"] = 3;
    mp["banana"] = 5;
    cout << "Map: ";
    for (const auto& pair : mp)
        cout << "{" << pair.first << ": " << pair.second << "} ";
    cout << endl;

    // Differences summary
    cout << "\nSummary:\n";
    cout << "vector: dynamic array, fast random access, slow insert/erase except at end\n";
    cout << "list: doubly linked list, fast insert/erase anywhere, slow random access\n";
    cout << "stack: LIFO, only top accessible, built on vector/list/deque\n";
    cout << "map: key-value pairs, sorted by key, fast lookup by key\n";

    return 0;
}