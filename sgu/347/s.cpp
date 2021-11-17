#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            string s = a[i] + a[j];
            string t = a[j] + a[i];
            if (t.compare(s) < 0)
                swap(a[i], a[j]);
        }
    for (string s : a)
        cout << s;
    cout << '\n';
    return 0;
}
