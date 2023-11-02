#include <bits/stdc++.h>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
namespace fs = std::filesystem;
using namespace std;

long long MAX = INT_MAX;


//input Folder name (Editable)
string folderName = "ABC_pyramid";

//global input (Editable)    ( must Edit in fn(Write_and_randomGlobalVar)   )
int n;

//OUTPUT

//(Editable)
void Write_and_randomGlobalVar(FILE *fp)
{ 
    
    n = rand()%10000;
    fprintf(fp,"%d",n);
}
///////////////////////////////////

///main function process (Editable) **using 'fprintf(fp,"{-},{-}");'  instead of  'printf();'
void Process(FILE *fp)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int long_line = 1;
    int start = 0;

    for(int i=0;i<n;i++)
    {
        if(start == long_line)
        {
            long_line++;
            start = 0;
            fprintf(fp, "\n");
        }
        start++;
        fprintf(fp,"%c",alphabet[i%26]);
    }
    return;
}

////////////////////////



string create_txt(string nm,int idx)
{
    nm += idx+'0';
    nm += ".txt";
    ofstream outfile (nm);

    return nm;
}

int main(){
    FILE *fp;
    srand(time(NULL));
    string TmpFolderName = "D:/POSN66/";
    TmpFolderName += folderName;

    const char * cfffffffff = TmpFolderName.c_str();
    CreateDirectory(cfffffffff,NULL);

    string FolderOut = TmpFolderName + "/output";
    string FolderIn = TmpFolderName + "/input";
    const char * innnnnnnnn = FolderIn.c_str();
    const char * ouuuuuuuuu = FolderOut.c_str();
    CreateDirectory(innnnnnnnn,NULL);
    CreateDirectory(ouuuuuuuuu,NULL);

    /////////////////////////////////////

    filesystem::path newDir = cfffffffff;
    filesystem::current_path(newDir);

    for(int i=0;i<10;i++)
    {
        // Generate input testcase
        filesystem::path innnnnnnn = innnnnnnnn;
        filesystem::current_path(innnnnnnn);
        
        string current_file = create_txt("input0", i);
        const char * current_filee = current_file.c_str();
        fp = fopen(current_filee,"w");
        Write_and_randomGlobalVar(fp);
        fclose(fp);

        // Generate output testcase
        filesystem::path onnnnnnnn = ouuuuuuuuu;
        filesystem::current_path(onnnnnnnn);
        
        string currentt_file = create_txt("output0", i);
        const char * ccurrent_file = currentt_file.c_str();
        create_txt("output0", i);
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