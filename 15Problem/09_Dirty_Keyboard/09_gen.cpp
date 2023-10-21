#include<bits/stdc++.h>
#include<fstream>
#include<Windows.h>
using namespace std;

 string s;
 string ch = "abcdefghijklmnopqrstuvwxyz";

void gen(FILE *ip){  // random code
    // gen input
    // fprintf(ip, "hello world");
    s.clear();
    int l = rand() % 20+1;
    for(int i=0;i<l;i++){
        int num=rand()%26;
        int ble = rand()%5+1;
        for(int j=0;j<ble;j++){
            s+=ch[num];
            fprintf(ip,"%c",ch[num]);
        }

    }

}

void ans(FILE *ip, FILE *op){  // solution code
    // solution
    // fsacf(ip,"%d", %n);
    // fprinf(op, "ans");


    for(int i=0;i<s.length()-1;i++){
        if(s[i] != s[i+1])
            fprintf(op,"%c",s[i]);
    }
   fprintf(op,"%c", s[s.length()-1]);

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

    ip_s += "\\testcase";
    //op_s += "\\output";

    char* ip_path = new char[ip_s.length()+1];
    strcpy(ip_path, ip_s.c_str());
    char* op_path = new char[op_s.length()+1];
    strcpy(op_path, op_s.c_str());

   // CreateDirectory(op_path,NULL);
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

        //filesystem::current_path(op_path);
        op = fopen(ch_op,"w");



        ans(ip,op);
        fclose(ip);
        fclose(op);
    }

}
