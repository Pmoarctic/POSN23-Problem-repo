#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std ;

int main()
{
    int n ;
    char str[100];

    scanf("%d",&n) ;
    scanf(" %[^\n]s",str);

    for(int i=0;i<strlen(str);i++)
    {
        
        if(str[i]>='A' && str[i] <='Z')
        {
            if(str[i]-n < 'A')
            {
                str[i] += 26;
            }
            str[i] -= n ;
        }
        if(str[i]>='a' && str[i] <='z')
        {
            if(str[i]-n < 'a')
            {
                str[i] += 26;
                
            }
            str[i] -= n ;
        }
        
        
    }

    printf("%s",str) ;

    return 0 ;
}