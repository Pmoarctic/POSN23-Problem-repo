#include<bits/stdc++.h>

using namespace std;

int main(){
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int n,x;
    cin >> n >> x;

    char ch[n][n];

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(j>=n-i-1){
                ch[i][j] = s[cnt];
                cnt++;
                cnt%=26;
            }
            else
                ch[i][j] = ' ';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ch[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=n-x;i<n;i++){
        cout << ch[i][x-1] << " ";
    }
}
