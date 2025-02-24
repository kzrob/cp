#include <bits/stdc++.h>
using namespace std;

int main() {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    //input the constraints
    int N, U;
    cin >> N >> U;

    //input the grid
    //true = #, false = .
    vector<vector<bool>> grid(N, vector<bool>(N, 0));
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            char c;
            cin >> c;
            grid[y][x] = (c == '#');
        }
    }

    //lambada function to count hashtags and dots
    auto countMin = [&](int x, int y) {
        int hash = 0;
        int dot = 0;

        //q1
        if (grid[y][x])
        { hash++; } else { dot++; }

        //q2
        if (grid[y][N-1-x])
        { hash++; } else { dot++; }
            
        //q3
        if (grid[N-1-y][N-1-x])
        { hash++; } else { dot++; }

        //q4
        if (grid[N-1-y][x])
        { hash++; } else { dot++; }

        return min(hash, dot);
	};

    //initial changes
    int changes = 0;
    for (int y = 0; y < N/2; y++) {
        for (int x = N/2; x < N; x++) {
            changes += countMin(x, y);
        }
    }
    cout << changes << "\n";
    
    //new changes
    while (U --> 0) {
        int y, x;
        cin >> y >> x;
        y--; x--; //remove the one index

        //old counts
        changes -= countMin(x, y);

        //new counts
        grid[y][x] = !grid[y][x];
        changes += countMin(x, y);
        
        cout << changes << "\n";
    }
}