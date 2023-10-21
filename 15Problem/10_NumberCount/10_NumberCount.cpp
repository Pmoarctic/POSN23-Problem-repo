#include<iostream>
using namespace std;

int arr[12];
bool chk[12];
bool zero;
int n;
int main(){

    
    cin >> n;
    int tmp=0;
    if(n%10==0) zero=true;
    for(int i=0;n>0;i++){
        arr[n%10]++;
        //cout << n%10;
        tmp*=10;
        tmp+=n%10;
        n=n/10;
    }
    //cout << tmp << endl;
    
    for(int i=0;tmp>0;i++){
        if(arr[tmp%10]!=0 && !chk[tmp%10]){
            cout << "'" << tmp%10 << "'" << "=" <<arr[tmp%10] << endl;
            chk[tmp%10] = true;
        }
        tmp/=10;
    }
    if(zero&&!chk[0]) cout << "'" << 0 << "'" << "=" << arr[0] << endl ;
    //if()

    return 0;
}
