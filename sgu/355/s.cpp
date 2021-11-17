#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (i % j == 0)
                a[i] = a[j] + 1;
    unordered_map<int,bool> checked;
    int total = 0;
    for (int i = 1; i <= n; i++)
        if (!checked[a[i]]) {
            total++;
            checked[a[i]] = true;
        }
    cout << total << '\n';
    for (int i = 1; i <= n; i++) {
        cout << a[i] + 1;
        if (i < n)
            cout << ' ';
    }
    cout << '\n';
    return 0;
}
