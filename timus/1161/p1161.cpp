#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    double result = a[0];
    for (int i = 1; i < n; i++)
        result = 2 * sqrt(result * a[i]);
    cout << fixed << setprecision(2);
    cout << result << '\n';
    return 0;
}
