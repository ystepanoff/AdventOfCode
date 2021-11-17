#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x = 0;
    for (int i = 1; i < n; i++)
        x ^= i;
    cout << x << '\n';
    return 0;
}
