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
        int n;
        cin >> n;

        int output = 0;
        int digits = int(log10(n)) + 1;
        int min = int(pow(10, digits) * double(4)/9) + 1; //like 4445
        int max = 5 * pow(10, digits-1) - 1; //like 4999

        for (int i = 2; i < digits; i++) {
            output += int(pow(10, i-1) * double(5)/9); //like 5555
        }

        if (n >= max) {
            output += max-min+1;
        } else if (n >= min) {
            output += n-min+1;
        }

        cout << output << "\n";
    }

	return 0;
}
