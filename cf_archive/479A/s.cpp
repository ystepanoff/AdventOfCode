#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    while (cin >> a >> b >> c) {
        vector<int> p = {
            a + b + c,
            a * b + c,
            a * (b + c),
            a + b * c,
            (a + b) * c,
            a * b * c
        };
        cout << *max_element(p.begin(), p.end()) << '\n';
    }
    return 0;
}
