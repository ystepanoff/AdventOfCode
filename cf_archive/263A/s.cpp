#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++) {
            int v;
            cin >> v;
            if (v == 1)
                cout << abs(i - 3) + abs(j - 3) << '\n';
        }
    return 0;
}
