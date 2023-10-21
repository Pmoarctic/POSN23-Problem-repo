#include<bits/stdc++.h>
#include<fstream>
#include<Windows.h>
using namespace std;

void gen(FILE *ip){  // random code
    // gen input
    // fprintf(ip, "hello world");

     int pos = rand()%10+1;

     int ra,rb,ca,cb;
     ra = rand()%19+2;
     rb = rand()%19+2;
     if(pos <= 6)
        ca = rb;
    else
        ca = rand()%19+2;
    cb = rand()%19+2;

    fprintf(ip,"%d %d %d %d\n",ra,ca,rb,cb);

    for(int i=0;i<ra;i++){
        for(int j=0;j<ca;j++){
            int tmp = rand()%10;
            int neg = rand()%2+1;

            tmp *= pow(-1,neg);
            fprintf(ip,"%d ",tmp);
        }
        fprintf(ip,"\n");
    }
     for(int i=0;i<rb;i++){
        for(int j=0;j<cb;j++){
            int tmp = rand()%10;
            int neg = rand()%2+1;

            tmp *= pow(-1,neg);
            fprintf(ip,"%d ",tmp);
        }
        fprintf(ip,"\n");
    }

}

void ans(FILE *ip, FILE *op){  // solution code
    // solution
    // fsacf(ip,"%d", %n);
    // fprinf(op, "ans");

    int rA,rB,cA,cB;
    fscanf(ip,"%d %d %d %d",&rA,&cA,&rB,&cB);
    int mA[rA][cA],mB[rB][cB],mC[rA][cB];
    memset(mC,0,sizeof(mC));
    for(int r=0;r<rA;r++){
        for(int c=0;c<cA;c++){
            fscanf(ip,"%d",&mA[r][c]);
        }
    }
    for(int r=0;r<rB;r++){
        for(int c=0;c<cB;c++){
            fscanf(ip,"%d",&mB[r][c]);
        }
    }
    if(cA != rB)fprintf(op,"Not Multiply");
    else{
        for(int i=0;i<rA;i++){
            for(int j=0;j<cB;j++){
                for(int k=0;k<cA;k++){
                    mC[i][j]+=mA[i][k]*mB[k][j];
                }
            }
        }
        for(int r=0;r<rA;r++){
        for(int c=0;c<cB;c++){
            fprintf(op,"%d ",mC[r][c]);
        }
        fprintf(op,"\n");
    }
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

        string f_op = "output.";
        f_op += i+'0';
        //f_op += ".txt";

        string f_ip = "input.";
        f_ip += i+'0';
        //f_ip += ".txt";

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
