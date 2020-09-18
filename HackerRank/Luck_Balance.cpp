//https://www.hackerrank.com/challenges/luck-balance/problem

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    int sum=0;
    vector<int> importGame;
    vector<int> unimportGame;

    for(vector<int> v : contests) {
        if(v[1] == 1) {
            importGame.push_back(v[0]);
        }else {
            unimportGame.push_back(v[0]);
        }
    }

    sort(importGame.begin(), importGame.end(), [](int& l, int& r) {
        return l>r;
    });

    for(int i=0; i<k && i<importGame.size(); i++) {
        sum += importGame[i];
    }

    if( k < importGame.size() ) {
        for(int i=k; i<importGame.size(); i++) {
            sum -= importGame[i];
        }
    }

    for(int i=0; i<unimportGame.size(); i++) {
        sum += unimportGame[i];
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

    cout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
