#include<bits/stdc++.h>
using namespace std;

int arr[10010][10010];

int main()
{
    int r,c,n;
    cin >> r >> c;

    int st = 1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            arr[i][j] = st++;
        }
    }

    int x1=0,y1=0,x2=c-1,y2=r-1;

    cin >> n;
    while(n--)
    {
        char tmp;
        cin >> tmp;
        if(tmp == 'U')
        {
            y1++;
            y2++;
        }
        else if(tmp == 'D')
        {
            y1--;
            y2--;
        }
        else if(tmp == 'R')
        {
            x1--;
            x2--;
        }
        else if(tmp == 'L')
        {
            x1++;
            x2++;
        }
/////////////////////////////////
        if(x1 == -1)
        {
            x1 = c-1;
        }
        else if(x2 == -1)
        {
            x2 = c-1;
        }
        else if(y1 == -1)
        {
            y1 = r-1;
        }
        else if(y2 == -1)
        {
            y2 = r-1;
        }
        else if(y1 == r)
        {
            y1 = 0;
        }
        else if(y2 == r)
        {
            y2 = 0;
        }
        else if(x1 == c)
        {
            x1 = 0;
        }
        else if(x2 == c)
        {
            x2 = 0;
        }
        
    }

    cout << arr[y1][x1] << " " << arr[y2][x2] << endl;
    

}
