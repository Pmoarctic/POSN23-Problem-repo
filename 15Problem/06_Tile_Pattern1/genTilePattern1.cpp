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
string folderName = "06_Tile_Pattern2";

//global input (Editable)    ( must Edit in fn(Write_and_randomGlobalVar)   )
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n,r,l;

///////////////


//OUTPUT


//(Editable)
//template "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
//   fprintf(fp,"%s",str.c_str());  (string)
void Write_and_randomGlobalVar(ofstream& outputFile)
{ 

    n = rand()%26;
    r = rand()%100;
    l = rand()%100;

    outputFile << n << " " << " " << r << " " << l << endl;
    
}
///////////////////////////////////
string multiplyStrings(string num1, string num2) 
{
    int len1 = num1.length();
    int len2 = num2.length();
    int len = len1 + len2;

    int result[len] = {};

    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string resultStr = "";
    int i = 0;
    while (i < len && result[i] == 0)
    {
        i++;
    }
    while (i < len) 
    {
        resultStr += result[i] + '0';
        i++;
    }

    return resultStr=="" ? "0" : resultStr;
}

///main function process (Editable) **using 'outputFile << n;'  instead of  'printf();'

//   fprintf(fp,"%s",str.c_str());  (string)

void Process(ofstream& outputFile)
{
    int idx = 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<l;j++)
        {
            outputFile << alpha[idx%n];
            idx++;
        }
         outputFile << endl;
    }

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