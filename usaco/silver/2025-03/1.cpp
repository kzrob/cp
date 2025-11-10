#include <bits/stdc++.h>
using namespace std;

int countBits(int n) { // Brian Kernighan’s Algorithm
    int count = 0;
    while (n > 0) {
        n &= (n - 1); 
        count++;
    }
    return count;
}

int solve() {
    return 0;
}

int main() {
    //fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //constraints
    int T; cin >> T;

    while (T--) {
        cout << solve() << "\n";
    }

    return 0;
}
