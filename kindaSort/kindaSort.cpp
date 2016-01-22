/* 
   Santiago Andaluz Ruiz
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool custSort(string a, string b){
    //if(a[0] == b[0]){
    //    if(a[1] == b[1]){
    //        return false; 
    //    }
    //}
    //return a < b;
    string shortA = a.substr(0,2);
    string shortB = b.substr(0,2);
//    cout << shortA.size() << endl;
    return shortA < shortB;
}

int main(){
    string name;
    vector<string> listOfNames;
    int counter = 0;
    cin >> counter;
    while(counter != 0){
        cin >> name;
        listOfNames.push_back(name);
        counter--;
        if(counter == 0){
            sort(listOfNames.begin(), listOfNames.end(),custSort);
            reverse(listOfNames.begin(),listOfNames.end());
            while(!listOfNames.empty()){
                cout << listOfNames.back() << endl;
                listOfNames.pop_back();
            }
            cout << endl;
            cin >> counter;
        }
    }
    //cout << "True = "<< true;
    //cout << "\nFalse= " << false << endl;
    //cout << first << " < " << second << " = " << custSort(first,second) << endl;
}
