#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    while (cin >> n >> s) {
        int a = 0, d = 0;
        for (char c : s)
            if (c == 'A')
                a++;
            else
                d++;
        cout << (a > d ? "Anton" : a < d ? "Danik" : "Friendship") << '\n';
    }
    return 0;
}
