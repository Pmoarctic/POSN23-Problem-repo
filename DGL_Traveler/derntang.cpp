#include<iostream>
using namespace std;

int main(){

    int n,k,cnt=0,a,l=0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        cnt+=a;
        if(cnt>=k){
            cnt = 0;
            l++;
        }
    }
    cout << l;

    return 0;
}
