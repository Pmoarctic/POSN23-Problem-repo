/*
LANG: C++
COMPILER: WCB
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n,tmp;
    cin>>n;
    tmp = (n+1)/2;
    char arr[tmp][tmp];
    for(int i=0;i<tmp;i++){
        for(int j=0;j<tmp;j++){
            cin>>arr[i][j];
        }
    }
    if(n%2!=0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j<tmp&&i<tmp)cout<<arr[i][j]<<" ";
                else if(j<tmp&&i>=tmp)cout<<arr[2*tmp-i-2][j]<<" ";
                else if(j>=tmp&&i<tmp)cout<<arr[i][2*tmp-j-2]<<" ";
                else cout<<arr[2*tmp-i-2][2*tmp-j-2]<<" ";
            }
            cout<<"\n";
        }
    }
    else{
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j<tmp&&i<tmp)cout<<arr[i][j]<<" ";
                else if(j<tmp&&i>=tmp)cout<<arr[2*tmp-i-1][j]<<" ";
                else if(j>=tmp&&i<tmp)cout<<arr[i][2*tmp-j-1]<<" ";
                else cout<<arr[2*tmp-i-1][2*tmp-j-1]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
