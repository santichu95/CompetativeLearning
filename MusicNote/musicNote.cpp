/*
 *  Santiago Andaluz
 */
using namespace std;
#include <iostream>
#include <deque>
#include <string>
#include <cstdlib>

int charToInt(char tempLetter){
    int charNum;
    switch(tempLetter){
        case 'G':
            charNum = 0;
            break;
        case 'F':
            charNum = 1;
            break;
        case 'E':
            charNum = 2;
            break; 
        case 'D':
            charNum = 3;
            break;
        case 'C':
            charNum = 4;
            break;
        case 'B':
            charNum = 5;
            break;
        case 'A':
            charNum = 6;
            break;
        case 'g':
            charNum = 7;
            break;
        case 'f':
            charNum = 8;
            break;
        case 'e':
            charNum = 9;
            break;
        case 'd':
            charNum = 10;
            break;
        case 'c':
            charNum = 11;
            break;
        case 'b':
            charNum = 12;
            break;
        case 'a':
            charNum = 13;
            break;
        }
    return charNum;
}

int main(){
    deque<deque<int> >mSheet(14);
    char noteIndex[14] = {'G','F','E','D','C','B','A','g','f','e','d','c','b','a'};
    enum Notes{G,F,E,D,C,B,A,g,f,e,d,c,b,a};
    deque<int> mSheetDur;
    char filler;
    string note;
    int  songLength,
         curNote = -1,
         noteInt,
         noteDur,
         curDur;
    
    cin >> songLength;

    for(int i = 0;i < songLength; i++){
        cin >> note;
        noteInt = charToInt(note[0]);
        if(note.size() > 1)
            noteDur = (note[1]) - '0';
        else
            noteDur = 1;
        //cout << i << " " <<  note << " " << noteInt << endl;
        mSheet[noteInt].push_back(i);
        mSheetDur.push_back(noteDur);
        //cout << mSheet[curLetter].back();

    }
    
    /*
    for(int i = 0; i < mSheet.size();i++){
        cout << noteIndex[i] << ": ";
        for( int j = 0; j < mSheet[i].size();j++){
            cout << mSheet[i][j];
        }
        cout << endl;
    }
    */
    for(int i = G; i <= a; i++){
        cout << noteIndex[i] << ": " ;
        
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 13)
                filler = '-';
            else
                filler = ' ';
        curNote = -1;
        curDur = -1;
        for(int j = 0; j < songLength; j++){
            
            if(curNote < j && !mSheet[i].empty()){
                curNote = mSheet[i].front();
                mSheet[i].pop_front();
            }
           
            for(int k = 0; k < mSheetDur[j]; k++) 
                if(j == curNote){
                    cout << '*';
                }
                else
                    cout << filler;
            if(j != songLength -1)
                cout << filler;
            
        }
        cout << endl;
    }

    return 0;   
}

