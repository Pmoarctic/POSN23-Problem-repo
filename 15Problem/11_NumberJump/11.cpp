#include<bits/stdc++.h>
using namespace std;

int arr[21];

int main(){

    int n,m ;

    scanf("%d %d",&n,&m);

    for(int i=n;i<=m;i++){

        if(i>=10){

            for(int j=i;j>0;j/=10){

                arr[j%10]++;

            }

        }

        else(arr[i%10]++);

    }

    for(int i=0;i<10;i++){

        printf("%d %d\n",i,arr[i]);

    }


    return 0;
}
