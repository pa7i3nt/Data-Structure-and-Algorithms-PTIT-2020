#include <bits/stdc++.h>
using namespace std;

//matrix
// 0 1 1 0 1
// 1 1 0 1 0
// 0 1 1 1 0
// 1 1 1 1 0
// 1 1 1 1 1
// 0 0 0 0 0

//table luu bang phuong an
// 0 1 1 0 1
// 1 1 0 1 0
// 0 1 1 1 0
// 1 1 2 2 0
// 1 2 2 3 1
// 0 0 0 0 0
int row,col,matrix[501][501],table[501][501]; 

int result(){

    //khoi tao gia tri QHD co so voi hang dau, cot dau cua bang phuong an trung voi matrix
    for(int i=1;i<=col;i++) table[1][i]=matrix[1][i];
    for(int i=1;i<=row;i++) table[i][1]=matrix[i][1];

    //   cong thuc QHD
    //   matrix[i][j] = 1 
    //         table[i][j] = min(table[i][j-1], table[i-1][j], table[i-1][j-1]) + 1
    //   matrix[i][j] = 0
    //         table[i][j] = 0
    //   res se la max cua table
    int MAX= INT_MIN;
    for(int i=2;i<=row;i++){
        for(int j=2;j<=col;j++){
            if(matrix[i][j]==1){
                table[i][j]=min(
                                    min(table[i-1][j],table[i][j-1]),
                                    table[i-1][j-1]
                                ) +1 ;
            }else table[i][j]=0;

            MAX=max(MAX,table[i][j]);
        }
    }

    return MAX;


}


main(){
    int t; cin>>t;
    while(t--){
        cin>>row>>col;
        for(int i=1;i<=row;i++) for(int j=1;j<=col;j++) cin>>matrix[i][j];
        cout<<result()<<endl;
    }
}