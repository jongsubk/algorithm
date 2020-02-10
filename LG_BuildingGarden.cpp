/* LG_BuildingGarden.cpp */
/* 각 옥상 정원에서 볼수 있는 옥상의 총 합을 출력한다.

   1. 건물은 일렬로 정렬되어 있으며 N개가 있음. N은 6이상 80,000 이하임
   2. 각 건물의 높이 H는 1이상 1,000,000,000 이하임
   3. 각 건물에 한사람씩 있고, 동쪽만 바라본다고 가정하며, 건물 정보는 서쪽에서 동쪽 순으로 입력
*/

#include <iostream>
//#include <stack>
using namespace std;

int N;
int H[80010];

void Input_Data(void){
	int i;
	N = 6;
	H[0] = 5;
	H[1] = 2;
	H[2] = 4;
	H[3] = 2;
	H[4] = 6;
	H[5] = 1;
}

/* my solution using stack, LG sol.*/
long long solve() {
	long long ret=0;
	int stack[80010];
	int sp = 0;

	for(int i=0; i<N; i++) {
		while(sp > 0) {
			if( H[i] < stack[sp] ) break;
			sp--;
		}
		ret += sp;
		stack[++sp] = H[i];
	}
	return ret;
}

int main() {
	long long ans = 0;
	Input_Data();
	
	/* Brute Force */
	#if 0
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N; j++){
			if( H[i] <= H[j] ) {
				break;
			}
			ans++;
		}
	}
	#endif
	
	cout << solve();
	
	return 0;
}