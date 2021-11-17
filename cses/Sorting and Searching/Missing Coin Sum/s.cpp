#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long s = 0;
    for (int x : a) {
        if (x > s + 1)
            break;
        s += x;
    }
    cout << s + 1 << '\n';
    return 0;
}
