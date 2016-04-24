// Santiago Andaluz Ruiz
#include <vector>
#include <iostream>

using namespace std;
void printBoard(vector<vector<bool> > *board){
    for ( auto row : *board) {
        for ( auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

bool addQueen(vector<vector<bool> > *board, vector<pair<int,int> > *holes) {

    return false;
}


int main() {

    int numberQueens,
        numberHoles,
        x,
        y;

    vector<vector<bool> > board(numberQueens,vector<bool>(numberQueens,false));
    vector<pair<int, int> >holes;

    cin >> numberQueens >> numberHoles ;

    for ( int i = 0 ; i < numberHoles; i++) {
        cin >> x >> y;
        holes.push_back(make_pair(x,y));
        board[x][y] = true;
    }

    printBoard(&board);


    //cout << numberQueens << " " << numberHoles << " " << holes.size() << endl;


    return 0;
}
