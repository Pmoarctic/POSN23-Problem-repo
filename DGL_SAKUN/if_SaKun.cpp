#include<bits/stdc++.h>
using namespace std;
int main(){
	char L;// U,Y,W
	int s;// 0,1
	float t;
	scanf("%c %d %f",&L,&s,&t);
	printf("%.0f TH BATH = ",t);
	if(L=='U'){
		if(s==1){
			printf("%.3f USD",37*t);
		}
		else printf("%.0f USD",37*t);
	}
	else if(L=='Y'){
		if(s==1){
			printf("%.3f YEN",0.25*t);
		}
		else printf("%.0f YEN",0.25*t);
	}
	else if(L=='W'){
		if(s==1){
			printf("%.3f WON",0.027*t);
		}
		else printf("%.0f WON",0.027*t);
	}
}
