#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

    const int MOD = 10000;
    long value, other;
    bool dec = false;
    string op;
    while ( cin >> value >> op >> other) {
        unsigned int modV = value % MOD;
        unsigned int modO = other % MOD;
        unsigned int temp = 1;
        unsigned int index = 0;
        vector<unsigned int> old;

        if( op == "+") {
            modV += modO;
        } else if (op == "*") {
            modV *= modO;
            modV %= MOD;
        } else if ( op == "^" ) {
             
            if ( other > 0) {
                temp = modV;
                other--;
                index++;
                old.push_back(temp);
            }
            while(other > 0) {
                if ( index <= other ) {
                    temp *= old.back();
                    temp %= MOD;
                    other -= index;
                    index += index;
                    if ( !dec) {
                        old.push_back(temp);
                    }

                }
                else{
                    dec = true;
                    index /= 2;
                    old.pop_back();
                }
            }
            modV = temp;

        }
        modV %= MOD;
        cout << modV << endl;
    }

    return 0;
}
