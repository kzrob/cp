#include <bits/stdc++.h>
using namespace std;

int main() {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//test cases
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<int> cows(0, N);
		set<int> counter;
		set<int> pairs;
		int highest = 0;

		for (int i = 0; i < N; i++) {
			int v;
			cin >> v;
			cows[i] == v;
			
			highest = max(highest, v);
			if (counter.count(v)) {
				pairs.insert(v);
			}
			counter.insert(v);
		}

		pairs.erase(highest);
		cout << 1 + 2 * pairs.size() << "\n";
	}

	return 0;
}
