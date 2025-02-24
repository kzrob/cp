#include <bits/stdc++.h>
using namespace std;

int main() {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//set the arrays
	int N;
	cin >> N;
	int orig[N];
	for (int i=0; i<N; ++i) {
		int v;
		cin >> v;
		orig[i] = v;
	}
	int check[N];
	for (int i=0; i<N; ++i) {
		int v;
		cin >> v;
		check[i] = v;
	}

	int output[N+1] = {0};

	//lambada
	auto checkArr = [&](int* arr) {
		int count = 0;
		for (int i=0; i<N; ++i) {
			if (arr[i] == check[i]) {
				++count;
			}
		}
		return count;
	};

	//logic
	for (int l=0; l<N; ++l) {
		for (int r=l; r<N; ++r) {
			int t[N];
			copy(orig, orig + N, t);

			//reverse
			int a = l;
			int b = r;

			while (a < b) {
				int temp = t[a];
				t[a] = t[b];
				t[b] = temp;

				++a;
				--b;
			}
			
			int count = checkArr(t);
			output[count]++;
		}
	}


	//output
	for (int v : output) {
		cout << v << "\n";
	}

	return 0;
}