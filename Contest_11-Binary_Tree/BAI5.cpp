#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void levelOrder(Node* root){
    queue<Node* >Q;
    Q.push(root);
    while(!Q.empty()){
        Node *nd = Q.front(); Q.pop();
        cout << nd->data << " ";
        if(nd->left!=NULL)    Q.push(nd->left);
        if(nd->right!=NULL)   Q.push(nd->right);
    }
}

void makeNode(Node *root,int n1,int n2,char c){
    switch(c){
        case 'L': root->left=new Node(n2);
                break;
        case 'R': root->right=new Node(n2);
                break;
    }
}
void insert(Node *root,int n1,int n2,char c){
     if(root==NULL) return;
     if(root->data == n1)
         makeNode(root,n1,n2,c);
     else{
         insert(root->left,n1,n2,c);
         insert(root->right,n1,n2,c);
     }
 }

main(){
  int t,n;
  cin>>t;
  while(t--) {
    cin>>n;
    Node *root=NULL;
    while(n--){
        int n1,n2; char c;
        cin>>n1>>n2>>c;
        if(root==NULL){
            root=new Node(n1);
            makeNode(root,n1,n2,c);
        }
        else insert(root,n1,n2,c);
    }
    levelOrder(root);
    cout << endl;
  }
}
