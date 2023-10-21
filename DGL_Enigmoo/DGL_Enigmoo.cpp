#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[10000]={};
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> ar[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int k=i+1;k<n;k++)
        {
            if(ar[k]<=ar[i])
            {
                ar[i]-=ar[k];
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << ar[i] << " ";
    }
}
