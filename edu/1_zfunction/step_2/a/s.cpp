#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<int> z(n, 0);
    for (int i = 1; i < n; i++)
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
    for (int i = 0; i < n; i++) {
        cout << z[i];
        if (i < n - 1)
            cout << ' ';
    }
    cout << '\n';
    return 0;
}
