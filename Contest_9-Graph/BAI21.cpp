#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

int v, e;
bool chuaxet[MAX];
vector<int> arr[MAX];
vector<int> edgeList[500000];

int thanh_phan_lien_thong() {
    int count = 0, x, y, j;
    memset(chuaxet, true, sizeof(chuaxet));

    for (int i = 1; i <= v; i++) {
        if (chuaxet[i]) {
            count++;
            stack<int> st;
            st.push(i);
            chuaxet[i] = false;

            while (!st.empty()) {
                x = st.top(); st.pop();
                for (j = 0; j < arr[x].size(); j++) {
                    y = arr[x][j];
                    if (chuaxet[y]) {
                        chuaxet[y] = false;
                        st.push(x);
                        st.push(y);
                        break;
                    }
                }
            }
        }
    }
    
    return count;
}

int result(int dinh1, int dinh2) {
    int res = 0, x, y, j;
    memset(chuaxet, true, sizeof(chuaxet));

    for (int i = 1; i <= v; i++) {
        if (chuaxet[i]) {
            res++;
            stack<int> st;
            st.push(i);
            chuaxet[i] = false;

            while (!st.empty()) {
                x = st.top(); st.pop();
                for (j = 0; j < arr[x].size(); j++) {
                    y = arr[x][j];
                    if ((y == dinh1 && x == dinh2) ||
                        (y == dinh2 && x == dinh1) ||
                        (chuaxet[y]) == false)
                            continue;
                    else {
                        chuaxet[y] = false;
                        st.push(x);
                        st.push(y);
                    }
                }
            }
        }
    }

    return res;
}

int main() {
    int t, tmp1, tmp2;
    cin >> t;
    while (t--) {
        for (int i = 0; i < MAX; i++) {
            arr[i].clear();
            edgeList[i].clear();
        }
        
        cin >> v >> e;

        for (int i = 0; i < e; i++) {
            cin >> tmp1 >> tmp2;
            arr[tmp1].push_back(tmp2);
            arr[tmp2].push_back(tmp1);
            edgeList[i].push_back(tmp1);
            edgeList[i].push_back(tmp2);
        }

        int soTPLT = thanh_phan_lien_thong();


        for (int i = 0; i < e; i++) {
            if (result(edgeList[i][0], edgeList[i][1]) > soTPLT)
                cout << edgeList[i][0] << " " << edgeList[i][1] << " ";
        }

        cout << '\n';
    }
    return 0;
}