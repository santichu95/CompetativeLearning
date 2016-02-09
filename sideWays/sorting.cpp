/*
    Santiago Andaluz Ruiz
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector> 
#include <cctype>
#include <cstring>
using namespace std;

bool MyCompare(const string &x, const string &y){
    string tempx = x,
           tempy = y;

    for( unsigned int i = 0; i < x.size(); i++){
        tempx[i] = tolower(tempx[i]);
    }
    for( unsigned int i = 0; i < y.size(); i++){
        tempy[i] = tolower(tempy[i]);
    }
    return tempx < tempy;
}

int main() { 
    int row, col;
    vector<string> list;
    cin >> row >> col;
    while (row != 0 && col != 0){
        list = vector<string>(col);
        
        for ( int j = 0; j < row; j++) {
            cin.get();
            for ( int i = 0;i < col; i++) {
               list[i].push_back(cin.get());
            }
        }

        stable_sort(list.begin(),list.end(),MyCompare);
        for ( int j = 0; j < row; j++) {
            for ( int i = 0;i < col; i++) {
               cout << list[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cin >> row >> col;
    }
    return 0;
}
