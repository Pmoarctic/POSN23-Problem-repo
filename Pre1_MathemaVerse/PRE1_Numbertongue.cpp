#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int, string>> nums ={{1000000000, "Billion"}, {1000000, "Million"}, 
    {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
    {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, 
    {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, 
    {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, 
    {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

string totext(ll number)
{
    switch (number)
    {
    case 9:return "Nine";
    case 8:return "Eight";
    case 7:return "Seven";
    case 6:return "Six";
    case 5:return "Five";
    case 4:return "Four";
    case 3:return "Three";
    case 2:return "Two";
    case 1:return "One";
    case 0:return "Zero";
    }
    return "";
}
string numberToWords(ll num)
{
    if(num == 0)   return "Zero";
        
    for(auto it: nums)
        if(num >= it.first)
        {
            return (num >= 100 ? numberToWords(num/it.first)+" " : "") + it.second + (num%it.first == 0 ? "" : " "+numberToWords(num%it.first));
        }
    return "";
}


int main()
{
    double n;
    cin >> n;
    ll k = n;
    cout << numberToWords(k);
    
    double d = n-k;

    if(d>0)
    {
        cout << " Point ";
        int de=5;
        while(de--)
        {
            d*=10;
            ll digit = d;
            cout << totext(digit) << " ";
            d -= digit;
        }
    }

}