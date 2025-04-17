#include <bits/stdc++.h>
using namespace std;

map<char, int> cti = {
    {'W', 0}, {'G', 1}, {'B', 2}
};

int main() {
    //fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int output[T] = {0};

    for (int t = 0; t < T; t++) {
        //get params
        int N, A, B;
        cin >> N >> A >> B;

        //fill the array
        int arr[N][N];
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                char c;
                cin >> c;
                arr[y][x] = cti[c];
            }
        }

        bool done = false;

        //see if invalid
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                int curr = arr[y][x];
                int prev = arr[y-B][x-A];
                int next = arr[y+B][x+A];

                //input 3: does not move
                if (A == 0 && B == 0) {
                    //invalid arrangement
                    if (curr == 1) {
                        output[t] = -1;
                        done = true;
                        break;
                    }

                    //counter for when it is valid
                    if (curr == 2) {
                        output[t]++;
                    }
                }
                
                //inputs 4-9: right one unit
                else if (A == 1 && B == 0) {
                    if (x-A < 0) {

                    }
                    if (x+A >= N) {
                        
                    }

                    if ( //invalid arguments
                        (prev >= 1) && (curr < 1)
                        ||
                        (prev >= 1 && next >= 1) && (curr != 2)
                    ) {
                        output[t] = -1;
                        done = true;
                        break;
                    }

                    //valid
                    if (prev >= 1 && curr >= 1) {
                        output[t]++;
                    }
                }

                //this code works for samples but idk how
                else {
                    if (curr == 2) { //coord is 2
                        if ( //not valid
                            (x-A >= 0 && y-B >= 0) && (prev == 0)
                            ||
                            (x+A < N && y+B < N) && (next == 0)
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
                            !((x+A < N && y+B < N) && (next == 0))
                        ) {
                            output[t]++;
                        }
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
