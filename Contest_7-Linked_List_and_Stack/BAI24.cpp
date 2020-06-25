#include <bits/stdc++.h>
using namespace std;

struct Node {
    int somu;
    int heso;
    Node *next;
};

struct List {
    Node *first, *last;
};

void init(List &ls) {
    ls.first = ls.last = NULL;
}

Node *creatNode (int h, int s) {
    Node *p;
    p = new Node;
    if (p == NULL)
        return NULL;
    
    p -> heso = h;
    p -> somu = s;
    p -> next = NULL;

    return p;
}

void addLast(List &ls, Node *new_ele) {
    if (ls.first == NULL)
        ls.first = ls.last = new_ele;

    else {
        ls.last -> next = new_ele;
        ls.last = new_ele;
    }
}

void insertLast(List &ls, int h, int s) {
    Node *new_ele = creatNode(h, s);

    if (new_ele == NULL)
        return;

    addLast(ls, new_ele);
}

void nhapDaThuc(List &ls, string str) {
    int n = str.length(), i, h, s;
    for (i = 0; i <= n; i++) {
        if (isdigit(str[i])) {
            int x = 0;

            while (i < n && isdigit(str[i])) {
                x = (x * 10) + (str[i] - '0');
                i++;
            }

            if (!isdigit(str[i]) && str[i] == '*') {
                h = x;
                i--;
            }

            else if (!isdigit(str[i]) && (str[i] == ' ' || str[i] == '\0')) {
                s = x;
                i--;
            }

        }

        if (str[i] == '+' || i == n - 1)
            insertLast(ls, h, s);
    }
}

void printList(List &ls) {
    Node *p;
    p = ls.first;
    while (p != NULL) {
        if (p -> next == NULL) {
            cout << p -> heso << "*x^" << p -> somu;
        }
        else {
            cout << p -> heso << "*x^" << p -> somu << " + ";
        }

        p = p -> next;
    }
    cout << endl;
}

// R = P + Q
void congDaThuc(List &P, List &Q, List &R) {
    init(R);
    Node *p = P.first, *q = Q.first;
    int tongHeSo;
    while (p && q) {
        if (p -> somu == q -> somu) {
            tongHeSo = p -> heso + q -> heso;
            if (tongHeSo != -1)
                insertLast(R, tongHeSo, p -> somu);
            
            p = p -> next;
            q = q -> next;
        }

        else {
            if (p -> somu > q -> somu) {
                insertLast(R, p -> heso, p -> somu);
                p = p -> next;
            }

            else if (p -> somu < q -> somu) {
                insertLast(R, q -> heso, q -> somu);
                q = q -> next;
            }
        }
    }

    while (q) {
        insertLast(R, q -> heso, q -> somu);
        q = q -> next;
    }

    while (p) {
        insertLast(R, p -> heso, p -> somu);
        p = p -> next;
    }
}

int main() {
    int t;
    List P, Q, R;
    string str1, str2;
    cin >> t;
    cin.ignore();
    while (t--) {
        init(P);
        init(Q);
        init(R);

        getline(cin, str1);
        nhapDaThuc(P, str1);
        // printList(P);


        getline(cin, str2);
        nhapDaThuc(Q, str2);
        // printList(Q);

        congDaThuc(P, Q, R);

        printList(R);
    }
    return 0;
}