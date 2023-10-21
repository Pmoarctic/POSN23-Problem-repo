#include<stdio.h>
#include<algorithm>

int main ()
{
    int n ;
    scanf("%d",&n) ;

    for(int i=n-1 ; i>-n ; i--)
    {
        for(int j=-n+1 ; j<n ; j++)
        {
            if(i==j || i==-j)
            {
                printf("%c",'A' + (abs(i)%26)) ;
            }
            else printf(" ") ;
        }
        printf("\n") ;
    }

    return 0 ;
}