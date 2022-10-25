#include <iostream>
#include <vector>
#define ELEMENTS 6

using namespace std;

vector <int> poleOne = {6,5,4,3,2,1};
vector <int> poleTwo = {-1,-1,-1,-1,-1,-1};
vector <int> poleThree = {-1,-1,-1,-1,-1,-1};

void showArrays() {
    string line = "  ";
    for(int i = ELEMENTS - 1; i >= 0; i--) {
        if(poleOne[i] != -1)
            line = line + to_string(poleOne[i]) + "  |";
        if(poleTwo[i] != -1)
            line = line + to_string(poleTwo[i]) + "  |";
        if(poleThree[i] != -1)
            line = line + to_string(poleThree[i]) + "  |";
        cout << line << endl;
        line = "  ";
    }
}

void moveToSlot(int slotNumber, int slotToMove) {
    int temp;
    switch(slotNumber) {
        case 1:
            temp = poleOne.back();
            poleOne.back() = -1;
        case 2:
            temp = poleTwo.back();
            poleTwo.back() = -1;
        case 3:
            temp = poleThree.back();
            poleThree.back() = -1;
    }
    switch(slotToMove) {
        case 1:
            poleOne.erase(poleOne.begin());
            poleOne.insert(poleOne.begin(), temp);
        case 2:
            poleTwo.erase(poleTwo.begin());
            poleTwo.insert(poleTwo.begin(), temp);
        case 3:
            poleThree.erase(poleThree.begin());
            poleThree.insert(poleThree.begin(), temp);
    }
}
int main() {

    moveToSlot(1,2);
    showArrays();

    return 0;
}
