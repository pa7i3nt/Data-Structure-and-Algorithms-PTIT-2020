#include <bits/stdc++.h>
using namespace std;
int ans;

struct Node {
    int data, height;
    Node *left, *right;
};

void printPostOrderBST(Node *root) {
    if (root == nullptr) return;
    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* cur = s1.top();
        s1.pop();
        s2.push(cur);

        if (cur->left) s1.push(cur->left);
        if (cur->right) s1.push(cur->right);
    }

    while (!s2.empty()) {
        Node* cur = s2.top();
        s2.pop();
        cout << cur->data << " ";
    }
}

Node* buildPreOrderBST(int* a, int n, int h){
    if (n <= 0) return nullptr;
    Node* root = new Node;
    root->data = a[0];
    root->height = h;
    ans = max(ans, h);
    int i = 0;
    for (i = 1; i < n; i++)
        if (a[i] > a[0]) break;
    root->left = buildPreOrderBST(&a[1], i-1, h+1);
    root->right = buildPreOrderBST(&a[i], n-i, h+1);
}

bool verifyPreOrderBST(int* a, int n){
    if (n <= 0) return true;
    int i = 0, j;
    for (i = 1; i < n; i++)
        if (a[i] > a[0]) break;
    for (j = 1; j < i; j++) {
        if (a[0] <= a[j]) {
            cout << "NO";
            return false;
        }
    }
    for (j = i; j < n; j++) {
        if (a[0] >= a[j]) {
            cout << "NO";
            return false;
        }
    }
    return (true && verifyPreOrderBST(&a[1], i-1) && verifyPreOrderBST(&a[i], n-i));
}

void preOrderToPostOrderBST(int* a, int n){
    ans = 0;
    if (!verifyPreOrderBST(a, n)) return;
    Node *root = buildPreOrderBST(a, n, 0);
    cout << ans << endl;
}

main(){
    int a[1000], t, n, i;
    cin >> t;

    while (t--){
        cin >> n;
        for (i=0; i<n; i++) cin >> a[i];
        preOrderToPostOrderBST(a, n);
    }
}
