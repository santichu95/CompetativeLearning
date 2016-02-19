#include <iostream>
#include <string>

using namespace std;

int main (){
    string temp; 
    while ( getline(cin, temp){
        int n = temp.size();
        string list[n];
        for ( int i = 0; i < n;i++) 
            list[i] = line.substr(i) + line.substr(0, n - i);
        sort(begin(list), end(list));

        for( string s : list)
            cout << s[n - 1];
        cout << endl;
        
    }
    return 0;
}
