/*
   Santiago Andaluz Ruiz
 */

#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <iterator>
#include <map>

using namespace std;
int hashString(string temp){
    int hashNum = 0;

    for ( char var : temp ) {
        hashNum = hashNum ^ var;
    }

    return hashNum;
}

int main () {
    int num, temp;
    int unique = 0, coll = 0;
    vector<string>::iterator it;

    string line;
    map<int, vector<string> > files;

    cin >> num;
    getline(cin, line);

    bool matched = false;

    while( num != 0 ) {
        for ( int i = 0; i < num; i++ ) {
            getline(cin, line);
            temp = hashString(line);
            if ( files.empty() ) {
                files[temp].push_back(line);
                unique ++;
            } else if ( files.find(temp) != files.end() ) { //Hash coll
                it = files[temp].begin();
                for ( ; it != files[temp].end() ; it++ ) {
                    coll++;
                    if ( it->compare(line) == 0 ) {
                        matched = true;
                        break;
                    }
                }
                if ( !matched ) {
                    unique++;
                }
                files[temp].push_back(line);
            } else {                                        //NO hash coll
                unique++;
                files[temp].push_back(line);
            }

        }

        cout << unique << "  " << coll << endl;

        unique = 0;
        coll = 0;

        matched = false;

        files.clear();
        cin >> num;

        getline(cin, line);
    }

    return 0;
}
