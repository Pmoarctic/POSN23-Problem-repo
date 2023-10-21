#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[26]={};
    string in;
    cin >> in;
    int ch=in[0],check=0;
    string temp="";
    for(int i=1;i<in.length();i++)
    {
        if(isdigit(in[i]))
        {
            temp+=in[i];
        }
        if(i==in.length()-1||isalpha(in[i+1]))
        {
            stringstream ss;
            int num;
            ss << temp;
            ss >> num;
            ar[ch-'A']+=num;
            temp="";
        }
        if(isalpha(in[i]))
        {
            ch=in[i];
        }
    }
    for(int i=0;i<26;i++)
    {
        if(ar[i]!=0)
            printf("%c = %d\n",i+'A',ar[i]);
    }
}
