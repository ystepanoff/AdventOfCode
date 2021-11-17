#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string n;
        int k;
        cin >> n >> k;
        int m = n.length();
        while (true) {
            set<char> s;
            for (int i = 0; i < m; i++) {
                s.insert(n[i]);
                if (s.size() > k) {
                    while (i > 0 && n[i] == '9')
                        i--;
                    n[i]++;
                    for (int j = i + 1; j < m; j++)
                        n[j] = '0';
                break;
            }
        }
        cout << n << '\n';
    }
    return 0;
}
