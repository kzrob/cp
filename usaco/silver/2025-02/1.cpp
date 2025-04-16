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

		vector<string> cows(N);
		vector<string> sorted(N);

		for (int i = 0; i < N; i++) {
			cin >> cows[i];
			cin >> sorted[i];
		}

		sort(sorted.begin(), sorted.end(), greater<string>());
		


	}

	return 0;
}
