#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> dx = { 1, 2, 2, 1, -1, -2, -2, -1 };
    vector<int> dy = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int c = 0;
        for (int i = 0; i < 8; i++) {
            int x = s[0] - 'a' + dx[i];
            int y = s[1] - '1' + dy[i];
            if (x >= 0 && x < 8 && y >= 0 && y < 8)
                c++;
        }
        cout << c << '\n';
    }
    return 0;
}
