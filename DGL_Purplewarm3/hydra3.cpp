#include<bits/stdc++.h>

using namespace std;


int n,m;
char ch[1000][1000];

void recur(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m)
        return;

    if(ch[i][j] == '#')
        return;

    ch[i][j] = '#';

    //cout << "HERE" << i << " " << j << endl;

    recur((i+1)%n,j);
    recur((i+n-1)%n,j);
    recur(i,(j+1)%m);
    recur(i,(j+m-1)%m);

    recur((i+1)%n,(j+1)%m);
    recur((i+1)%n,(j+m-1)%m);
    recur((i+n-1)%n,(j+1)%m);
    recur((i+n-1)%n,(j+m-1)%m);

    return;
}

int main(){
    scanf("%d %d",&n,&m);
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf(" %c",&ch[i][j]);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ch[i][j] == '*'){
                cnt++;
                recur(i,j);

                //cout << i << " " << j << endl;
            }
        }
    }

    printf("%d",cnt);
}

/*
5 5
***##
*#*#*
###*#
**##*
*****
*/
