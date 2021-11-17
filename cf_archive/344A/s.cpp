#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<string> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        int r = 1;
        for (int i = 1; i < n; i++)
            if (s[i - 1][1] == s[i][0])
                r++;
        cout << r << '\n';
    }
    return 0;
}
