/* https://codeforces.com/problemset/problem/2092/C
 * took like under 2 hours to get this slow solution (timed out test 2)
*/

#include <bits/stdc++.h>
using namespace std;

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
