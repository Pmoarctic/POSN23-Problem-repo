#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            if((c==(n+1)/2||c==((n+1)/2)+(n%2==0))&&(r==(n+1)/2||r==((n+1)/2)+(n%2==0))){
                cout << 8;
            }else if(c==r||c==n-r+1){
                cout << 1;
            }else cout << 0;
        }
        cout << endl;
    }
}
