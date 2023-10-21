#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int l = s.length();

    int n,m;
    cin >> n >> m;
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << s[cnt];
            cnt++;
            cnt%=l;
        }
        if(cnt==0)
            cnt = l;
        else
            cnt--;

        cout << endl;
    }
}
