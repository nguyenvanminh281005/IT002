#include<bits/stdc++.h>
using namespace std;

struct matrix{
     int n,m;
    int A[2000][2000];

    void init_size(){
        cin>>this->n>>this->m;
    }

    void init_matrix(){
        for(int i=1; i<=this->n; i++){
            for(int j=1; j<=this->m; j++){
                cin>>A[i][j];
            }
        }
    }

    void sum(matrix& B){
        for(int i=1; i<=this->n; i++){
            for(int j=1; j<=this->m; j++){
                cout<<this->A[i][j]+B.A[i][j]<<' ';
            }
            cout<<'\n';
        }
    }

    void sub(matrix& B){
        for(int i=1; i<=this->n; i++){
            for(int j=1; j<=this->m; j++){
                cout<<this->A[i][j]-B.A[i][j]<<' ';
            }
            cout<<'\n';
        }
    }


    void mul(matrix& B){
        for(int i=1; i<=this->n; i++){
            for(int j=1; j<=this->m; j++){
                cout<<this->A[i][j]*B.A[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
};
matrix ma_tran_1,ma_tran_2;
int main(){
    cout<<"nhap kich thuoc : \n";
    ma_tran_1.init_size();
    cout<<"nhap ma tran A  : \n";
    ma_tran_1.init_matrix();

    ma_tran_2.n=ma_tran_1.n;
    ma_tran_2.m=ma_tran_1.m;
    cout<<"nhap ma tran B  : \n";
    ma_tran_2.init_matrix();
    cout<<"tong \n";
    ma_tran_1.sum(ma_tran_2);
    cout<<"hieu \n";
    ma_tran_1.sub(ma_tran_2);
    cout<<"tich \n";
    ma_tran_1.mul(ma_tran_2);
}
