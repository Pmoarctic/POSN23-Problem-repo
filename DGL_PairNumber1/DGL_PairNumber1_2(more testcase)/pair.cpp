#include<bits/stdc++.h>
using namespace std;


int bo[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n ;
    int st = INT_MAX;
    int ed = -1;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        bo[tmp]++;
        st = min(st,tmp);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int sum;
        cin >> sum;
        int check = 0;
        for(int i=st;i<=sum;i++)
        {
            
            int now = sum - i;
            if(sum<=i)
            {
                break;
            }
            if(now == i && bo[i] < 2)
            {
                continue;
            }
            if(bo[now] >= 1 && bo[i] >= 1)
            {
                cout << "YES\n";
                check = 1;
                break;
            }
            
            
        }
        if(check == 0)
        {
            cout << "NO\n";
        }
    }
    return 0;
}