#include <bits/stdc++.h>
using namespace std;

bool good(int n) {
    for (; n > 0; n /= 10)
        if (n % 10 != 4 && n % 10 != 7)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        bool y = false;
        for (int i = 4; i <= n; i++)
            if (!(n % i) && good(i))
                y = true;
        cout << (y ? "YES" : "NO") << '\n';
    }
    return 0;
}
