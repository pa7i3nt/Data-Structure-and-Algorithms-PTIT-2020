#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;

	Node(int x){
	    data = x;
	    left = right = NULL;
	}
};

void getleafsum(Node* root,bool dir,int &sum){
    if(root==NULL)  return;

    if(dir==true && !root->left && !root->right)
    sum+=root->data;

    getleafsum(root->left,true,sum);

    getleafsum(root->right,false,sum);
}

int leftLeafSum(Node* root){
    int sum=0;
    bool direction=true;
    getleafsum(root,direction,sum);
    return sum;
}

main(){
  int t,n,n1,n2; char lr;
  cin>>t;
  while (t--){
     map<int, Node*> m;
     cin>>n;
     Node *root = NULL;
     Node *child;
     while (n--){
        Node *parent;
        cin>>n1>>n2>>lr;
        if (m.find(n1) == m.end()){
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')  parent->left = child;
        else            parent->right = child;
        m[n2]  = child;
     }
     cout<<leftLeafSum(root)<<endl;
  }
}
