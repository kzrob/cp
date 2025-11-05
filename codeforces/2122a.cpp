#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n; cin >> n;
    int m; cin >> m;

    if (n * m <= 4) {
        return "NO";
    }
    return "YES";
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
