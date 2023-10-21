#include<bits/stdc++.h>
#include<fstream>
#include<Windows.h>
using namespace std;

/*string alp = "abcdefghijklmnopqrstuvwxyz";
string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string all = alp+ALP;*/

void gen(FILE *ip){  // random code
    // gen input
    // fprintf(ip, "hello world");
    int n = rand()%100+1;
    int hp = rand()%100+1;

    fprintf(ip,"%d %d\n",n,hp);
    for(int i=0;i<2*n;i++){
        for(int j=0;j<5;j++){
            int tmp = rand()%51;
            fprintf(ip,"%d ",tmp);
        }
        fprintf(ip,"\n");
    }
}

void ans(FILE *ip, FILE *op){  // solution code
    // solution
    // fsacf(ip,"%d", %n);
    // fprinf(op, "ans");

    int n;
    //rounds
    fscanf(ip,"%d",&n);
    int a[n][5],b[n][5],wc_a,wc_b,hp_a,hp_b,hp,r_end;
    //healths
    fscanf(ip,"%d",&hp);
    hp_a = hp;
    hp_b = hp;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            //power
            fscanf(ip,"%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            //power
            fscanf(ip,"%d",&b[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        wc_a = 0;
        wc_b = 0;
        for(int j=0;j<5;j++){
            if(a[i][j]>b[i][j]){
                wc_a++;
            }else if(a[i][j]<b[i][j]){
                wc_b++;
            }
        }
        if(wc_b>wc_a){
            hp_a -=3;
        }else{
            hp_b -=3;
        }
        if(i==n-1&&(hp_a>0&&hp_b>0)){
            fprintf(op,"%d\nDRAW",i+1);
        }
        if(hp_a<=0){
            fprintf(op,"%d\nJOB WIN",i+1);
            break;
        }else if(hp_b<=0){
            fprintf(op,"%d\nGAO WIN",i+1);
            break;
        }
    }

}

void extra(FILE *ip,FILE *op){  // write and solve in one function;
    // no fscanf()
}


int main(){
    FILE *ip;
    FILE *op;

    string ip_s = "E:\\coding\\posn66\\";    //copy path of your folder
    string op_s = "E:\\coding\\posn66\\";    //copy path of your folder

    string tmp;
    cout << "Enter Name : ";
    cin >> tmp;

    int type;
    cout << "Enter Type (1 for NU 2 for CHS) : ";
    cin >> type;

    ip_s += tmp;
    op_s += tmp;

    if(type == 1)
        ip_s += "\\testcase_NU";
    else
        ip_s += "\\testcase_CHS";


    char* ip_path = new char[ip_s.length()+1];
    strcpy(ip_path, ip_s.c_str());
    char* op_path = new char[op_s.length()+1];
    strcpy(op_path, op_s.c_str());

   // CreateDirectory(op_path,NULL);
    CreateDirectory(ip_path,NULL);

    cout << "\n";
    for(int i=0;i<10;i++)
    {
        string f_ip;
        string f_op;

        if(type == 1){
            f_ip += "input.";
            f_ip += i+'0';

            f_op += "output.";
            f_op += i+'0';
        }
        else{
            if(i<9){
                f_ip += i+'1';
                f_op += i+'1';
            }
            else{
                f_ip += "10";
                f_op += "10";
            }
            f_ip += ".in";
            f_op += ".sol";
        }

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


       /* ip = fopen(ch_ip,"w");
        //filesystem::current_path(op_path);
        op = fopen(ch_op,"w");



        extra(ip,op);
        fclose(ip);
        fclose(op);*/




        cout << "Gen testcase " << i+1 << " complete\n";
    }

    cout << "\n******************** Done ********************\n";

}
