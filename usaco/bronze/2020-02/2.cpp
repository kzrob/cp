#include <bits/stdc++.h>
using namespace std;

int main() {
    //io
    freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);

    //input
    int N;
    cin >> N;

    string goal;
    string test;
    cin >> goal >> test;

    int count = 0;
    bool prev = true;
    for (int i=0; i<N; i++) {
        if (goal[i] != test[i] && prev == true) {
            count++;
        }
        prev = goal[i] == test[i];
    }

    cout << count;
}