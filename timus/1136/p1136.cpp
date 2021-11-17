#include <bits/stdc++.h>
using namespace std;

struct BST {
    int v;
    BST *left, *right;

    BST() : v(0), left(NULL), right(NULL) {
    }

    BST(int value) {
        v = value;
        left = right = NULL;
    }

    BST* insert(BST* root, int value) {
        if (!root)
            return new BST(value);
        if (value > root->v)
            root->right = insert(root->right, value);
        else
            root->left = insert(root->left, value);
        return root;
    }

    void walk(BST* root) {
        if (!root)
            return;
        walk(root->right);
        walk(root->left);
        cout << root->v << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    BST bst, *root = NULL;
    for (int i = n - 1; i >= 0; i--)
        root = bst.insert(root, a[i]);
    bst.walk(root);
    return 0;
}
