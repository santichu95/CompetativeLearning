/*
   Santiago Andaluz Ruiz
 */

#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <utility>
#include <iterator>

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
    vector<pair<int, string> >::iterator it;

    string line;
    vector<pair<int,string> >data;

    cin >> num;
    getline(cin, line);
    
    bool matched = false;

    while( num != 0 ) {
        for ( int i = 0; i < num; i++ ) {
            getline(cin, line);
            temp = hashString(line);

            if ( i != 0 ) {

                while( (it->first < temp ) && it != data.end() ) {
                    it++;
                }
                if ( it == data.end() || (it == data.begin() && it->first != temp) ) {
                    data.insert(it, make_pair(temp,line));
                    unique++;
                }
                else if ( it->first == temp) {
                    while ( it->first == temp) {
                        coll++;
                        if ( line.compare(it->second) == 0 ) {
                           matched = true;
                           it++;
                           break;
                        }
                        it++;
                    }
                    if (!matched) {
                        unique++;
                    }
                    data.insert(it, make_pair(temp,line));
                }
            } else {
                unique++;
                data.push_back(make_pair(temp, line));
            }
            it = data.begin();
            
            matched = false;
        }

        cout << unique << "  " << coll << endl;

        unique = 0;
        coll = 0;

        data.clear();
        cin >> num;

        getline(cin, line);
    }

    return 0;
}
