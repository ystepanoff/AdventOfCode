#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - 'a';
    }
    for (int i = 1; i < n; i++) {
        b[i] = (a[i] - a[i - 1] + 26) % 26;
    }
    b[0] = (a[0] + 21) % 26;
    for (int i = 0; i < n; i++) {
        cout << (char)(b[i] + 'a');
    }
    cout << '\n';
    return 0;
}
