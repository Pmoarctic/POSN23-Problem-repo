#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int n;
    scanf(" %d",&n);

    while(n--){
        char ch;
        scanf(" %c",&ch);
        bool found = false;
        for(int i=0;i<s.length();i++){
            if(tolower(s[i]) == tolower(ch)){
                printf("%d ",i+1);
                found = true;
            }

        }
        if(!found)
            printf("Not Found");
        printf("\n");
    }
}
