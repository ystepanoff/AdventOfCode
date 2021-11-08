#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < 10; i++) {
        int v;
        cin >> v;
        b -= v * 20;
    }
    if (b >= a) {
        cout << "No chance.\n";
    } else {
        cout << "Dirty debug :(\n";
    }
    return 0;
}
