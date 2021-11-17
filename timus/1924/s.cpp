#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << ((n * (n + 1) / 2) & 1 ? "grimy" : "black") << '\n';
    return 0;
}
