#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


void ParseStr(const vector<string> &testCases)
{
    string line;
    string token;
    string extension;
    int size;
    vector <string> tokens;
    vector <string> extensions;
    vector <int> sizes;
    int totalImgSize=0, totalMusicSize=0, totalMovieSize=0 , totalOtherSize=0;
    int i,j ; //Counters
    
    for(i = 0 ; i < testCases.size() ; i++)
    {
        stringstream fileStr(testCases[i]);
        while(getline(fileStr,line))
        {
            stringstream liness(line);
            //Split string by dots
            while( getline( liness, token, '.' ) ) {
                tokens.push_back(token);
            }
            
            //convert last token into stringstream
            stringstream lastToken(tokens[tokens.size() - 1]);
            
            //Split extension and size in the last token
            lastToken >> extension;
            extensions.push_back(extension);
            lastToken >> size;
            sizes.push_back(size);
        }
        
        for(j = 0 ; j < extensions.size() ; j++)
        {
            if((extensions[j] == "mp3") || (extensions[j] == "aac") || (extensions[j] == "flac"))
            {
                totalMusicSize += sizes[j];  
            }
            else if((extensions[j] == "jpg") || (extensions[j] == "bmp") || (extensions[j] == "gif"))
            {
                totalImgSize += sizes[j];
            }
            else if((extensions[j] == "mp4") || (extensions[j] == "avi") || (extensions[j] == "mkv"))
            {
                totalMovieSize += sizes[j];
            }
            else
            {
                totalOtherSize += sizes[j];
            }
        }
        
        cout << "music " << totalMusicSize << "b " << "images " << totalImgSize << "b " << "movies " << totalMovieSize << "b " << "other " << totalOtherSize << "b\n" ; 
        totalMovieSize = totalImgSize = totalMusicSize = totalOtherSize = 0 ;
        sizes.clear();
        extensions.clear();
        
    }
}

int main()
{
    string temp;
    string str;
    string testCaseTemp = "";
    int testCasesNum;
    int testCaseLinesNum;
    vector <string> testCases;
    
    getline(cin , str);
    stringstream ss(str);
    ss >> testCasesNum;
    ss >> testCaseLinesNum;
    
    while (testCasesNum)
    {
        while (testCaseLinesNum)
        {
            getline(cin , temp);
            testCaseTemp += temp + "\n";
            testCaseLinesNum --;
        }
        
        testCases.push_back(testCaseTemp);
        ss >> testCaseLinesNum;
        testCaseTemp = "";
        testCasesNum -- ;
    }
    
    ParseStr(testCases);
    
}