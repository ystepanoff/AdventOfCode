#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string n;
    cin >> n;
    int m = 0;
    for (int i = 0; i < n.length(); i++)
        m = (m * 10 + n[i] - '0') % 3;
    if (m) {
        cout << "1\n" << m << "\n";
    } else {
        cout << "2\n";
    }
    return 0;
}
