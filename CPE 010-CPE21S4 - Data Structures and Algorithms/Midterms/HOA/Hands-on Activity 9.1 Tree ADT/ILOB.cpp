#include <iostream>
using namespace std;

struct BNode {
    int data;
    BNode* left;
    BNode* right;
    BNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

BNode* buildTree() {
    BNode* root = new BNode(27);
    root->left = new BNode(14);
    root->left->left = new BNode(10);
    root->left->right = new BNode(19);
    root->right = new BNode(35);
    root->right->left = new BNode(31);
    root->right->right = new BNode(42);
    return root;
}

void preOrder(BNode* n) {
    if (n == NULL) return;
    cout << n->data << " ";
    preOrder(n->left);
    preOrder(n->right);
}

void inOrder(BNode* n) {
    if (n == NULL) return;
    inOrder(n->left);
    cout << n->data << " ";
    inOrder(n->right);
}

void postOrder(BNode* n) {
    if (n == NULL) return;
    postOrder(n->left);
    postOrder(n->right);
    cout << n->data << " ";
}

bool found = false;

void findData(BNode* n, int choice, int key) {
    if (n == NULL) return;
    if (n->data == key) {
        cout << key << " was found!\n";
        found = true;
        return;
    }
    if (choice == 1) {
        findData(n->left, choice, key);
        if (!found) findData(n->right, choice, key);
    }
    else if (choice == 2) {
        findData(n->left, choice, key);
        if (!found) findData(n->right, choice, key);
    }
    else if (choice == 3) {
        findData(n->left, choice, key);
        findData(n->right, choice, key);
    }
}

int main() {
    BNode* root = buildTree();
    
    cout << "Pre-order:  ";
    preOrder(root);
    cout << "\n";
    
    cout << "In-order:   ";
    inOrder(root);
    cout << "\n";
    
    cout << "Post-order: ";
    postOrder(root);
    cout << "\n\n";
    
    cout << "Find 19 using Pre-order:\n";
    found = false;
    findData(root, 1, 19);
    
    cout << "\nFind 31 using In-order:\n";
    found = false;
    findData(root, 2, 31);
    
    cout << "\nFind 42 using Post-order:\n";
    found = false;
    findData(root, 3, 42);
    
    return 0;
}