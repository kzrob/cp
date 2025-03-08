//updated March 8, 2025: Passes all test cases, though may not be the most optimal solution

#include <bits/stdc++.h>
using namespace std;

typedef long long big;

int main() {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//input
	big N;
	cin >> N;
	big arr[N];

    big prefix[N]; //number of unique chars before i that are not arr[i]
	set<big> uniques;

	//fill the array and prefix sum
	for (big i = 0; i < N; i++) {
		cin >> arr[i];

        uniques.erase(arr[i]); //do not want to include N
        prefix[i] = uniques.size();
        uniques.insert(arr[i]); //add N back for next iteration
	}

    //fill the maps and output
	big output = 0;
	map<big, int> contains = {};

	//loop backwards and get the moos
	for (big i = N-1; i >= 0; i--) {
		if (contains[arr[i]] == 1) {
			output += prefix[i];
		}
		contains[arr[i]]++;
	}

	cout << output;

	return 0;
}
