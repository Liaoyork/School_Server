#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char *argv[]){
    ifstream input (argv[1]);
    ofstream output (argv[2]);
    string ss;
    int NumOfWord = 0;
    int NumOfSten = 0;
    int longestStenLength = 0;
    int longestWordLength = 0;
    int calculateLongestStenLength = 1;
    int amount = 0;
    //string *longest;
    char **longest = nullptr;
    while (input >> ss){
        NumOfWord++;
        string rg = "";

        for (int i = 0 ; i < ss.length();i++){
            if (isalpha(ss[i])){
                rg += ss[i];
            }
            else if (isdigit(ss[i])){
                rg += ss[i];
            }
            else if (ss[i] == '-' || ss[i] == ',' || ss[i] == '.'){
                rg += ss[i];
            }
        }

        ss = "";
        ss = rg;

        int len = ss.length();
        if (ss[ss.length() - 1] == ',' || ss[ss.length() - 1] == '.'){
            len = ss.length() - 1;
        }
        if (ss[ss.length() - 1] == '.'){
            NumOfSten++;
            if (calculateLongestStenLength > longestStenLength){
                longestStenLength = calculateLongestStenLength;
                calculateLongestStenLength = 1;
            }
            calculateLongestStenLength = 1;
        } else {
            calculateLongestStenLength++;
        }

        
        if (len >= longestWordLength){
            if (len > longestWordLength){
                amount = 1;
                delete [] longest;
                longest = new char *[amount];
                for (int i = 0 ; i < amount; i++){
                    longest[i] = new char [len];
                }
                for (int i = 0 ;i < len; i++){
                    longest[0][i] = ss[i];
                }
            }
            else if (len == longestWordLength){
                char **temp = new char *[amount];
                for (int i = 0 ;i < amount; i++){
                    temp[i] = new char [len];
                }
                for (int i = 0 ; i < amount; i++){
                    for (int j = 0 ;j < len ;j++){
                        temp[i][j] = longest[i][j];
                    }
                }
                delete [] longest; 
                amount++;
                longest = new char *[amount];
                for (int i = 0 ; i< amount; i++){
                    longest[i] = new char [len];
                }
                for (int i = 0; i < amount - 1; i++){
                    for (int j = 0 ; j < len; j++){
                        longest[i][j] = temp[i][j];
                    }
                }
                temp = nullptr;
                for (int i = 0 ; i < len; i++){
                    longest[amount - 1][i] = ss[i];
                }
            }
            longestWordLength = len;
        }

    }
    output << "The number of words is: " << NumOfWord << endl;
    output << "The number of sentences is: " << NumOfSten << endl;
    output << "The longest sentence has a length of: " << longestStenLength << endl;
    output << "The longest word has a length of: " << longestWordLength << endl;
    output << "The longest words are: ";
    for (int i = 0; i < amount ; i++){
        output << longest[i] << " ";
    }
    output << endl;
}

