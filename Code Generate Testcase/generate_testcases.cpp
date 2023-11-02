#include <bits/stdc++.h>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
namespace fs = std::filesystem;
using namespace std;

long long MAX = INT_MAX;

string ran_Mix(int length,string RANDOM_STRING) {
    string result={""};

    //const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int i = 0; i < length; ++i) {
        // Generate a random index within the range of characters
        /*
        int index = rand() % (sizeof(characters) - 1);
        result += characters[index];
        */
        int index = rand() % RANDOM_STRING.length();
        result += RANDOM_STRING[index];
        // Append the character at the generated index to the result
    }
    return result;
}

//input Folder name (Editable)
string folderName = "zAplusB_problem";

//global input (Editable)    ( must Edit in fn(Write_and_randomGlobalVar)   )
int a,b;

///////////////

//OUTPUT


//(Editable)
//template "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
//   fprintf(fp,"%s",str.c_str());  (string)
void Write_and_randomGlobalVar(FILE *fp)
{ 
    
    a = rand()%1000000000;
    b = rand()%1000000000;
    fprintf(fp,"%d %d\n",a,b);

    //random string case

}
///////////////////////////////////

///main function process (Editable) **using 'fprintf(fp,"{-},{-}");'  instead of  'printf();'

//   fprintf(fp,"%s",str.c_str());  (string)

void Process(FILE *fp)
{
    int c = a+b;

    fprintf(fp,"%d",c);
    
}

////////////////////////



string create_in(string nm,int idx)
{
    nm += ".";
    nm += idx+'0';
    //nm += "in";
    
    ofstream outfile (nm);

    return nm;
}
string create_out(string nm,int idx)
{
    nm += ".";
    nm += idx+'0';
    //nm += "out";
    ofstream outfile (nm);

    return nm;
}



int main(){
    FILE *fp;
    srand(time(NULL));
    string TmpFolderName = "D:/GenTestCase/";
    TmpFolderName += folderName;
    const char * cfffffffff = TmpFolderName.c_str();
    CreateDirectory(cfffffffff,NULL);
    /////////////////////////////////////
    filesystem::path newDir = cfffffffff;
    filesystem::current_path(newDir);

    for(int i=0;i<10;i++)
    {
        // Generate input testcase
        string current_file = create_in("input", i);
        const char * current_filee = current_file.c_str();
        fp = fopen(current_filee,"w");
        Write_and_randomGlobalVar(fp);
        fclose(fp);

        // Generate output testcase
        string currentt_file = create_out("output", i);
        const char * ccurrent_file = currentt_file.c_str();
        fp = fopen(ccurrent_file,"w");
        Process(fp);
        fclose(fp);
    }

}

/*
    template
    int O = rand()%1000;
    int X = rand()%100;
    int n = rand()%10;
    fprintf(fp,"%d %d\n%d\n",O,X,n);

*/