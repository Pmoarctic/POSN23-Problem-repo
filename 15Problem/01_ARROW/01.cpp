#include<bits/stdc++.h>

using namespace std;

int main(){
    int type,n;
    cin >> type >> n;

    if(type == 1){
        for(int i=0;i<n;i++){
            for(int j=1;j<n-i;j++)
                cout << " ";
            cout << "/" << endl;
        }
        for(int i=n;i>0;i--){
            for(int j=i;j<n;j++)
                cout << " ";
            cout << "\\" << endl;
        }
    }
    else{
        for(int i=n;i>0;i--){
            for(int j=i;j<n;j++)
                cout << " ";
            cout << "\\" << endl;
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n-i;j++)
                cout << " ";
            cout << "/" << endl;
        }

    }
}
