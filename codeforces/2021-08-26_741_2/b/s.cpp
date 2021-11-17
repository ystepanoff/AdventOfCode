#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    for (int c = 2; c * c <= n; c++)
        if (!(n % c))
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s; 
        cin >> s;
        string r = "";
        for (int i = 0; i < n; i++) {
            if (!is_prime(s[i] - '0') || s[i] == '1')
                r = string({s[i]});
        }
        if (!r.compare("")) {
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++) 
                    if (!is_prime((s[i] - '0') * 10 + (s[j] - '0')))
                        r = string({s[i], s[j]});
        }
        if (!r.compare("")) {
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++) 
                    for (int k = j + 1; k < n; k++)
                        if (!is_prime((s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0')))
                            r = string({s[i], s[j], s[k]});
        }
        if (!r.compare("")) {
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    for (int k = j + 1; k < n; k++)
                        for (int l = k + 1; k < n; k++)
                            if (!is_prime((s[i] - '0') * 1000 + (s[j] - '0') * 100 + (s[k] - '0') * 10 + (s[l] - '0')))
                                r = string({s[i], s[j], s[k]});
        }
        cout << r.length() << '\n' << r << '\n';
    }
    return 0;
}
