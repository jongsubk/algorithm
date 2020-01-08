#include <iostream>
using namespace std;

int N;//지도 크기
char map[110][110];//지도 정보

void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> map[i];
	}
}

int main(){
	int ans = -1;
	Input_Data();		//	입력 함수

	//	코드를 작성하세요
	if( N == 0 ) { return 0;}
	else if( N < 2) { return map[0][0]; }
	
	int dp[N+1][N+1] = {0,};
	
	for(int i=1; i<= N; i++) {
		for(int j=1;j<= N; j++) {
			if( (i==1 && j==1) || (i==N && j==N) ) { map[i-1][j-1] = '0'; }
			else if( i==1 ) { dp[i][j] = dp[i][j-1] + (map[i-1][j-1] -'0'); }
			else if( j==1 ) { dp[i][j] = dp[i-1][j] + (map[i-1][j-1] -'0'); }
			else {
				int temp_value1 = min(dp[i-1][j], dp[i][j-1]);
				int temp_value2 = (map[i-1][j-1] -'0');
			
				dp[i][j] =  temp_value1 + temp_value2;
				//cout << "-DP" << i << j << " : " << dp[i][j] << endl;
			}
		}
	}

	cout << dp[N][N] << endl;	//	정답 출력

	return 0;
}

//2차원 배열 넘기기
template<typename T>
void func(T arr) {
	cout << arr[1][1];
}

