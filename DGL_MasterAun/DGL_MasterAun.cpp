#include<bits/stdc++.h>
using namespace std;
bool prime[1050000]={false};
int main()
{
    prime[1]=true;
    for(int i=2;i<=1050000;i++)
    {
        if(!prime[i])
        {
            for(int k=i+i;k<=1050000;k+=i)
                prime[k]=true;
        }
    }
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("if(n==%d)\n\tcout << ",i);
        if(!prime[i])
            printf("%cY%c;\n",34,34);
        else
            printf("%cN%c;\n",34,34);
    }
}
