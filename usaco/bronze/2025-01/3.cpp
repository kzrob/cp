#include <bits/stdc++.h>
using namespace std;

int main() {
    //fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //inputs
    int N;
    cin >> N;

    vector<int> orig(N);
    for (int &i : orig) {
        cin >> i;
    }

    vector<int> check(N);
    for (int &i : check) {
        cin >> i;
    }

    vector<int> output(N+1, 0);

    //lambada
    auto checkDiff = [&](vector<int> arr) {
        int count = 0;
        for (int i=0; i<N; i++) {
            if (arr[i] == check[i]) {
                count++;
            }
        }
        output[count]++;
    };

    //logic
    for (int l=0; l<N; l++) {
        for (int r=l; r<N; r++) {
            vector<int> test = orig;
            reverse(test.begin() + l, test.begin() + r+1);
            checkDiff(test);
        }
    }

    //output
    for (int v : output) {
        cout << v << "\n";
    }

    return 0;
}