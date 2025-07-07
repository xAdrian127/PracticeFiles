#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {} // Constructor to initialize a node
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Returns true if found, and sets 'position' to the depth (root is 0)
bool search(Node* root, int key, int& position, int depth = 0) {
    if (!root) return false;
    if (root->data == key) {
        position = depth;
        return true;
    }
    if (key < root->data)
        return search(root->left, key, position, depth + 1);
    else
        return search(root->right, key, position, depth + 1);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);

    int key = 6;
    int position;
    if (search(root, key, position))
        cout << key << " found in BST at depth " << position << "." << endl;
    else
        cout << key << " not found in BST." << endl;

    return 0;
}