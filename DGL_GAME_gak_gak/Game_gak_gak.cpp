#include <bits/stdc++.h>

using namespace std;

int main() {
    string line1,line2;
    int cc=0,col=-1,row=-1;
    cin >> line1 >> line2;
    for(int i = 0;i<line1.length();i++){
        for(int j=0;j<line2.length();j++){
            if(line1[i]==line2[j]){
                col = i;
                row = j;
                cc=1;
                break;
            }
        }
        if(cc==1)break;
    }
    if(cc==0){
        for(int r=0;r<line2.length();r++){
            for(int c=0;c<line1.length();c++){
                if(r==0){
                    cout<<line1[c]<<" ";
                }else cout << "  ";
            }
            cout << line2[r] << endl;
        }
    }else if(cc=1){
        for(int r=0;r<line2.length();r++){
            for(int c=0;c<line1.length();c++){
                if(r==row){
                    cout << line1[c] << " ";
                }else if(c==col&&r!=row){
                    cout << line2[r] << " ";
                }else{
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
}
