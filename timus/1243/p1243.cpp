#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = 0;
    for (int i = 0; i < s.size(); i++)
        n = (n * 10 + s[i] - '0') % 7;
    cout << n << '\n';
    return 0;
}
