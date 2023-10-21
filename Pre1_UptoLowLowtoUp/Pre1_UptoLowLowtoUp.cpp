#include<bits/stdc++.h>
using namespace std;
int main(){
	string n;
	cin >> n;
	for(int i=0;i<n.length();i++){
		if(n[i]<'a') {
			n[i] =tolower(n[i]);
			cout << n[i];
		}
		else {
		n[i] = toupper(n[i]);
		cout << n[i];
	}
		
		}
}
