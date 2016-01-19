/*
   Santiago Andaluz Ruiz
*/
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
    string line;
    int i = 0,
        days = 0,
        tempLen,
        enterTime,
        exitTime,
        diffTime,
        index;
    vector<pair<string, int> >customers,exitCust;
    pair<string, int> cust;
    vector<pair<string, int> >::iterator it;
    cout << setprecision(2) << fixed;
    while(getline(cin,line)){
       //cout << line << endl;
       if(line.find("CLOSE") == 0){
           days++;
           cout << "Day " << days << endl;
           sort(customers.begin(),customers.end());
           while(!customers.empty()){
               cout << customers.front().first << " $" << (float)customers.front().second * .1 << endl;
               customers.erase(customers.begin());
           }
           customers.clear();
           cout << endl;
       }

       tempLen = line.rfind(" ") - line.find(" ") - 1;
       cust = make_pair(line.substr(line.find(" ") + 1,tempLen),atoi(line.substr(line.rfind(" ") + 1).c_str()));
       it = customers.begin();
       while(it != customers.end() && it->first != cust.first){
           ++it;
       }
       if(line.find("ENTER") == 0){
           //cout << cust.first << "" << cust.second << endl;
           if( it == customers.end())
                customers.push_back(cust);
           else{
               it->second = cust.second - it->second;
           }

           //cout << "Enter" << endl; 
       }
       else if(line.find("EXIT") == 0){
            //index = customers.begin() - it;
            diffTime = cust.second - it->second;
            it->second = diffTime;
           //exitCust.push_back(cust);
           //cout << "Exit" << endl;
       }

              
    }
    //cout << "Number of days" << days << endl;
    return 0;
}
