#include <iostream>
#include <map>
using namespace std;
#include <sstream>

int main() {
    stringstream line;
    string temp;
    map<string,int> vars;
    string op;
    int value;

    while(getline(cin,temp)){
        line << temp;
        while(line >> temp) {
            line >> op;
            if(op == "="){
                cout << "true" << endl;
                line >> value;
                vars[temp] = value;
            }
            else{
            }
            
        }
        cout << vars.size() << endl;
        for( auto a : vars){
            cout << a.first << " " << a.second << endl;
        }
        vars.clear();
        
    }
    return 0;
}
