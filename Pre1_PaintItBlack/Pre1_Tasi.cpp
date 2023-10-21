#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[50000]={};
    int n;
    int siz;
    scanf("%d",&siz);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int st,ed;
        scanf("%d %d",&st,&ed);
        ar[st]+=1;
        ar[ed+1]+=-1;
    }
    for(int i=1;i<=siz;i++)
    {
        ar[i]+=ar[i-1];
        cout << ar[i] << " ";
    }
}
