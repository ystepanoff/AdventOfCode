#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s; 
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (r >= i)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    vector<int> b;
    for (int i = 0; i < n; i++)
        if (i + z[i] >= n)
            b.push_back(i);
    b.push_back(n);
    for (int x : b)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
