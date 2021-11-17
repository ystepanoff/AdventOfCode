#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // n * m - 1 cuts, so interested in the parity of n * m
    if ((n * m - 1) & 1) {
        cout << "[:=[first]";
    } else {
        cout << "[second]=:]";
    }
    return 0;
}
