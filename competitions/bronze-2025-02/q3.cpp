#include <bits/stdc++.h>
using namespace std;

int main() {
    //fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //input the constraints
    int T;
    cin >> T;

    //for each test case
    while (T --> 0) {
        //input constraints
        int N, K;
        cin >> N >> K;

        //constants
        const vector<int> zeroVector(K, 0);

        //trackers
        int lastNum = 0;
        set<int> uniques;
        int currentIndex = 0;
        vector<vector<int>> counts(N/K+1, vector<int>(K, 0));
        
        while (N --> 0) {
            int v; cin >> v;
            
            if (uniques.size() >= K && v != lastNum && uniques.count(v)) {
                currentIndex++;
                uniques.clear();
            }

            counts[currentIndex][v-1]++;
            uniques.insert(v);
            lastNum = v;
        }

        //compare all the vectors
        bool yes = true;
        for (int i = 1; i < counts.size(); i++) {
            if (counts[i-1] == zeroVector || counts[i] == zeroVector) {
                continue;
            }

            if (counts[i-1] != counts[i]) {
                yes = false;
                break;
            }
        }

        //output
        if (yes) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}