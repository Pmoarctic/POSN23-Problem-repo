#include<stdio.h>

int arr[2000000] = {};

int main()
{   
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        arr[i] += (tmp + arr[i-1]);
    }

    int q;
    scanf("%d",&q);

    while(q--)
    {
        int x;
        int y;
        scanf("%d %d",&x,&y);

        printf("%d\n",arr[y] - arr[x-1]);
    }
    return 0;
}
