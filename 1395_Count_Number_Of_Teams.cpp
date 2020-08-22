#include <iostream>
#include <vector>

using namespace std;

int numTeams(vector<int>& rating) {
    int teams = 0;
    int n = rating.size();
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if( (rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k]) ) {
                    teams++;
                }
            }
        }
    }
    
    return teams;
}

#if 0
int numTeams(vector<int>& rating) {
    int res = 0;
    for (int i = 1; i < rating.size() - 1; i++) {
        int less[2] = {}, greater[2] = {};
        for (auto j = 0; j < rating.size(); j++) {
            if (rating[i] < rating[j])
                less[j > i]++;
            if (rating[i] > rating[j])
                greater[j > i]++;
        }
        res += less[0] * greater[1] + greater[0] * less[1];
    }
    return res;
}
#endif

int main() {
    vector<int> rating = { 2,5,3,4,6 };

    cout << numTeams(rating);

    return 1;
}
