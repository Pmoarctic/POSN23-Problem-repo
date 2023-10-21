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
ll random(int PLUS,ll LIMIT,ofstream& inputFile);
string multiplyStrings(string num1, string num2); 


//template "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"


//input Folder name (Editable)
string folderName = "DGL_AxB_problem";
long long ITEM = 10;

///////////////////////////////////////////////////////////////////////////////

void Process(ofstream& in, ofstream& out)
{
    string a = ran_str(9000,"0123456789",in);
    string b = ran_str(9000,"0123456789",in);
    string c = multiplyStrings(a,b);
    out << c;
    
}

////////////////////////
///main function process (Editable) **using 'out << n;'  instead of  'fprintf();'


















































string create_file(string nm,int idx,char opr)
{
    if(opr == 'N')
    {
        nm += idx+'0';
        ofstream outfile(nm);
        return nm;
    }
    else if(opr == 'I')
    {
        string tmp = "";
        if(idx == 0)
        {
            tmp += "10.in";
            ofstream outfile(tmp);
        }
        else
        {
            tmp += idx+'0';
            tmp += ".in";
            ofstream outfile(tmp);
        }
        return tmp;
    }
    else if(opr == 'O')
    {
        string tmp = "";
        if(idx == 0)
        {
            tmp += "10.sol";
            ofstream outfile(tmp);
        }
        else
        {
            tmp += idx+'0';
            tmp += ".sol";
            ofstream outfile(tmp);
        }
        return tmp;
    }
    return nm;
}

int main()
{
    srand(time(NULL));
    string TmpFolderName = "D:/GenTestCase/";

    TmpFolderName += folderName;
    const char * cfffffffff = TmpFolderName.c_str();
    CreateDirectory(cfffffffff,NULL);
    filesystem::path newDir = cfffffffff;
    filesystem::current_path(newDir);


    string TmpFolderNamee = TmpFolderName;
    TmpFolderNamee += "/Nu";
    const char * zfffffffff = TmpFolderNamee.c_str();
    CreateDirectory(zfffffffff,NULL);
    filesystem::path newDiR = zfffffffff;
    filesystem::current_path(newDiR);

    for(int i=0;i<ITEM;i++)
    {
            string input_file = create_file("input.", i,'N');
            ofstream inputFile(input_file);

            string output_file = create_file("output.", i,'N');
            ofstream outputFiles(output_file);

            Process(inputFile,outputFiles);
            inputFile.close();
            outputFiles.close();
    }

    TmpFolderName += "/Chs";
    const char * kfffffffff = TmpFolderName.c_str();
    CreateDirectory(kfffffffff,NULL);
    filesystem::path newDIR = kfffffffff;
    filesystem::current_path(newDIR);

    for(int i=0;i<ITEM;i++)
    {
            string input_filee = create_file("", i,'I');
            ofstream iinputFile(input_filee);

            string output_filee = create_file("", i,'O');
            ofstream ooutputFiles(output_filee);

            Process(iinputFile,ooutputFiles);
            iinputFile.close();
            ooutputFiles.close();
    }
}

ll random(int PLUS,ll LIMIT,ofstream& inputFile)
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
