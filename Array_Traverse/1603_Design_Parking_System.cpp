//https://leetcode.com/problems/design-parking-system/

#include <iostream>
using namespace std;

int space[3];

void ParkingSystem(int big, int medium, int small) {
    space[0] = big;
    space[1] = medium;
    space[2] = small;
}

bool addCar(int carType) {
    if( space[carType-1] >0 ) {
        space[carType-1]--;
        return true;
    }

    return false;
}

int main() {
    ParkingSystem(1,1,0);

    if( addCar(1) ) cout << "true"; else cout << "false";
    if( addCar(2) ) cout << "true"; else cout << "false";
    if( addCar(3) ) cout << "true"; else cout << "false";
    if( addCar(1) ) cout << "true"; else cout << "false";

    return 1;
}
