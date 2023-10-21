#include<bits/stdc++.h>
#include<fstream>
#include<Windows.h>
using namespace std;

int n,m;
char ch[1000][1000];

/*string alp = "abcdefghijklmnopqrstuvwxyz";
string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string all = alp+ALP;*/

void recur(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m)
         return;

    if(ch[i][j] == '#')
        return;

    ch[i][j] = '#';

    //cout << "HERE" << i << " " << j << endl;

    recur((i+1)%n,j);
    recur((i+n-1)%n,j);
    recur(i,(j+1)%m);
    recur(i,(j+m-1)%m);

    recur((i+1)%n,(j+1)%m);
    recur((i+1)%n,(j+m-1)%m);
    recur((i+n-1)%n,(j+1)%m);
    recur((i+n-1)%n,(j+m-1)%m);


    return;
}

void gen(FILE *ip){  // random code
    // gen input
    // fprintf(ip, "hello world");
    int a = rand()%500+1;
    int b = rand()%500+1;

    fprintf(ip,"%d %d\n",a,b);

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            int tmp = rand()%2;
            if(tmp == 0)
                fprintf(ip,"*");
            else
                fprintf(ip,"#");
        }
        fprintf(ip,"\n");
    }
}

void ans(FILE *ip, FILE *op){  // solution code
    // solution
    // fsacf(ip,"%d", %n);
    // fprinf(op, "ans");

    fscanf(ip,"%d %d",&n,&m);
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            fscanf(ip," %c",&ch[i][j]);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ch[i][j] == '*'){
                cnt++;
                recur(i,j);

                //cout << i << " " << j << endl;
            }
        }
    }

    fprintf(op,"%d",cnt);

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


       /* ip = fopen(ch_ip,"w+");
        op = fopen(ch_op,"w+");



        extra(ip,op);
        fclose(ip);
        fclose(op);*/




        cout << "Gen testcase " << i+1 << " complete\n";
    }

    cout << "\n******************** Done ********************\n";

}
