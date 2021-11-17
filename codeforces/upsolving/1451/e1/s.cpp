#include <bits/stdc++.h>
using namespace std;

int ask(string s, int i, int j) {
    cout << s << " " << i << ' ' << j << '\n';
    cout.flush();
    int r;
    cin >> r;
    return r;
}

int main() {
    int n;
    cin >> n;
    int xor12 = ask("XOR", 1, 2);
    int xor23 = ask("XOR", 2, 3);
    int xor13 = xor12 ^ xor23;
    int and12 = ask("AND", 1, 2);
    int and23 = ask("AND", 2, 3);
    int and13 = ask("AND", 1, 3);
    int x1 = xor12 + 2 * and12;
    int x2 = xor23 + 2 * and23;
    int x3 = xor13 + 2 * and13;
    vector<int> a(n);
    a[0] = (x1 - x2 + x3) >> 1;
    a[1] = (x1 + x2 - x3) >> 1;
    a[2] = (-x1 + x2 + x3) >> 1;
    for (int i = 3; i < n; i++) {
        int x = ask("XOR", i, i + 1);
        a[i] = a[i - 1] ^ x;
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';
    cout.flush();
    return 0;
}
