#include <iostream> 
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> connections;
vector<int> chatSize;
vector<int> answer;

int find ( int index ) {

    if ( connections[index] == index ) {
        return index;
    } else {

        int temp = find ( connections[index] ) ;
        connections[index] = temp;

        return temp;
    }
}

void merge ( int x, int y ) {
    int root1, root2;

    root1 = find ( x );
    root2 = find ( y );

    if ( root1 != root2 ) {
        if ( chatSize[root1] < chatSize[root2] ) {
            connections[root1] = root2;
            chatSize[root2] += chatSize[root1];
            chatSize[root1] = -1;
        } else {
            connections[root2] = root1;
            chatSize[root1] += chatSize[root2];
            chatSize[root2] = -1;
        }
    }
}

int main () {

    int prev = -1, time = 1;
    int n, r, a, b, c, first, second, counter;
    unsigned int i;
    stringstream output;

    while ( cin >> n ) {
        cin >> r >> a >> b >> c;


        connections = vector<int>( n );
        chatSize = vector<int>( n, 1 );

        for ( i = 0; i < connections.size(); ++i ) {
            connections[i] = i;
        }

        for ( int j = 0; j < n; ++j ) {

            do {
                r = ( r  * a + b) % c;  
                first = r;

                r = ( r  * a + b) % c;  
                second  = r;
                
                first %= n;
                second %= n;
            } while ( first == second );
            
            merge(first, second);
        }

        sort ( chatSize.begin(), chatSize.end() );
        reverse ( chatSize.begin(), chatSize.end() );

        for ( unsigned int j = 0; j < chatSize.size(); ++j ) {
            if ( chatSize[j] != -1 ) {
                counter++;
            }

            if ( prev != chatSize[j] ) {
                if ( time != 1 ) {
                    output << "x" << time;
                }
                prev = chatSize[j];
                time = 1;
                if ( chatSize[j] == -1 ) {
                    j = chatSize.size(); 
                } else { 
                    output << " " << prev;
                }
            } else {
                time++;
            }
            

        }

        
        cout << counter << output.str() << endl;

        output.str("");
        chatSize.clear();
        connections.clear();
        answer.clear();

        counter = 0;
        time = 1;
    }

    return 0;
}
