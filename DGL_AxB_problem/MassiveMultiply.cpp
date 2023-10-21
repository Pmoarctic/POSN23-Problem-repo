#include <bits/stdc++.h>
using namespace std;

int result[1000000] = {};
string multiplyStrings(string num1, string num2) 
{
    int len1 = num1.length();
    int len2 = num2.length();
    int len = len1 + len2;

    

    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string resultStr = "";
    int i = 0;
    while (i < len && result[i] == 0)
    {
        i++;
    }
    while (i < len) 
    {
        resultStr += result[i] + '0';
        i++;
    }

    return resultStr=="" ? "0" : resultStr;
    
}
/*
char* Multiply(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1+len2;

    //int result[len] ={};
    for(int i=len1-1; i>=0; i--)
    {
        for(int j=len2-1; j>=0; j--)
        {
            int mul = (num1[i]-'0')*(num2[j]-'0');
            int sum = mul + result[i+j+1];
            result[i+j+1] = sum%10;
            result[i+j] += sum/10;
        }
    }

    char *ans = new char[len+10];
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

    return ans;
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
   //char a[1000000];
   //char b[1000000];
   string a,b;
   //scanf("%s %s",&a,&b);
   cin >> a >> b;
   //char* c = Multiply(a,b);
   string c = multiplyStrings(a,b);
    cout << c;
   //printf("%s",c);
   /*
   for(int i=0; i<strlen(c); i++)
   {
    cout << c[i];
   }
   */

    return 0;
}
