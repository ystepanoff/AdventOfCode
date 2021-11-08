#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<int> cnt(1000, 0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        cnt[v]++;
    }
    int total = 0;
    for (int x : cnt)
        total += x >> 2;
    cout << total << '\n';
    return 0;
}
