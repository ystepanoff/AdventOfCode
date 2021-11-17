#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> g;
    string t = "";
    for (char c = 'a'; c <= 'z'; c++) {
        t = t + string({ c }) + t;
        g.push_back(t);
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int k, j;
        cin >> k >> j;
        k--;
        int z = 0;
        if (j > 0) {
            while (j + z < g[k].length() && g[k][j + z] == g[k][z])
                z++;
        }
        cout << z << '\n';
    }
    return 0;
}
