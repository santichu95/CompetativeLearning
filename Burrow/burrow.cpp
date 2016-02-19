#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main (){
    string temp; 
    string shifted;
    while ( getline(cin, temp)){
        int n = temp.size();
        map<string, int> list;
        temp +=temp;
        for ( int i = 0; i < n;i++) {
            shifted = temp.substr(i,n);
            if(list.find(shifted) != list.end()){
                list[shifted] = 1;
            }
            else
                list[shifted] = list[shifted] + 1;
        }

        for ( auto a : list) {
            for( int i = 0; i < a.second;i ++){
                cout << a.first[n - 1];
            }
        }

        list.clear();
        cout << endl;
        
    }
    return 0;
}
