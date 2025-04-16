#include <bits/stdc++.h>
using namespace std;

int main() {
    //fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //input the constraints
    int N;
    cin >> N;

    //input the array & count
    vector<int> arr(N, 0);
    vector<int> count(N+1, 0);
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        arr[i] = v;
        count[v]++;
    }

    //prefix sum
    vector<int> prefix(N+1, 0);
    int zeroes = 0;
    for (int i = 0; i < N; i++) {
        if (count[i] == 0) {
            zeroes++;
        }
        prefix[i+1] = zeroes;
    }
    
    //calculate mex
    for (int i = 0; i <= N; i++) { //for each mex value
        int ops = prefix[i];
        if (count[i] > 0 && ops < count[i]) {
            ops = count[i];
        }
        cout << ops << "\n";
    }
}