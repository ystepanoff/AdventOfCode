#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    double s = accumulate(a.begin(), a.end(), 0);
    s -= *min_element(a.begin(), a.end());
    cout << fixed << setprecision(1) << (int)((s / (n - 1)) * 10) * 0.1 << '\n';
    return 0;
}
