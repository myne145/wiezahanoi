#include <iostream>
#include <vector>
#define ELEMENTS 6
#define POLES 3

using namespace std;

vector <int> poleOne = {6,5,4,3,2,1};
vector <int> poleTwo = {-1,-1,-1,-1,-1,-1};
vector <int> poleThree = {-1,-1,-1,-1,-1,-1};

void showArrays() {
    bool isEmpty = false;
    string line = "  ";
    for(int i = ELEMENTS - 1; i >= 0; i--) {
        if(poleOne[i] != -1)
            line = line + to_string(poleOne[i]) + "  |  ";
        if(poleTwo[i] != -1) {
            line = line + to_string(poleTwo[i]) + "  |  ";

        }
        if(poleThree[i] != -1) {

            for(int j = 0; j < ELEMENTS - 1; j++) {
                if(poleTwo[j] != -1) {
                    isEmpty = true;
                }
            }
            if(!isEmpty) {
                line = line + "   |  " + to_string(poleThree[i]) + "  |  ";
                isEmpty = false;
            }
            if(isEmpty)
                line = line + to_string(poleThree[i]) + "  |  ";
        }
        cout << line << endl;

        line = "  ";
    }
}

//void checkIfEmpty(vector <int> pole) {
////        for(int i = 0; i < pole.size(); i++) {
////            pole.at(i) = "  |  ";
//    }
//}

void moveToSlot(int slotNumber, int slotToMove) {
    int temp;
    switch(slotNumber) {
        case 1:
            temp = poleOne.back();
            poleOne.back() = -1;
            break;
        case 2:
            temp = poleTwo.back();
            poleTwo.back() = -1;
            break;
        case 3:
            temp = poleThree.back();
            poleThree.back() = -1;
            break;
    }
    int x = 5;
    switch(slotToMove) {
        case 1:
            poleOne.erase(*x);
            poleOne.insert(*x, temp);
            break;
        case 2:
            poleTwo.erase(poleTwo.begin());
            poleTwo.insert(poleTwo.begin(), temp);
            break;
        case 3:
            //checkIfEmpty(poleTwo);
            poleThree.erase(poleThree.begin());
            poleThree.insert(poleThree.begin(), temp);
            break;
    }
}
int main() {
    int whichSlot, whereToPut;
    showArrays();

    do {
        cin >> whichSlot;
        cin >> whereToPut;
        moveToSlot(whichSlot, whereToPut);
        showArrays();
    } while(whichSlot != -1 || whereToPut != -1);

    return 0;
}
