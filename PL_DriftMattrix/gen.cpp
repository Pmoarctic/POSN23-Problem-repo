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
string folderName = "PL_DriftMattrix";

//global input (Editable)    ( must Edit in fn(Write_and_randomGlobalVar)   )
int r,c,n;

///////////////
string temp[10000000];
int arr[1002][1002];

//OUTPUT


//(Editable)
//template "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
//   fprintf(fp,"%s",str.c_str());  (string)
void Write_and_randomGlobalVar(ofstream& outputFile)
{ 
    r = rand()%1000;
    c = rand()%1000;
    n = rand()%1000000000+1000000;

    outputFile << r << " " << c << endl << n << endl;

    for(int i=0;i<n;i++)
    {
        string k = ran_str(1,"LRUD");
        outputFile << k << endl;
        temp[i] = k;
    }
    
}
///////////////////////////////////

///main function process (Editable) **using 'outputFile << n;'  instead of  'printf();'

//   fprintf(fp,"%s",str.c_str());  (string)

void Process(ofstream& outputFile)
{
    int st = 1;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            arr[i][j] = st++;
        }
    }

    int x1=0,y1=0,x2=c-1,y2=r-1;

    for(int i=0;i<n;i++)
    {
        string tmp = temp[i];
        if(tmp == "U")
        {
            y1++;
            y2++;
        }
        else if(tmp == "D")
        {
            y1--;
            y2--;
        }
        else if(tmp == "R")
        {
            x1--;
            x2--;
        }
        else if(tmp == "L")
        {
            x1++;
            x2++;
        }
/////////////////////////////////
        if(x1 == -1)
        {
            x1 = c-1;
        }
        else if(x2 == -1)
        {
            x2 = c-1;
        }
        else if(y1 == -1)
        {
            y1 = r-1;
        }
        else if(y2 == -1)
        {
            y2 = r-1;
        }
        else if(y1 == r)
        {
            y1 = 0;
        }
        else if(y2 == r)
        {
            y2 = 0;
        }
        else if(x1 == c)
        {
            x1 = 0;
        }
        else if(x2 == c)
        {
            x2 = 0;
        }
        
    }

    outputFile << arr[y1][x1] << " " << arr[y2][x2] << endl;

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