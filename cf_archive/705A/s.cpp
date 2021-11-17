#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        string s;
        for (int i = 1; i <= n; i++) {
            if (i & 1)
                s += "I hate ";
            else
                s += "I love ";
            if (i < n)
                s += "that ";
        }
        s += "it";
        cout << s << '\n';
    }
    return 0;
}
