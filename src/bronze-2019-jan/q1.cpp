#include <bits/stdc++.h>
using namespace std;

void swap(int (&cups)[3], int a, int b) {
    int temp = cups[a];
    cups[a] = cups[b];
    cups[b] = temp;
}

int main() {
    //fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);

    int cups[3] = {0, 1, 2};
    int count[3] {};

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        swap(cups, a-1, b-1);
        
        count[cups[g-1]] += 1;
    }

    int max = count[0];
    for (int i=0; i<3; i++) {
        if (count[i] > max) {
            max = count[i];
        }
    }

    cout << max;
    
    return 0;
}