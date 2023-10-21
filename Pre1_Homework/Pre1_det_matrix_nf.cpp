#include<iostream>
using namespace std;

int arr1[5][5];
int arr[5][5];

int main(){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf(" %d",&arr1[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int tmp;
            scanf(" %d",&tmp);
            arr[i][j] = tmp + arr1[i][j];
        }
    }
    int p1,p2,p3,m1,m2,m3;
    p1 = arr[0][0]*arr[1][1]*arr[2][2];
    p2 = arr[0][1]*arr[1][2]*arr[2][0];
    p3 = arr[0][2]*arr[1][0]*arr[2][1];
    m1 = arr[0][1]*arr[1][0]*arr[2][2];
    m2 = arr[0][0]*arr[1][2]*arr[2][1];
    m3 = arr[0][2]*arr[1][1]*arr[2][0];
    int det = p1+p2+p3-m1-m2-m3;
    printf("%d",det);

    return 0;
}
