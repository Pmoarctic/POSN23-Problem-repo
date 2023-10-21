#include<stdio.h>
#define ull unsigned long long

int main()
{
    ull sum = 0;
    ull tmp;
    ull n;
    scanf("%llu",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%llu",&tmp);
        sum += tmp;
        printf("%llu ",sum);
    }
    return 0;
}