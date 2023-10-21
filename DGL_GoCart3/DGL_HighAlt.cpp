#include<bits/stdc++.h>

int arr[2000000] = {};

int main()
{   
    int n;
    int mx = INT_MIN;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        arr[i] += (tmp + arr[i-1]);
        if(arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    printf("%d",mx);

}
