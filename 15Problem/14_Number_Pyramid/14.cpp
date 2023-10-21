#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n;

    int ans=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout << j << " ";
        cout << endl;

        ans += i*(n-i+1);
    }

    ans -= n-2;
    ans -= (n-1)*(n) /2;
    ans -= n*(n+1)/2;

    if(ans == 0)
    {
        cout << "No Answer";
        return 0;
    }
    cout << ans;


}
