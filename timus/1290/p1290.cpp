#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> &a) {
    vector<int> b = { (int)a.size() };
    sort(a.begin(), a.end());
    for (int i = 1; ; i++) {
        int k = a.end() - upper_bound(a.begin(), a.end(), i);
        if (k == 0)
            break;
        b.push_back(k);
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 0) {
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b = f(a);
    a = f(b);
    for (int x : a)
        cout << x << '\n';
    cout << '\n';
    return 0;
}
