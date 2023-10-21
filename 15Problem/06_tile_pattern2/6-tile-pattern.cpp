#include<iostream>
using namespace std ;

int main()
{
    char asc = 65 ;
    int n,l,w ;

    cin >> n ;
    cin >> l ;
    cin >> w ;

    for(int i=0;i<w;i++)
    {    
        for(int j=0;j<l;j++)
        {
            printf("%c",asc+(i+j)%n) ;
        }
        cout << "\n" ;

    }

    return 0 ;
}