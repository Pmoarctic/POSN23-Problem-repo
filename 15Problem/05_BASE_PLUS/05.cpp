#include<bits/stdc++.h>

using namespace std;
int n;

long tonum(string s){
    long ans=0;
    int l = s.length();
    for(int i=0;i<l;i++){
        if(isdigit(s[i])){
            ans += (s[i]-'0') * pow(n,l-i-1);
        }
        else{
            ans+= (s[i]-'7') * pow(n,l-i-1);
        }
    }
    return ans;

}
string tos(long num){
    string ans;
    int l = ceil(log(num) / log(n));

    for(int i=0;i<l;i++){
        int tmp = num/pow(n,l-i-1);
        num -= (tmp*pow(n,l-i-1));

        if(tmp <10)
            ans+=tmp + '0';
        else
            ans+=tmp + '7';
    }
    return ans;

}

int main(){

    cin >> n;

    string a,b;
    cin >> a >> b;

    cout << tos(tonum(a)+tonum(b));

   /* long a;
    cin >> a;

    cout << tos(a);*/
}
