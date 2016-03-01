#include <iostream>
#include <algorithm>
#include <string>
string line;

using namespace std;
bool MyCompare(char* a, char* b){
    unsigned int index = 0;
    while(a[index] != '\0' && b[index] != '\0') {
        if ( a[index] < b[index] )
            return true;
        else if (b[index] < a[index] )
            return false;
        index++;
    }
    return false;
}


int main (){

    vector<int> list;
    while (getline(cin,line)) {
        list = vector<int>(line.size());
        for (int i = 0; i < line.size(); ++i) {

        }
    }
    return 0;
}
