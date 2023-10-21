#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    float x[n],y[n],maxdis=0;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
        if(sqrt(pow(x[0]-x[i],2)+pow(y[0]-y[i],2))>maxdis){
            maxdis = sqrt(pow(x[0]-x[i],2)+pow(y[0]-y[i],2));
        }
    }
    printf("%.2f",maxdis);
}
