#include <bits/stdc++.h>
using namespace std;

int main() {
    //fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //constraints
    int N, M;
    cin >> N >> M;

    //symbols
    vector<vector<bool>> dwl(N, vector<bool>(N, 0)); //true when elsie loses

    //input dwl
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            char c;
            cin >> c;
            dwl[i][j] = (c == 'L');

            if (i != j) {
                dwl[j][i] = (c == 'W');
            }
        }
    }

    //debugging
    /*
    for (auto row : dwl) {
        for (bool b : row) {
            cout << b << " ";
        }
        cout << "\n";
    }
    */

    //games
    while (M--) {
        int l, r;
        cin >> l >> r;
        l--; r--; //remove one index

        int count = 0;
        for (int i = 0; i < N; i++) {
            if (dwl[l][i] & dwl[r][i]) {
                count++;
            }
        }

        int output = 0;
        for (int i = 1; i <= count; i++) {
            output += (2*N - 1) - 2*(i-1);
        }
        cout << output << "\n";
    }

    return 0;
}
