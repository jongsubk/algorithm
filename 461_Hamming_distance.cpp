#include <iostream>

using namespace std;


int hammingDistance(int x, int y) {
	int result = 0;

    int humming = x ^ y;
	
	while( humming ) {
        result ++;
        humming &= (humming-1);
	}
	
	return result;
}
/*
int hammingDistance(int x, int y) {
	int result = 0;
	
	while( x || y ) {
		int x1 = x&1;
		int y1 = y&1;
		if( (x&1) != (y&1) ) {
			result++;
		}
		x = x >> 1;
		y = y >> 1;
	}	
	return result;
}
*/

int main() {	
	cout << hammingDistance(1,4);


    return 0;
}