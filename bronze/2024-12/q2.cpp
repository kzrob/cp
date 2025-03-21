#include <bits/stdc++.h>
using namespace std;

int main() {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// INPUT
	int N, Q;
	cin >> N >> Q;

    //i hate this syntax
	vector<vector<vector<int>>> arr(
        3, vector<vector<int>>(
            N, vector<int>(N, N)
        )
    );

    int count = 0;

	//for each removal
	while (Q --> 0) {
		int x, y, z;
		cin >> x >> y >> z;

        //remove cheese blocks
		if (--arr[0][x][y] == 0) {
            count++;
        }
		if (--arr[1][y][z] == 0) {
            count++;
        }
		if (--arr[2][x][z] == 0) {
            count++;
        }

		cout << count << "\n";
	}

	return 0;
}
