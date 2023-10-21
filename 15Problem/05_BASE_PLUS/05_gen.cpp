#include<bits/stdc++.h>
#include<fstream>
#include<Windows.h>
using namespace std;

int base;
int a,b;

long tonum(string s){
    long ans=0;
    int l = s.length();
    for(int i=0;i<l;i++){
        if(isdigit(s[i])){
            ans += (s[i]-'0') * pow(base,l-i-1);
        }
        else{
            ans+= (s[i]-'7') * pow(base,l-i-1);
        }
    }
    return ans;

}

string tos(long num){
    string ans;
    int l = ceil(log(num) / log(base));

    for(int i=0;i<l;i++){
        int tmp = num/pow(base,l-i-1);
        num -= (tmp*pow(base,l-i-1));

        if(tmp <10)
            ans+=tmp + '0';
        else
            ans+=tmp + '7';
    }
    return ans;

}

void gen(FILE *ip){  // random code
    // gen input
    // fprintf(ip, "hello world");

    base = rand()%15+2;
    fprintf(ip,"%d\n",base);

    a = rand()%10000;
    b = rand()%10000;

    string aa = tos(a);
    string bb = tos(b);

    for(int i=0;i<aa.length();i++){
        char ch = aa[i];
        fprintf(ip,"%c",ch);
    }
    fprintf(ip,"\n");
    for(int i=0;i<bb.length();i++){
        char ch = bb[i];
        fprintf(ip,"%c",ch);
    }
    fprintf(ip,"\n");
}

void ans(FILE *ip, FILE *op){  // solution code
    // solution
    // fsacf(ip,"%d", %n);
    // fprinf(op, "ans");

    string ans = tos(a+b);
    for(int i=0;i<ans.length();i++){
        char ch = ans[i];
        fprintf(op,"%c",ch);
    }

}



int main(){
    FILE *ip;
    FILE *op;

    string ip_s = "E:\\coding\\posn66\\";    //copy path of your folder
    string op_s = "E:\\coding\\posn66\\";    //copy path of your folder

    string tmp;
    cin >> tmp;

    ip_s += tmp;
    op_s += tmp;

    ip_s += "\\input";
    op_s += "\\output";

    char* ip_path = new char[ip_s.length()+1];
    strcpy(ip_path, ip_s.c_str());
    char* op_path = new char[op_s.length()+1];
    strcpy(op_path, op_s.c_str());

    CreateDirectory(op_path,NULL);
    CreateDirectory(ip_path,NULL);


    for(int i=0;i<10;i++)
    {

        string f_op = "output0";
        f_op += i+'0';
        f_op += ".txt";

        string f_ip = "input0";
        f_ip += i+'0';
        f_ip += ".txt";

        //cout << f_op << " " << f_ip << endl;

        char* ch_op = new char[f_op.length()+1];
        strcpy(ch_op, f_op.c_str());

        char* ch_ip = new char[f_ip.length()+1];
        strcpy(ch_ip, f_ip.c_str());

        filesystem::current_path(ip_path);
        ip = fopen(ch_ip, "w");
        gen(ip);
        fclose(ip);

        ip = fopen(ch_ip,"r");

        filesystem::current_path(op_path);
        op = fopen(ch_op,"w");



        ans(ip,op);
        fclose(ip);
        fclose(op);
    }

}
