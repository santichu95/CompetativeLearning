#include <iostream>
#include <algorithm>
#include <cstring>

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
    char *temp = new char[100000];
    char *shifted;
    while (cin.getline(temp,100000,'\n')){
        unsigned int n = strlen(temp);
        vector<char*> list;
        
        strcat(temp,temp);
        for (unsigned int i = 0; i < n;i++) {
            shifted = temp + i;
            list.push_back(shifted);
        }
        
        sort(list.begin(),list.end(),MyCompare);

        for ( char* a : list) {
                cout << a[n - 1];

        }
        
        for ( char* a : list) {
            delete a;
        }
        list.clear();
        cout << endl;
        delete temp;
        temp = new char[100000];
    }
    delete temp;
    return 0;
}
