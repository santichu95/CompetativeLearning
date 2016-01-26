/* 
    Santiago Andaluz Ruiz
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string word;
    vector<string> pali;
    bool notDone = true,notDoneDouble = true; 
    int paliSize,
        centerLeft,
        centerRight;

    while(cin >> word){
        pali.clear();
        for(int i = 0; i < word.size(); i++){
            paliSize = 1;
            notDone = true;
            while(notDone){
                if(i + paliSize < word.size() && i - paliSize >= 0){
                    if(word[i-paliSize] == word[i + paliSize]){
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
                    if(word[centerLeft - paliSize] == word[centerRight + paliSize]){
                        pali.push_back( word.substr(centerLeft - paliSize, centerRight - centerLeft + paliSize *2 + 1 ));
                    }
                    else
                        notDoneDouble = false;
                }
                else
                    notDoneDouble = false;
                paliSize++;
            }

        }
        
        sort(pali.begin(),pali.end());
        reverse(pali.begin(), pali.end() );
        pali.erase( unique( pali.begin(), pali.end() ), pali.end());

       if(!pali.empty()){
            while(!pali.empty()){
                cout << pali.back() << endl;
                pali.pop_back();
            }
        
        cout << endl;
        }
    }


    return 0;
}
