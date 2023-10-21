#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int arr[5];

int main(){

    for(int i=0;i<3;i++){
        scanf(" %d", &arr[i]);
    }
    sort(arr,arr+3);
    for(int i=0;i<3;i++){
        char tmp;
        scanf(" %c", &tmp);
        printf("%d ",arr[tmp-'A']);
    }

    return 0;
}
