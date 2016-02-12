
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <sstream>


using namespace std;

int main() {
    double x1,x2,y1,y2,p;

    cout << fixed << setprecision(10);
    while(cin >> x1 >> y1 >> x2 >> y2 >> p )
    {

        x1 = pow(abs(x1 - x2),p);
        y1 = pow(abs(y1 - y2),p);
        x1 += y1;
        x1 = pow(x1, (1/p));
        cout << x1 << endl;
    }
    return 0;
}

