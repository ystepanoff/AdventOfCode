#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a;
    while (n > 1) {
        if (n & 1) {
            a.push_back(n >> 1);
            n = n - (n >> 1);
        } else {
            a.push_back(n >> 1);
            n >>= 1;
        }
    }
    cout << a.size() << '\n';
    for (int x : a)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
