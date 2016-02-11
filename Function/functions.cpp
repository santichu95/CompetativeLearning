/*
   Santiago Andaluz Rui
 */

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>


using namespace std;

int main() {
    vector<string> domain,
                    codomain,
                    input,
                    output;
    int times;
    string firstWord;
    stringstream line;
    bool function = true,
         in = true,
         sub = false;
    while (cin >> firstWord) {
        getline(cin, firstWord);
        line << firstWord;
        
        while(line >> firstWord) {
            domain.push_back(firstWord);
        }
        
        cin >>  firstWord;

        line.clear();
        getline(cin, firstWord);
        line << firstWord;
        
        while ( line >> firstWord) {
            codomain.push_back(firstWord);
        }
        line.clear();

        cin >> times;
        getline(cin,firstWord);
        function = true;
        in = true;
        sub = false;

        for( int i = 0; i < times; i++) {
            cin >> firstWord;
            if(find(input.begin(),input.end(),firstWord) == input.end()) {
                input.push_back(firstWord);
            }
            else {
                function = false;
            }
            
            cin >> firstWord;
            cin >> firstWord;
            if(find(output.begin(),output.end(),firstWord) == output.end()){
                output.push_back(firstWord);
            }
            else
                in = false;
        }
        if(output.size() == codomain.size())
            sub = true;
              
        if(!function)
            cout << "not a function" << endl;
        else if(in && sub)
            cout << "bijective" << endl;
        else if(in)
            cout << "injective" << endl;
        else if(sub)
            cout << "surjective" << endl;
        else if(function){
            cout << "neither injective nor surjective" << endl;
        }
        
        


        /*
        for ( auto a : domain) {
            cout << a << endl;
        }
        
        for ( auto a : codomain) {
            cout << a << endl;
        }
        */

        domain.clear();
        codomain.clear();
        output.clear();
        input.clear();
    }
    return 0;
}
