/* https://codeforces.com/problemset/problem/2092/C
 * Wed, April 16, 2024
 * why tf is the solution so easy (and how tf was i supposed to come up with the solution??)
 * note its because result is always odd, and you can take evens until all odds are one
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long big;

int solve() {
    int n; cin >> n;
    big sum = 0;
    big maxi = 0;
    big odd = 0;

    for (int i = 0; i < n; i++) {
        big v; cin >> v;
        sum += v;
        maxi = max(maxi, v);
        if (v % 2 == 1) {
            odd++;
        }
    }

    if (odd == n || odd == 0) {
        return maxi;
    }
    return sum - odd + 1;
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

// took ~2 hours to get this slow solution (timed out test 2)
/*
int solve() {
    //queues (must push 0 to prevent seg fault)
    priority_queue<int> even; even.push(0);
    priority_queue<int> odd; odd.push(0);
    
    //inputs
    int n; cin >> n;
    
    while (n--) {
        int v; cin >> v;
        if (v % 2 == 0) {
            even.push(v);
        } else {
            odd.push(v);
        }
    }
    
    while (even.top() && odd.top()) {
        int e = even.top(); even.pop();
        int o = odd.top(); odd.pop();
        
        int diff = max(min(e, o) - min(even.top(), odd.top()), 1);
        
        if (e > o) {
            e += diff;
            o -= diff;
        } else {
            o += diff;
            e -= diff;
        }
        
        if (e % 2 == 0) {
            even.push(e);
            odd.push(o);
        } else {
            even.push(o);
            odd.push(e);
        }
    }
    
    return max(even.top(), odd.top());
}
*/