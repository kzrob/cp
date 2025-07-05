#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n; cin >> n;
    int k; cin >> k;

    vector<bool> s(n);

    int zeroes = 0;
    int ones = 0;

    for (int i = 0; i < n; i++) {
        bool v; cin >> v;
        s[i] = v;
        if (v == 1) {
            ones++;
        } else {
            zeroes++;
        }
    }

    if (ones <= k) {
        return "Alice";
    }




    /*
    string s; cin >> s;

    auto alice = [k, &s]() mutable -> bool {
        while (k) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '1') {
                    s[i] = '0';
                    k--;
                    break;
                }
            }
            return false;
        }
        return true;
    };

    auto bob = [k, &s]() mutable {
        for (int i = 0; i < s.size()-k; i++) {
            if (s.substr(i, k)
        }
    };

    */

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