#include <bits/stdc++.h>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
namespace fs = std::filesystem;
using namespace std;
#define ll long long
long long MAX = INT_MAX;

//declare function;
string ran_str(int length,string RANDOM_STRING,ofstream& inputFile);
ll random(ll LIMIT,ofstream& inputFile,int PLUS);
string multiplyStrings(string num1, string num2); 


//template "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"




//input Folder name (Editable)
string folderName = "PairNumber1";

///////////////////////////////////////////////////////////////////////////////

void Process(ofstream& in, ofstream& out)
{
     int n = random(1000,in,0);
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int temp = random(1200,in,0);
        mp[temp]=1;
    }
    int q = random(200,in,100);
    for(int i=0;i<q;i++)
    {
        int sum = random(250,in,3);
        int check=0;
        for(auto it:mp)
        {
            //cout << it.first;
            if(it.first==sum-it.first)
                break;
            if(mp.find(sum-it.first)!=mp.end())
            {
                check=1;
                out << "YES\n";
                break;
            }
        }
        if(check==0)
            out << "NO\n";
    }

}

////////////////////////
///main function process (Editable) **using 'out << n;'  instead of  'fprintf();'


















































string create_file(string nm,int idx)
{
    nm += idx+'0';
    ofstream outfile(nm);
    return nm;
}



int main(){
    //FILE *fp;
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
        string input_file = create_file("input.", i);
        ofstream inputFile(input_file);

        // Generate output testcase
        string output_file = create_file("output.", i);
        ofstream outputFiles(output_file);

        Process(inputFile,outputFiles);
        inputFile.close();
        outputFiles.close();
    }

}

ll random(ll LIMIT,ofstream& inputFile, int PLUS)
{
    ll num = (rand()%LIMIT) + PLUS;
    inputFile << num << "\n";

    return num;
}

string ran_str(int length,string RANDOM_STRING, ofstream& inputFile) {
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

    inputFile << result << endl;

    return result;
}

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

/*
    template
    int O = rand()%1000;
    int X = rand()%100;
    int n = rand()%10;
    fprintf(fp,"%d %d\n%d\n",O,X,n);

*/