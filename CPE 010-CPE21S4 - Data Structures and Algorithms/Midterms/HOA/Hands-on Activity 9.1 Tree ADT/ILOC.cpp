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

BNode* insert(BNode* n, int val) {
    if (n == NULL) {
        return new BNode(val);
    }
    if (val < n->data) {
        n->left = insert(n->left, val);
    }
    else if (val > n->data) {
        n->right = insert(n->right, val);
    }
    return n;
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

int main() {
    BNode* root = NULL;
    int values[] = {2, 3, 9, 18, 0, 1, 4, 5};
    
    for (int i = 0; i < 8; i++) {
        root = insert(root, values[i]);
    }
    
    cout << "Pre-order:  ";
    preOrder(root);
    cout << "\n";
    
    cout << "In-order:   ";
    inOrder(root);
    cout << "\n";
    
    cout << "Post-order: ";
    postOrder(root);
    cout << "\n";
    
    return 0;
}