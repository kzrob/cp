#include <bits/stdc++.h>
using namespace std;

typedef long long big;

int main() {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//test cases
	big N, Q;
	cin >> N >> Q;

	string s;
	cin >> s;
	
	while (Q--) {
		big l, r;
		cin >> l >> r;
        l--; r--; //remove one index
        
        //cout << l << " " << r << ": " << s.substr(l, r-l+1) << "\n";
        
        big i = l;
        big j = r;
        big minLenI = 0;
		while (s[i] == s[j]) {
			i++;
            minLenI++;
		}

        big minLenJ = 0;
        i=l;
        j=r;
        while (s[i] == s[j]) {
            j--;
            minLenJ++;
        }

        //cout << minLenI << " " << minLenJ << "\n";
        
        if (minLenI == minLenJ) {
            big mid = (l+r)/2;
            if (s[mid] == s[r]) {
                l += minLenI;
            } else {
                r -= minLenJ;
            }
        } else if (minLenI < minLenJ) {
            l += minLenI;
        } else {
            r -= minLenJ;
        }

		big pivot = -1;

		while (pivot < 0 && r-l+1 >= 3) {
			big m = r-1;
			big minDist = N;

			while (m > l) {
                //cout << "(" << l << ", " << r << ") | "
                //<< pivot << " | "
                //<< minDist << " | "
                //<< m << ": " << s[m] << " " << s[r] << "\n";
				if (s[m] == s[r]) {
					big diff = abs((r+l)/2 - m);
					if (diff < minDist) {
						minDist = diff;
						pivot = m;
					}
				}
				m--;
			}

			if (pivot == -1) {
				char prev = s[r];
				do {
					r--;
                    //cout << pivot << " | " << prev << " | (" << l << ", " << r << ")\n";
				} while (s[r] == s[l]);
			}
            //cout << pivot << " | (" << l << ", " << r << ")\n";
		}

        if (pivot < 0) {
            cout << pivot << "\n";
        } else {
		    cout << (pivot-l)*(r-pivot) << "\n";
        }
	}

	return 0;
}
