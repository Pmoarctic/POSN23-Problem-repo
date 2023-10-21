#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; // max30
    scanf("%d",&n);
    long long arr[n][n];
    int cnt[n]={0};

    arr[0][0]=1;
    cnt[0]=1;
    arr[1][0]=1;
    arr[1][1]=1;

    for(int i=1;i<n;i++){
        arr[i][0]=1;
        arr[i][i]=1;
        cnt[i]+=i+2;
        for(int j=1;j<i;j++){
            arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
            cnt[i]+= floor(log10(arr[i][j]))+1;
        }

    }
    int tmp = cnt[n-1]/2;
    for(int i=0;i<n;i++){
        /*for(int j=0;j<tmp-(cnt[i]/2);j++)
            printf(" ");*/

        for(int j=0;j<=i;j++)
            printf("%lld ",arr[i][j]);
        printf("\n");
    }
}
