#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<int,bool> seen[3];
    set<int> all;
    for (int t = 0; t < 3; t++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            seen[t][v] = true;
            all.insert(v);
        }
    }
    int total = 0;
    for (int x : all) {
        if (seen[0][x] && seen[1][x] && seen[2][x]) total++;
    }
    cout << total << '\n';
    return 0;
}
