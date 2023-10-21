#include <bits/stdc++.h>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
namespace fs = std::filesystem;
using namespace std;

long long MAX = INT_MAX;

string ran_str(int length,string RANDOM_STRING) {
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
string folderName = "PL_LongestDis";

//global input (Editable)    ( must Edit in fn(Write_and_randomGlobalVar)   )
int n;
int x[10000],y[10000];
///////////////


//OUTPUT


//(Editable)
//template "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
//   fprintf(fp,"%s",str.c_str());  (string)
void Write_and_randomGlobalVar(ofstream& outputFile)
{ 
    n = rand()%10000;

    outputFile << n << endl;

    //random string case
    for(int i=0;i<n;i++)
    {
        x[i] = rand()%10000;
        y[i] = rand()%10000;
        outputFile << x[i] << " " << y[i] << endl;
    }
    
}
///////////////////////////////////

///main function process (Editable) **using 'outputFile << n;'  instead of  'printf();'

//   fprintf(fp,"%s",str.c_str());  (string)

void Process(ofstream& outputFile)
{
    double mx = INT_MIN;
    for(int i=1;i<n;i++)
    {
        mx = max(mx,sqrt((x[i]-x[0])*(x[i]-x[0])+(y[i]-y[0])*(y[i]-y[0])));
    }

    outputFile << fixed << setprecision(2) << mx;
}

////////////////////////



















































string create_file(string nm,int idx)
{
    nm += idx+'0';
    ofstream outfile(nm);
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
        string current_file = create_file("input.", i);
        //const char * current_filee = current_file.c_str();
        ofstream outputFile(current_file);
        Write_and_randomGlobalVar(outputFile);
        outputFile.close();

        // Generate output testcase
        string currentt_file = create_file("output.", i);
        //const char * ccurrent_file = currentt_file.c_str();
        ofstream outputFiles(currentt_file);
        Process(outputFiles);
        outputFiles.close();
    }

}

/*
    template
    int O = rand()%1000;
    int X = rand()%100;
    int n = rand()%10;
    fprintf(fp,"%d %d\n%d\n",O,X,n);

*/