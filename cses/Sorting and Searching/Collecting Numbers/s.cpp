#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        b[v] = i;
    }
    int total = 1;
    for (int i = 1; i < n; i++)
        if (b[i + 1] < b[i])
            total += 1;
    cout << total << '\n';
    return 0;
}
