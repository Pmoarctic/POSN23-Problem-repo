#include<bits/stdc++.h>
using namespace std ;

int n,m,temp,don,mx,in,out,sum[2222][2222] ;

int main()
{
    scanf("%d %d",&n,&m) ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&temp) ;
            sum[i][j] = temp + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] ;
        }
    }

    for(int i=m;i<=n;i++)
    {
        for(int j=m;j<=n;j++)
        {
            out = sum[i][j] - sum[i-m][j] - sum[i][j-m] + sum[i-m][j-m] ;
            in  = sum[i-1][j-1] - sum[i-1-(m-2)][j-1] - sum[i-1][j-1-(m-2)] + sum[i-1-(m-2)][j-1-(m-2)] ;
            don = out - in ;

            mx = ((mx>=don)*mx) + ((mx<don)*don) ;
            //printf("%d %d %d\n",in,out,mx) ;
        }
    }

    printf("%d",mx) ;

    return 0 ;
}
