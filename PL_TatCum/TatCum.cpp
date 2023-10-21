#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    int countt=0;
    for(int i=0;i<a.length();i++)
    {
        if((a[i]!=' '&&a[i]!=',')&&(a[i+1]==' '||a[i+1]==','||a[i+1]=='\0'))
            countt++;
    }
    cout << countt;
}
