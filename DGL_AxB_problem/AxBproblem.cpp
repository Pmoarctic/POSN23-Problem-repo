#include<bits/stdc++.h>
using  namespace std;

int result[1000000] ={};
char a[1000000];
char b[1000000];
char ans[1000000];

int main()
{

    
    scanf("%s %s",a,b);
   
   //////////////////
    int len1 = strlen(a);
    int len2 = strlen(b);
    int len = len1+len2;

    
    for(int i=len1-1; i>=0; i--)
    {
        for(int j=len2-1; j>=0; j--)
        {
            int mul = (a[i]-'0')*(b[j]-'0');
            int sum = mul + result[i+j+1];
            result[i+j+1] = sum%10;
            result[i+j] += sum/10;
        }
    }

    
    int idx = 0;
    int st=0;
    while(result[idx]==0 && idx < len)
    {
        idx++;
    }
    for(int i=idx; i<len;i++)
    {
        ans[st] = result[i]+'0';
        st++;
    }

    printf("%s",ans);
    //return ans;

    return 0;
}