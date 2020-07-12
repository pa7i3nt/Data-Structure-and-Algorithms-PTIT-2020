#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

Node* createBST(int *a, int start, int end){
    if(start > end) return NULL;
    int mid = (start + end)/2;
    Node* temp = newNode(a[mid]);
    temp->left = createBST(a, start, mid - 1);
    temp->right = createBST(a, mid + 1, end);
    return temp;
}

void preorder(Node* temp){
    if(temp){
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

main(){
    int t,n,i;
    cin>>t;
    while(t--){
        cin >> n;
        int a[n];
        for(i = 0; i < n; ++i) cin >> a[i];
        sort(a, a+n);
        Node *temp = createBST(a, 0, n - 1);
        preorder(temp);
        cout << endl;
    }
}
