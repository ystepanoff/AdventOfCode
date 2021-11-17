#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++) {
        a += n % 10;
        n /= 10;
    }
    for (int i = 0; i < 3; i++) {
        b += n % 10;
        n /= 10;
    }
    return a == b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (check(n - 1) || check(n + 1) ? "Yes" : "No") << '\n';
    return 0;
}
