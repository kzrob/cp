// https://calicojudge.com/team/problems/815/statement

#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N, M; cin >> N >> M; //dimensions of the board
    int K; cin >> K; //number of pieces

    vector<char> types(K);
    vector<pair<int, int>> positions(K);

    int count = 0;

    for (int i = 0; i < K; i++) {
        char type; cin >> type; //type of piece
        int x, y; cin >> x >> y; //positions of the pieces
        types[i] = type;
        positions[i] = {x, y};
    }

    for (int i = 0; i < K; i++) {
        char type = types[i];
        int x = positions[i].first;
        int y = positions[i].second;

        bitset<4> TRBL; //top, right, bottom, left
        bitset<4> dTRBL; //diagonal top-right, bottom-right, bottom-left, top-left

        for (int j = 0; j < K; j++) {
            if (i == j) continue; //skip self
            char otherType = types[j];
            int otherX = positions[j].first;
            int otherY = positions[j].second;

            //check if capture
            if (type == 'R' || type == 'Q') { // horizontal or vertical
                if (x == otherX || y == otherY) {
                    // cout << type << "(" << x << "," << y << ")->" << otherType << "(" << otherX << "," << otherY << ")  ";
                    if (y < otherY) TRBL.set(0, 1); //top
                    else if (x < otherX) TRBL.set(1, 1); //right
                    else if (y > otherY) TRBL.set(2, 1); //bottom
                    else if (x > otherX) TRBL.set(3, 1); //left
                }
            }
            if (type == 'B' || type == 'Q') { // diagonal
                if (abs(x - otherX) == abs(y - otherY)) {
                    // cout << type << "(" << x << "," << y << ")->" << otherType << "(" << otherX << "," << otherY << ")  ";
                    if (x < otherX && y < otherY) dTRBL.set(0, 1); //top right
                    else if (x < otherX && y > otherY) dTRBL.set(1, 1); //bottom right
                    else if (x > otherX && y > otherY) dTRBL.set(2, 1); //bottom left
                    else if (x > otherX && y < otherY) dTRBL.set(3, 1); //top left
                }
            }
        }

        // cout << TRBL << " " << dTRBL << "\n";
        count += TRBL.count() + dTRBL.count();
    }
    return count;
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
