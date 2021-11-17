#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s = "", t;
    while (cin >> t)
        s += t;
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '>')
            b++;
        else if (s[i] == '<')
            a += b;
    cout << a << '\n';
    return 0;
}
