#include<bits/stdc++.h>
#include<fstream>
#include<Windows.h>
using namespace std;

void gen(FILE *ip){  // random code
    // gen input
    // fprintf(ip, "hello world");

    int n = rand() % 18 +2;
    int x = rand() % (n-2) +2;
    fprintf(ip,"%d\n%d",n,x);

}

void ans(FILE *ip, FILE *op){  // solution code
    // solution
    // fsacf(ip,"%d", %n);
    // fprinf(op, "ans");

    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int n,x;
    fscanf(ip,"%d %d", &n, &x);

    char ch[n][n];

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(j>=n-i-1){
                ch[i][j] = s[cnt];
                cnt++;
                cnt%=26;
            }
            else
                ch[i][j] = ' ';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fprintf(op,"%c ",ch[i][j]);
        }
        fprintf(op,"\n");
    }

    for(int i=n-x;i<n;i++){
        fprintf(op,"%c " ,ch[i][x-1]);
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
