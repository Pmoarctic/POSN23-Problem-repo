#include<bits/stdc++.h>
using namespace std;
int main()
{
    string f2,f3,e2,e3;
    cin >> f2 >> f3 >> e2 >> e3;
    int a;
    cin >> a;
    int sum=0;
    for(int i=0;i<a;i++)
    {
        string temp;
        cin >> temp;
        if(temp[0]==f2[0]&&temp[1]==f2[1])
            sum+=500;
        if(temp[0]==f3[0]&&temp[1]==f3[1]&&temp[2]==f3[2])
            sum+=1000;
        if(temp[4]==e2[0]&&temp[5]==e2[1])
            sum+=500;
        if(temp[3]==e3[0]&&temp[4]==e3[1]&&temp[5]==e3[2])
            sum+=1000;
    }
    cout << a*100-sum;
}
