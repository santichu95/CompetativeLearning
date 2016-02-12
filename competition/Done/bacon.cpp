/*
   Santiago Andaluz RUiz
*/

using namespace std;

#include <map>            
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

int main (){
    map<string,int> foodList;
    vector<vector<string> > custList;
    string food,
           name;
    stringstream order;
    bool first = true;
    bool firstCust = true;
    int custNum,index;
    while(cin >> custNum) {
        if(!firstCust){
            cout << endl << endl;
        }
        else
            firstCust = false;
        for( int i = 0 ;i < custNum; i++) {
            cin >> name;
            cin.get();
            getline(cin,food);
            order << food;
            while(order >> food){
                if( foodList.find(food) == foodList.end()){
                    foodList[food] = foodList.size() - 1;
                    custList.push_back(vector<string>() );
                }
                custList[foodList[food]].push_back(name);


            }
            order.clear();

        }
            for(auto var : foodList) {
                //cout << var.first << " " << var.second << endl;
                sort(custList[var.second].begin(),custList[var.second].end());
                if(!first){
                    cout << endl;
                }
                else
                    first = false;
                cout << var.first;
                for( auto cust : custList[var.second]){
                    cout << " " << cust;
                }
            }
            foodList.clear();
            custList.clear();
            first = true;
    }
    return 0;
}
