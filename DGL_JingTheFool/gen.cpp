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
string folderName = "DGL_JingTheFool";

//global input (Editable)    ( must Edit in fn(Write_and_randomGlobalVar)   )
int n,m;
///////////////


//OUTPUT


//(Editable)
//template "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
//   fprintf(fp,"%s",str.c_str());  (string)
void Write_and_randomGlobalVar(ofstream& outputFile)
{ 
    n = rand()%10000;

    outputFile << n << endl;
    
}
///////////////////////////////////

///main function process (Editable) **using 'outputFile << n;'  instead of  'printf();'

//   fprintf(fp,"%s",str.c_str());  (string)

void Process(ofstream& outputFile)
{
    float sum,charge;

    if(n <= 50){

        sum = n*0.5;

    }else if(n>50 && n <= 150){

        sum = (50*0.5) + ((n-50)*0.75);

    }else if(n>150 && n<= 250){

        sum = (50*0.5) + (100*0.75) + ((n-150)*1.25);

    }else if(n>250){

        sum = (50*0.5) + (100*0.75) + (100*1.25) + ((n-250)*2.5);
    }

    if(n<=10){

        sum+=sum*0.2;

    }else if(n>10 && n<=100){

        sum+=sum*0.5;

    }else{

        sum+=sum*0.7;

    }

    outputFile << fixed << setprecision(2) << sum;
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