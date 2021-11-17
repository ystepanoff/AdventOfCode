#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int total = 0;
    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1])
            total++;
    cout << total << '\n';
    return 0;
}
