#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull line[100][100];
int mid[100];

int digit(ull num)
{
    int cnt=0;
    while(num>0)
    {
        num/=10;
        cnt++;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;

    //cout << digit(n) << endl;

    line[1][1] = 1;
    //line[2][1] = 1;
    //line[2][2] = 1;
    mid[1] = 1;
    int lim=0;
    for(int i=2;i<=n;i++)
    {
        line[i][i] = 1;
        line[i][1] = 1;
        mid[i] = i+1;
        for(int j=2;j<i;j++)
        {
            line[i][j] = line[i-1][j-1] + line[i-1][j];
            mid[i] += digit(line[i][j]);
        }
       /* if(i==n)
        {
            lim = mid[i];
        }*/
        //mid[i] = (mid[i]+1)/2 +1;
    }


    for(int i=1;i<=n;i++)
    {
        int cnt=0;

       // cout << mid[i];
        for(int k=0;k<(mid[n]-mid[i])/2;k++)
        {
            cnt++;
            cout << "_";
        }
        for(int j=1;j<i;j++)
        {
            cnt++;
            cnt += digit(line[i][j]);
            cout << line[i][j] << "_";
        }
        cnt++;
        cout << line[i][i];

        while(cnt < mid[n])
        {
            cout << "_";
            cnt++;
        }

        cout << "\n";
    }


}
