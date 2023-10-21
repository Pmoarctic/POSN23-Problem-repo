#include<bits/stdc++.h>
#include<fstream>
#include<Windows.h>
using namespace std;

void gen(FILE *ip){  // random code
    int n = rand()%20 +1;
    fprintf(ip, "%d",n);
}

void ans(FILE *ip, FILE *op){  // solution code
    int n;
    fscanf(ip, "%d", &n);

    int ans=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            fprintf(op, "%d ", j);
        fprintf(op , "\n");

        ans += i*(n-i+1);
    }

    ans -= n-2;
    ans -= (n-1)*(n) /2;
    ans -= n*(n+1)/2;
    if(ans!=0)
        fprintf(op, "%d", ans);
    else
        fprintf(op, "No Answer");

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
