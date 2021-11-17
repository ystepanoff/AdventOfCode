#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s = "", t;
    while (getline(cin, t))
        s += t;
    t = "";
    for (int i = 0; i < 80; i++)
        t += ' ';
    int j = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '<') {
            j--;
            if (j < 0)
                j = 0;
        } else if (s[i] == '>') {
            j++;
            if (j >= 80)
                j = 0;
        } else {
            t[j++] = s[i];
            if (j >= 80)
                j = 0;
        }
    cout << t << '\n';

    return 0;
}
