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
    int mean = accumulate(a.begin(), a.end(), 0) / n;
    int median = a[n / 2];
    if (!(n & 1))
        median = (a[n / 2] + a[(n / 2) - 1]) / 2;
    vector<int> cnt(1010, 0);
    for (int x : a)
        cnt[x]++;
    int mode = a[1];
    int mc = *max_element(cnt.begin(), cnt.end());
    for (int i = 1000; i >= 1; i--)
        if (cnt[i] == mc) {
            mode = i;
            break;
        }
    cout << mean << '\n' << median << '\n' << mode << '\n';
    return 0;
}
