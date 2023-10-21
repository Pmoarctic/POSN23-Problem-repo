#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin >> a;
	int l,h,r,lmin=999,rmax=-999;
	int hchange[999]={0};
	for(int i=0;i<a;i++)
	{
		cin >> l >> h >> r;
		for(int i=l;i<r;i++)
		{
			hchange[i] = max(hchange[i],h);
		}
		lmin = min(l,lmin);
		rmax = max(r,rmax);
	}
	int last = -1;
	for(int i=lmin;i<=rmax;i++)
	{
		if(hchange[i]!=last)
		{
			cout << i << " " << hchange[i] << " ";
			last = hchange[i];
		}
	}
}
