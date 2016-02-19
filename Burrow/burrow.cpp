#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main (){
    string temp; 
    while ( getline(cin, temp)){
        int n = temp.size();
        vector<string> list(n);
        for ( int i = 0; i < n;i++) 
            list[i] = temp.substr(i) + temp.substr(0, i);
        sort(list.begin(),list.end());

        for( string s : list)
            cout << s[n - 1];
        cout << endl;
        
    }
    return 0;
}
