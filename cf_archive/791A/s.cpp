#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    while (cin >> a >> b) {
        int k = 0;
        while (a <= b) {
            a *= 3;
            b *= 2;
            k++;
        }
        cout << k << '\n';
    }
    return 0;
}
