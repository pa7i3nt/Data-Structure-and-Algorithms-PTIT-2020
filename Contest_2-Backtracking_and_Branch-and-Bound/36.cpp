#include <iostream>
using namespace std;
int a,b,c,d,e,testCase;

//index chi muc 1,2,3,4,5 ung voi a,b,c,d,e
//mark danh dau gia tri a,b,c,d,e da dung
//mangHoanVi luu mot hoan vi cua a...e
int index[6],mark[6],mangHoanVi[6];

//toan tu luu cac toan tu vi tri (1)...(4)
//1 ung voi +; 2 ung voi -  ; 3 ung voi *;
int toanTu[5];

//kiem tra dang thuc
bool kiemTraDangThuc(){
    int temp;
    switch(toanTu[1]){
        case 1: {temp=mangHoanVi[1]+mangHoanVi[2];break;}
        case 2: {temp=mangHoanVi[1]-mangHoanVi[2];break;}
        case 3: {temp=mangHoanVi[1]*mangHoanVi[2];break;}
    }
    for(int i=2;i<=4;i++){
        switch(toanTu[i]){
            case 1: {temp+=mangHoanVi[i+1];break;}
            case 2: {temp-=mangHoanVi[i+1];break;}
            case 3: {temp*=mangHoanVi[i+1];break;}
        }
    }
    return temp==23;
}
//tao bieu thuc + - * 
void taoBieuThuc(int i){
    if(testCase) return;
    for(int j=1;j<=3;j++){
        toanTu[i]=j;
        if(i==4){
            if(kiemTraDangThuc()){
                testCase++;
                if(testCase) return;
            }
            // kiemTraDangThuc();
        }else taoBieuThuc(i+1);
    }
}


//luu cac hoan vi cua a,b...e
void writeHoanViabcde(){
    for(int i=1;i<=5;i++) {
        switch(index[i]){
            case 1: {mangHoanVi[i]=a;break;}
            case 2: {mangHoanVi[i]=b;break;}
            case 3: {mangHoanVi[i]=c;break;}
            case 4: {mangHoanVi[i]=d;break;}
            case 5: {mangHoanVi[i]=e;break;}
        }
        // cout<< mangHoanVi[i];         test
    }
    // cout<<endl;
}
// quay lui index
void hoanVi(int i){
    if(testCase) return;
    for(int j=1;j<=5;j++){
        if(testCase) return;
        if(!mark[j]){
            index[i]=j;
            mark[j]=1;
            if(i==5){
                writeHoanViabcde();
                taoBieuThuc(1);
            }else hoanVi(i+1);
            mark[j]=0;
        }
    }
}

main(){
    int t;cin>>t;
    while(t--){
        testCase=0;
        cin>>a>>b>>c>>d>>e;
        hoanVi(1);
        testCase?cout<<"YES":cout<<"NO"; cout<<endl;
    }

}