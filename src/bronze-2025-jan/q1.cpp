#include <bits/stdc++.h>
using namespace std;

int main() {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	int output[T] = {0};


	for (int t=0; t<T; ++t) {
		//get params
		int N, A, B;
		cin >> N >> A >> B;
		int arr[N][N];

		//fill the array
		for (int y=0; y<N; ++y) {
			for (int x=0; x<N; ++x) {
				char c;
				cin >> c;

				if (c == 'W') {
					arr[y][x] = 0;
				}
				if (c == 'G') {
					arr[y][x] = 1;
				}
				if (c == 'B') {
					arr[y][x] = 2;
				}
			}
		}

		bool done = false;

		//see if invalid
		for (int y=0; y<N; ++y) {
			for (int x=0; x<N; ++x) {
				if (arr[y][x] == 2) { //coord is 2
					if ( //not valid
						(x-A >= 0 && y-B >= 0) && (arr[y-B][x-A] == 0)
						||
						(x+A < N && y+B < N) && (arr[y+B][x+A] == 0)
					) {
						done = true;
						output[t] = -1;
						break;
					}
					else { //is valid
						output[t]++;
					}
				}
				
				if (arr[y][x] == 1) { //coord is 1
					if ( //didn't move to 0
						!((x+A < N && y+B < N) && (arr[y+B][x+A] == 0))
					) {
						output[t]++;
					}
				}
			}
			if (done) {break;}
		}
	}

	for (int v : output) {
		cout << v << "\n";
	}

	return 0;
}