#include <bits/stdc++.h>
using namespace std;

int median(int a, int b, int c) {
    return a + b + c - max(max(a, b), c) - min(min(a, b), c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = median(x, y, z);
    }
    cout << median(a[0], a[1], a[2]) << '\n';
    return 0;
}
