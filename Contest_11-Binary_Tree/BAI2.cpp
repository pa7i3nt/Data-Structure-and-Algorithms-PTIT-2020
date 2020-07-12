#include <bits/stdc++.h>
using namespace std;
struct Node{
    string data;
    Node *left, *right;

    Node(string x){
        data = x;
        left = right = NULL;
    }
};

long long toNum(string s){
    int i;
    long long ans = 0;
    if(s[0] == '-'){
        s.erase(0,1);
        for(i=0;i<s.length();i++) ans = ans*10 + s[i]-'0';
        return -ans;
    }
    for(i=0;i<s.length();i++) ans = ans*10 + s[i]-'0';
    return ans;
}

long long evalTree(Node* root){
    if(root->left==NULL&&root->right==NULL)
        return toNum(root->data);
    if(root->data=="+")
        return evalTree(root->left) + evalTree(root->right);
    if(root->data=="-")
        return evalTree(root->left) - evalTree(root->right);
    if(root->data=="*")
        return evalTree(root->left) * evalTree(root->right);
    return evalTree(root->left) / evalTree(root->right);
}

main(){
    int t,n,i; cin>>t;
    while(t--){
        cin>>n;
        string s[n];
        for(i=0;i<n;i++) cin>>s[i];

        int p=0;
        Node *root = new Node(s[p]);
        queue<Node *> Q;
        Q.push(root);
        p=1;
        while(!Q.empty()){
            Node *f = Q.front(); Q.pop();
            Node *l,*r;

            if(p!=n){
                l=new Node(s[p]);
                f->left = l;
                p++;
                Q.push(l);
            } else 	f->left = NULL;

            if(p!=n){
                r=new Node(s[p]);
                f->right = r;
                p++;
                Q.push(r);
            } else	f->right=NULL;
        }
        cout<<evalTree(root)<<endl;
    }
}
