#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;

    float sum,charge;

    scanf("%d",&n);

    if(n <= 50){

        sum = n*0.5;

    }else if(n>50 && n <= 150){

        sum = (50*0.5) + ((n-50)*0.75);

    }else if(n>150 && n<= 250){

        sum = (50*0.5) + (100*0.75) + ((n-150)*1.25);

    }else if(n>250){

        sum = (50*0.5) + (100*0.75) + (100*1.25) + ((n-250)*2.5);
    }

    if(n<=10){

        sum+=sum*0.2;

    }else if(n>10 && n<=100){

        sum+=sum*0.5;

    }else{

        sum+=sum*0.7;

    }

    printf("%.2f",sum);

    return 0;
}
