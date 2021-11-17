#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    long long total = (long long)n * ((long long)n + 1) / 2;
    vector<vector<long long>> lcp(n + 1, vector<long long>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--) {
            if (i == j)
                lcp[i][j] = n - i;
            else if (s[i] == s[j]) 
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            total -= lcp[i][j];
        }
    cout << total << '\n';
    return 0;
}
