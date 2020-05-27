// #include<bits/stdc++.h> 
// using namespace std; 
// int main() 
// { 
//     int t; cin>>t;
//     while(t--){
//         int n; int m; cin>>n>>m;
//         vector<int> squareList;
//         for(int i=1;i<=n;i++){
//             squareList.push_back(i);
//         }
//         int index=0;
//         while(squareList.size()>1){
//             for(int run=1;run<=m;run++){
//                 if(index!=squareList.size()-1) index++;
//                 else index=0;
//             }
//             // cout<<index<<" ";
//             if(index==squareList.size()-1){
//                 squareList.erase(squareList.begin()+0); index--;
//             }
//             else squareList.erase(squareList.begin()+(index+1));

//             // if(index>s.size()-1) index=s.size()-1;
//             // for(int i=0;i<squareList.size();i++) cout<<squareList[i]<<" "; cout<<endl;
//             // cout<<squareList.size()<<" ";
//         }
//         cout<<squareList.back()-1<<endl;
//     }
//     return 0; 
// } 

// // 1 2 3 4 5    4


#include <bits/stdc++.h> 
using namespace std; 
  
int josephus(int n, int k) 
{ 
    if (n == 1) 
        return 1; 
    else
        return (josephus(n - 1, k) + k) % n+1 ; 
} 
  
int main() 
{ 
    int t; cin>>t;
    while(t--){
        int n ; 
        int k; cin>>n>>k; 
        cout <<  josephus(n, k)<<endl; 
    }
    return 0; 
} 