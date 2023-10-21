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
string folderName = "PL_SizeShirt";

//global input (Editable)    ( must Edit in fn(Write_and_randomGlobalVar)   )
int n;
string ar[10000],br[10000];
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
        string tmp1 = ran_str(1,"SML");
        
        if(tmp1 == "S" || tmp1 == "L")
        {
            string p1 = "";
            int num1 = (rand()%100)+10;
            while(num1--)
            {
                p1 += "X";
            }
            p1+=tmp1;
            tmp1 = p1;
        }
        

        string tmp2 = ran_str(1,"SML");
        
        if(tmp2 == "S" || tmp2 == "L")
        {
            string p2 = "";
            int num2 = (rand()%40)+10;
            while(num2--)
            {
                p2 += "X";
            }
            p2+=tmp2;
            tmp2 = p2;
        }
        

        outputFile << tmp1 << " " << tmp2 << endl;

        ar[i] = tmp1;
        br[i] = tmp2;
    }
    
}
///////////////////////////////////

///main function process (Editable) **using 'outputFile << n;'  instead of  'printf();'

//   fprintf(fp,"%s",str.c_str());  (string)

void Process(ofstream& outputFile)
{
    for(int i=0;i<n;i++)
    {
        string a =ar[i];
        string b =br[i];
        int countx1=0,countx2=0;
        char indi1,indi2;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]=='X')
                countx1++;
        }
        indi1=a[a.length()-1];
        for(int i=0;i<b.length();i++)
        {
            if(b[i]=='X')
                countx2++;
        }
        indi2=b[b.length()-1];
        if(indi1=='L'&&indi2=='L')
        {
            if(countx1>countx2)
                outputFile << ">\n";
            else if(countx2>countx1)
                outputFile << "<\n";
            else
                outputFile << "=\n";
        }
        else if(indi1=='S'&&indi2=='S')
        {
            if(countx1>countx2)
                outputFile << "<\n";
            else if(countx2>countx1)
                outputFile << ">\n";
            else
                outputFile << "=\n";
        }
        else if(indi1=='L'&&(indi2=='S'||indi2=='M'))
            outputFile << ">\n";
        else if(indi1=='S'&&(indi2=='L'||indi2=='M'))
            outputFile << "<\n";
        else if(indi1=='M'&&indi2=='M')
            outputFile << "=\n";
        else if(indi1=='M'&&indi2=='S')
            outputFile << ">\n";
        else if(indi1=='M'&&indi2=='L')
            outputFile << "<\n";
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