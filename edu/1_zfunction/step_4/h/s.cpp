#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int m = s.length();
    string t = "";
    long long total = 0;
    for (int j = m - 1; j >= 0; j--) {
        t = s[j] + t;
        int n = m - j;
        vector<int> z(n, 0);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (r >= i)
                z[i] = min(z[i - l], r - i + 1);
            while (i + z[i] < n && t[z[i]] == t[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        int k = *max_element(z.begin(), z.end());
        for (int i = k; i < n; i++)
            total += i + 1;
    }
    cout << total << '\n';
    return 0;
}
