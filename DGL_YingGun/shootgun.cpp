#include<bits/stdc++.h>
using namespace std;
char a[200][200]={};
int yy,xx;
int countt=0;
void recur(int y,int x)
{
    if(y<0||x<0||y>=yy||x>=xx)
        return;
    if(a[y][x]=='-')
        return;
    if(a[y][x]=='*')
        countt++;
    a[y][x]='-';
    recur(y+1,x);
    recur(y-1,x);
    recur(y,x+1);
    recur(y,x-1);
    recur(y+1,x+1);
    recur(y+1,x-1);
    recur(y-1,x+1);
    recur(y-1,x-1);
    return;
}
int main()
{
    cin >> yy >> xx;
    for(int i=0;i<yy;i++)
    {
        for(int k=0;k<xx;k++)
        {
            cin >> a[i][k];
        }
    }
    int yst,xst;
    cin >> xst >> yst;
    yst--;
    xst--;
    recur(yst,xst);
    cout << countt;
}
