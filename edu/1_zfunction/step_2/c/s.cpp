#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> z(n);
        string s = "";
        for (int i = 0; i < n; i++) {
            cin >> z[i];
            s += alpha[i];
        }
        for (int i = 1; i < n; i++)
            if (z[i] > 0)
                for (int j = 0; j < z[i]; j++)
                    if (i + j < n)
                        s[i + j] = s[j];
        vector<int> t(n, 0);
        for (int i = 1; i < n; i++)
            while (i + t[i] < n && s[i + t[i]] == s[t[i]])
                t[i]++;
        bool match = true;
        for (int i = 0; i < n; i++)
            match &= t[i] == z[i];
        cout << (match ? s : "!") << '\n';
    }
    return 0;
}

/*
 * 0 0 1 0 3 0 1 0 7 0 1 0 3 0 1
 * a b c d e f g h i j k l m n o
 * a b a d a b a h a b a d a b a
 */
