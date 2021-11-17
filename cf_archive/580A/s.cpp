#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int c = 1, best = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] >= a[i - 1])
                c++;
            else
                c = 1;
            best = max(c, best);
        }
        cout << best << "\n";
    }
    return 0;
}
