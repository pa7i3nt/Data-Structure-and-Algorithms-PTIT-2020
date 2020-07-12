#include<bits/stdc++.h>
using namespace std;
struct Node{
	char data;
	Node *left, *right;
};

bool toanTu(char c){
	return(c == '-' || c == '+' || c == '*' || c == '/' || c == '^');
}

Node *creatNode(char c){
	Node *p = new Node;
	p->left = p->right = NULL;
	p->data = c;
	return p;
}

void Duyet(Node *t){
	if(t!=NULL){
		Duyet(t->left);
		cout<<t->data<<" ";
		Duyet(t->right);
	}
}

Node *taocay(string hauto){
	stack<Node*> S;
	Node *t, *t1, *t2;
	for(int i=0;i<hauto.length();i++){
		if(!toanTu(hauto[i])){
			t = creatNode(hauto[i]);
			S.push(t);
		}
		else{
			t = creatNode(hauto[i]);

			t1 = S.top();	S.pop();
			t2 = S.top();	S.pop();

			t->right = t1;
			t->left  = t2;
			S.push(t);
		}
	}
	return S.top();
}

main(){
	int t; cin>>t;
	while(t--){
		string hauto;
		cin>>hauto;
		Node *t = taocay(hauto);
		Duyet(t);
		cout<<endl;
	}
}
