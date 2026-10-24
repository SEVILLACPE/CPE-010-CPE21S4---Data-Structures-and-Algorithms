#include <iostream>
#include <vector>
using namespace std;

struct GNode {
    char data;
    vector<GNode*> children;
    GNode(char val) {
        data = val;
    }
};

GNode* buildTree() {
    GNode* A = new GNode('A');
    GNode* B = new GNode('B');
    GNode* C = new GNode('C');
    GNode* D = new GNode('D');
    GNode* E = new GNode('E');
    GNode* F = new GNode('F');
    GNode* G = new GNode('G');
    
    A->children.push_back(B);
    A->children.push_back(C);
    A->children.push_back(D);
    A->children.push_back(E);
    A->children.push_back(F);
    A->children.push_back(G);
    
    GNode* H = new GNode('H');
    D->children.push_back(H);
    
    GNode* I = new GNode('I');
    GNode* J = new GNode('J');
    E->children.push_back(I);
    E->children.push_back(J);
    
    GNode* K = new GNode('K');
    GNode* L = new GNode('L');
    GNode* M = new GNode('M');
    F->children.push_back(K);
    F->children.push_back(L);
    F->children.push_back(M);
    
    GNode* N = new GNode('N');
    G->children.push_back(N);
    
    GNode* P = new GNode('P');
    GNode* Q = new GNode('Q');
    J->children.push_back(P);
    J->children.push_back(Q);
    
    return A;
}

void preOrder(GNode* n) {
    if (n == NULL) return;
    cout << n->data << " ";
    for (int i = 0; i < n->children.size(); i++) {
        preOrder(n->children[i]);
    }
}

void postOrder(GNode* n) {
    if (n == NULL) return;
    for (int i = 0; i < n->children.size(); i++) {
        postOrder(n->children[i]);
    }
    cout << n->data << " ";
}

int main() {
    GNode* root = buildTree();
    
    cout << "Pre-order:  ";
    preOrder(root);
    cout << "\n";
    
    cout << "Post-order: ";
    postOrder(root);
    cout << "\n";
    
    return 0;
}