/*
 * Collision works
 * Checking the right rectangles with each other works
 *
 * Error when there is a collision and the max size
 *
 * if everything collides find the max size
 *
 * make a size vector to make adding the size easy?
 * 
 * doesnt stop when it should in checkCol function
 */
#include <iostream>
#include <vector>


using namespace std;

struct rect{
    int w,
        h,
        x,
        y;

    rect(){}

    rect(int temp1, int temp2, int temp3, int temp4){
        w = temp1;
        h = temp2;
        x = temp3;
        y = temp4;
    }
};

bool checkCol(rect *first, rect *second){
    /*
    cout << "Collision Check:\nFIRST\n";
    cout << "(" << first->x << "," << first->y << ") "
        <<  "(" << first->x + first->w << "," << first->y << ")" << endl
        <<  "(" << first->x << "," << first->y + first->h << ") " 
        <<  "(" << first->x + first->w << "," << first->y + first->h << ")\n";

    cout << "SECOND\n";
    
    cout << "(" << second->x << "," << second->y << ") "
        <<  "(" << second->x + second->w << "," << second->y << ")" << endl
        <<  "(" << second->x << "," << second->y + second->h << ") " 
        <<  "(" << second->x + second->w << "," << second->y + second->h << ")\n";

    cout <<"END CHECK\n";
    */

    return ((first->x < (second->x + second->w)) && ((first->x + first->w) > second->x)
        && (first->y < (second->y + second->h)) && ((first->y + first->h) >  second->y));
}

int calcMaxSize(vector<rect> *rectangles, int *maxArea){

    unsigned int perm = 1 << rectangles->size();
    int tempSize;
    bool col;

    perm--;

    while (perm != 0){
        tempSize = 0;
        unsigned int temp = perm;
        unsigned int mask = 1 << (rectangles->size() - 1);
        col = false;




        cout << "Perm: " << perm << endl;
        for(unsigned int i = 0; i < (rectangles->size()); i++){
                            cout << *maxArea << " " << tempSize << endl;
            for( unsigned int j = i; j < (rectangles->size()); j++){
                cout << "Rectangles[" << i << "] vs Rectangles[" << j <<"]\n";
                if( i != j ){
                    if( ((temp & (mask >> i)) != 0)){
                        if(((temp & (mask >> j)) != 0)){
                            if((checkCol(&rectangles->at(i),&rectangles->at(j)))){
                                cout <<  "COLLISION" <<i << " " << j << " " ;
                                j = rectangles->size();
                                i = rectangles->size();
                                tempSize = 0;
                                col = true;
                                cout << *maxArea << " " << tempSize << endl;
                            }
                        }
                    }
                }
            }
            if(!col) {
                tempSize += (rectangles->at(i).w * rectangles->at(i).h);
            }

        }

        if( *maxArea < tempSize ) {
            *maxArea = tempSize;
        }

        perm--;
    }
    
    return *maxArea;
}



int main(){
    int lines;
    int w,h,x,y;

    int maxSize = 0;

    vector<rect> stories;

    while(cin >> lines){
        if( lines != 0 ) {
            while(lines != 0) {
                cin >> w >> h >> x >> y;
                stories.push_back(rect(w,h,x,y));
                lines--;
            }
            
            maxSize = 0;
            maxSize = calcMaxSize(&stories, &maxSize);

            cout << maxSize << endl;


            stories.clear();
        }

    }

    return 0;
}
