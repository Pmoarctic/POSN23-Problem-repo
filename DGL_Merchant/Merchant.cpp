#include<iostream>
using namespace std;

//banknote = 10,20,50,100,200,500,1000,2000,5000
int banknote[15] = {1,2,5,10,20,50,100,200,500,1000,2000,5000};

int main(){

    int n,m;
    int tmp;

    cin >> n >> m;

    tmp = n-m;

    for(int i=11;i>=0;i--){
        if(tmp >= banknote[i]){
            printf("%d = %d\n",banknote[i],tmp/banknote[i]);
            tmp%=banknote[i];
        }
        else {
            continue;
        }
    }

    return 0;
}
