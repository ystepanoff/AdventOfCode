#include <bits/stdc++.h>
using namespace std;

bool vowel(char a) {
    return a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U';
}

int cost(char a, char b) {
    return vowel(a) != vowel(b) ? 1 : 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int _t = 1; _t <= tt; _t++) {
        string s;
        cin >> s;
        int n = s.length();
        int best = n << 2;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            int curr = 0;
            for (int i = 0; i < n; i++)
                if (s[i] != ch)
                    curr += cost(s[i], ch);
            best = min(best, curr);
        }
        cout << "Case #" << _t << ": " << best << '\n';
    }
    return 0;
}
