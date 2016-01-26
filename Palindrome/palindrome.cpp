/* 
    Santiago Andaluz Ruiz
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    string word;
    vector<string> pali;
    bool notDone = true,notDoneDouble = true; 
    int paliSize,
        centerLeft,
        centerRight;

    while(cin >> word){
        for(int i = 1; i < word.size(); i++){
            paliSize = 1;
            //cout << "Word: \"" << word << "\"\n";
            notDone = true;
            while(notDone){
                if(i + paliSize < word.size() && i - paliSize >= 0){
                    //cout << word.substr(i - paliSize, (paliSize*2) + 1) << endl;
                    if(word[i-paliSize] == word[i + paliSize]){
                        //cout << word.substr(i - paliSize, (paliSize*2) + 1) << endl;
                        pali.push_back(word.substr(i - paliSize, (paliSize * 2 ) + 1));
                        paliSize++;
                    }
                    else
                        notDone = false;

                }
                else
                    notDone = false;
            }

            paliSize = 0;
            centerLeft = i;
            centerRight = i + 1;
            notDoneDouble = true;
            while(notDoneDouble){
                if(centerLeft - paliSize >= 0 && centerRight + paliSize < word.size()){
                    cout << word.substr(centerLeft - paliSize, centerRight - centerLeft + paliSize *2 + 1 );
                    cout << endl;
                }
                else
                    notDoneDouble = false;
                paliSize++;
            }

        }
    }

    return 0;
}
