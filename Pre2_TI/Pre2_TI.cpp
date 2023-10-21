#include<bits/stdc++.h>
using namespace std;
char ar[5000]={};
int n,ww,ll;
void recur(int w,int l,char wl,int index)
{
    if(index!=-1)
        ar[index]=wl;
    if(w==n||l==n)
    {
        for(int k=0;k<=index;k++)
        {
            cout << ar[k] << " ";
        }
        cout << "\n";
        return;
    }
    recur(w+1,l,'W',index+1);
    recur(w,l+1,'L',index+1);
}
int main()
{
    cin >> n >> ww >> ll;
    recur(ww,ll,' ',-1);
}
