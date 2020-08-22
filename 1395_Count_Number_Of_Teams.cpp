#include <iostream>
#include <vector>

using namespace std;


int numTeams(vector<int>& rating) {
        int size{(int)rating.size()}, total{0};
        std::vector<std::vector<int>> dp(size, {0, 0, 0, 0});
        for(int i{1}; i < size; ++i) {
            for(int j{0}; j < i; ++j) {
                if(rating[j] < rating[i]) ++dp[i][0], dp[i][1] += dp[j][0];
                else ++dp[i][2], dp[i][3] += dp[j][2];
            }
            total += dp[i][1] + dp[i][3];
        }
        return total;
    }


int main() {
    vector<int> rating = { 2,5,3,4,6 };

    cout << numTeams(rating);

    return 1;
}