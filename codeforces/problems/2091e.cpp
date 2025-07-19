/* https://codeforces.com/problemset/problem/2091/E
 * Thu, April 17, 2024
 * editorial solution in 1:30 hrs
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}

vector<bool> is_prime = sieve_of_eratosthenes(10000000);

int solve() {
    int n; cin >> n;
    int out = 0;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            out += n/i;
        }
    }

    return out;
}

int main() {
    //fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //constraints
    int T; cin >> T;

    while (T--) {
        cout << solve() << "\n";
    }

    return 0;
}

// took 1 hour with hints to get this slow solution (timed out test 3)
/*
int solve() {
    int out = 0;
    int a = 1;
    int b = 2;
    int n; cin >> n;
    set<int> primes;

    auto increment = [&]() {
        if (b < n) {
            b++;
        } else {
            //cout << "here?\n";
            a++;
            b = a+1;
            primes.clear();
        }
    };

    while (a < b && b <= n) {
        //cout << a << ", " << b << "\n";
        if (!primes.empty()) {
            int broken = false;
            for (auto p : primes) {
                if (b % p == 0) {
                    increment();
                    broken = true;
                    break;
                }
            }
            if (broken) {
                continue;
            }
        }
        if (b % a == 0) {
            out++;
            primes.insert(b);
        }
        increment();
    }

    return out;
}
*/