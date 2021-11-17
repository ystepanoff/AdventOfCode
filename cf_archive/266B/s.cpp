#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    string s;
    while (cin >> n >> t >> s) {
        while (t--) {
            string s_new = s;
            for (int i = 0; i < n - 1; i++)
                if (s[i] == 'B' && s[i + 1] == 'G') {
                    s_new[i] = 'G';
                    s_new[i + 1] = 'B';
                    i++;
                } else {
                    s_new[i] = s[i];
                }
            s = s_new;
        }
        cout << s << '\n';
    }
    return 0;
}
