#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


int main() {

    stringstream numbs;
    int temp;
    int sum = 0;
    int var;

    vector<int> answer;
    string numbers;

    while(getline(cin,numbers)) {
        numbs << numbers;
        while( numbs >> temp) {
            sum += temp;
            answer.push_back(temp);
        }
        for(int i = 0 ;i < answer.size(); i++){
            var = answer[i];
            if( var == sum - var){
                cout << var << endl;
                i = answer.size();
            }
        }
        answer.clear();
        numbs.clear();
        sum = 0;
    }
    return 0;
}

