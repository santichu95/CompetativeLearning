#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

using namespace std;

int main (){
    string tens[10] = {"","","twenty", "thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    string ones[10] = { "","one","two","three","four","five","six","seven","eight","nine"};
    string special[10] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    int digit;
    int t,o;
    bool first = true;
    stringstream line;
    string temp;
    string output;

    while(getline(cin,temp)){
        line << temp;
        while(line >> temp){

            if (isdigit(temp[0])) {
                    if(temp.size() > 1){
                        t = atoi(temp.substr(0,1).c_str());
                        o = atoi(temp.substr(1,1).c_str());
                    }
                    else{
                        t = 0;
                        o = atoi(temp.substr(0,1).c_str());
                    }
                    if(t == 1){
                        output = special[o];
                    }
                    else{
                        if(o == 0 && t == 0)
                            output = "zero";
                        else if(o==0){
                            output = tens[t];
                        }
                        else if(t==0)
                            output = ones[o];
                        else{
                            output = tens[t] + "-" +ones[o];
                        }
                    }
                    if(first) {
                        output[0] = toupper(output[0]);
                    }
            }
            else
            {
                output = temp;
            }
            if(!first)
                cout << " ";
            else
                first = false;
            cout << output;
        }                
        first = true;
        line.clear();
        cout << endl;
            
    }
    return 0;
}
