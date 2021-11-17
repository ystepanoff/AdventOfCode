#include <bits/stdc++.h>
using namespace std;

int b2i(vector<string> &board) {
    int r = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            r <<= 1;
            if (board[i][j] == 'W')
                r += 1;
        }
    return r;
}

vector<string> i2b(int board) {
    vector<string> r(4);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            r[i] += 'B';
    for (int i = 0; i < 16; i++)
        if (board & (1 << i))
            r[3 - (i / 4)][3 - (i % 4)] = 'W';
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> board(4), mask(3);
    for (int i = 0; i < 4; i++)
        cin >> board[i];
    for (int i = 0; i < 3; i++)
        cin >> mask[i];
    vector<bool> visited(1 << 16, false);
    vector<int> d(1 << 16, 0);
    vector<int> q;
    int pos = b2i(board);
    q.push_back(pos);
    visited[pos] = true;
    for (int k = 0; k < q.size(); k++)
        for (int x = 0; x < 4; x++)
            for (int y = 0; y < 4; y++) {
                board = i2b(q[k]);
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        if (mask[i][j] == '1') {
                            int xx = x + i - 1, yy = y + j - 1;
                            if (xx >= 0 && yy >= 0 && xx < 4 && yy < 4)
                                board[xx][yy] = board[xx][yy] == 'W' ? 'B' : 'W';
                        }
                pos = b2i(board);
                if (!visited[pos]) {
                    q.push_back(pos);
                    visited[pos] = true;
                    d[pos] = d[q[k]] + 1;
                }
            }
    if (visited[0] || visited[(1<<16)-1]) {
        int best = -1;
        if (visited[(1<<16)-1])
            best = d[(1<<16)-1];
        if (visited[0] && (best == -1 || d[0] < best))
            best = d[0];
        cout << best << '\n';
    } else {
        cout << "Impossible\n";
    }
    return 0;
}
