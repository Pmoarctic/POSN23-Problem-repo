#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;;
string in;
bool gobreak;
bool gogo;
string words[2001];
int ct;

int main()
{
    while(1)
    {
        gogo = 1;
        cin >> in;
        if(in.back()=='.')
        {
            in = in.substr(0,in.size()-1);
            gobreak = 1;
        }

        for(i=1;i<=ct;i++)
        {
            if(in==words[i])
            {
                gogo = 0;
                break;
            }
        }

        if(gogo)
        {
            words[ct++] = in;
        }

        if(gobreak) break;
    }

    cout << ct;

    return 0;
}

