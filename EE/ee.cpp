/*
   Santiago Andaluz Ruiz
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

int main( ){
    vector<string> usedWord;
    string curWord,
           wordString,
           lowerWord;
    stringstream process;
    bool first = true;

    while (getline(cin,wordString)) {

        process << wordString;
        first = true;
        while (process >> curWord) {
            if(!first)
                cout << " ";
            lowerWord = curWord;
            for (int i = 0; i < lowerWord.size(); i++) {
                lowerWord[i] = tolower(lowerWord[i]);                
            }
            auto a = find(usedWord.begin(), usedWord.end(),lowerWord);
            if (a == usedWord.end()) {
                cout << curWord;
                usedWord.push_back(lowerWord);
                first = false;
            }
            else {
                first = false;
                cout << "." ;
            }
        }        
        process.clear();
        cout << endl;
    }

    
    return 0;
}
