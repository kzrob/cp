#include <bits/stdc++.h>
using namespace std;

typedef long long big;

int main() {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//declare the array
	big N;
	cin >> N;
	big arr[N];

	//trackers
	unordered_map<big, big> contains = {};
	unordered_map<big, big> indexes = {};
	unordered_set<big> solutions;
	int output = 0;

	//fill the array
	for (big i=0; i<N; ++i) {
		big v;
		cin >> v;
		arr[i] = v;
	}

	//loop backwards
	for (big i=N-1; i>=0; --i) {
		big v = arr[i];
		if (contains[v] == 1) {
			indexes[v] = i;
		}
		contains[v]++;
	}

	for (const auto& [moo, index] : indexes) {
		for (big i=0; i<=index; ++i) {
			if (i == index) {
			  output += solutions.size();
			  solutions = {};
			  continue;
			}
			
			big v = arr[i];
			if (v == moo) {continue;}
			solutions.insert(v);
		}
	}

	cout << output;

	return 0;
}
