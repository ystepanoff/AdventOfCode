#include <bits/stdc++.h>
using namespace std;

long long ask_sum(int i, int j) {
    long long a, o;
    cout << "and " << i << ' ' << j << '\n';
    cout.flush();
    cin >> a;
    cout << "or " << i << ' ' << j << '\n';
    cout.flush();
    cin >> o;
    return a + o;
}

int main() {
    int n, k;
    cin >> n >> k;
    long long x1 = ask_sum(1, 2);
    long long x2 = ask_sum(2, 3);
    long long x3 = ask_sum(1, 3);
    vector<long long> a(n);
    a[0] = (x1 - x2 + x3) / 2;
    a[1] = (x1 + x2 - x3) / 2;
    a[2] = (-x1 + x2 + x3) / 2;
    for (int i = 3; i < n; i++) {
        long long x = ask_sum(i, i + 1);
        a[i] = x - a[i - 1];
    }
    sort(a.begin(), a.end());
    cout << "finish " << a[k - 1] << '\n';
    cout.flush();
    return 0;
}
