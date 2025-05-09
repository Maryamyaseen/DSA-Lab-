#include <iostream>
using namespace std;
struct Node {
    int data, height;
    Node *left, *right;
    Node(int v) : data(v), height(1), left(0), right(0) {}
};
Node* insertBST(Node* r, int v) {
    if (!r) return new Node(v);
    if (v < r->data) r->left = insertBST(r->left, v);
    else r->right = insertBST(r->right, v);
    return r;
}
int h(Node* n) { return n ? n->height : 0; }
int bal(Node* n) { return h(n->left) - h(n->right); }
int max(int a, int b) { return a > b ? a : b; }
Node* rotR(Node* y) {
    Node* x = y->left, *T = x->right;
    x->right = y; y->left = T;
    y->height = 1 + max(h(y->left), h(y->right));
    x->height = 1 + max(h(x->left), h(x->right));
    return x;
}
Node* rotL(Node* x) {
    Node* y = x->right, *T = y->left;
    y->left = x; x->right = T;
    x->height = 1 + max(h(x->left), h(x->right));
    y->height = 1 + max(h(y->left), h(y->right));
    return y;
}
Node* insertAVL(Node* r, int v) {
    if (!r) return new Node(v);
    if (v < r->data) r->left = insertAVL(r->left, v);
    else if (v > r->data) r->right = insertAVL(r->right, v);
    else return r;
    r->height = 1 + max(h(r->left), h(r->right));
    int b = bal(r);
    if (b > 1 && v < r->left->data) return rotR(r);
    if (b < -1 && v > r->right->data) return rotL(r);
    if (b > 1 && v > r->left->data) { r->left = rotL(r->left); return rotR(r); }
    if (b < -1 && v < r->right->data) { r->right = rotR(r->right); return rotL(r); }
    return r;
}
void inorder(Node* r) {
    if (!r) return;
    inorder(r->left); cout << r->data << " "; inorder(r->right);
}
int main() {
    Node *bst = 0, *avl = 0;
    int ch, x;
    while (1) {
        cout << "\n1.Insert BST  2.Insert AVL  3.BST Inorder  4.AVL Inorder  5.Exit\n> ";
        cin >> ch;
        if (ch == 1) cin >> x, bst = insertBST(bst, x);
        else if (ch == 2) cin >> x, avl = insertAVL(avl, x);
        else if (ch == 3) inorder(bst), cout << endl;
        else if (ch == 4) inorder(avl), cout << endl;
        else break;
    }
}

