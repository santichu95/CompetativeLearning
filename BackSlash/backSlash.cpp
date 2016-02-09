/*
    Santiago Andaluz Ruiz
 */
#include <string> 
#include <iostream>
#include <cmath>

using namespace std;

int main () {
    string outString;
    int times;
    char letter;
    while(cin >> times) {
        cin >> letter;
        cin >> noskipws;
        while(letter != '\n') {
            if ((letter >= '!' && letter <= '*') ||  (letter >= '[' && letter <= ']') ) {
                for(int i = 0; i < (pow(2,times) - 1); i++){
                    outString.push_back('\\'); 
                }
            }
            outString.push_back(letter);
            cin >> letter;
        }
        cout << outString << endl;
        outString.clear();
        cin >> skipws;
    }
    return 0;
}
