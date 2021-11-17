#include <bits/stdc++.h>
using namespace std;

string A(int n) {
    string r = "sin(" + to_string(n) + ")";
    for (int i = n - 1; i >= 1; i--) {
        char sign = (i & 1) ? '-' : '+';
        r = "sin(" + to_string(i) + sign + r + ")";
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    /**
     * a(1) = sin(1)
     * a(2) = sin(1-sin(2))
     * a(3) = sin(1-sin(2+sin(3)))
     *
     * s(1) = sin(1)+1
     * s(2) = (sin(1)+2)sin(1-sin(2))+1
     * s(3) = ((sin(1)+3)sin(1-sin(2))+2)sin(1-sin(2+sin(3)))+1
    */
    int n;
    cin >> n;
    vector<string> a = { "" };
    for (int i = 1; i <= n; i++)
        a.push_back(A(i));
    string s = "";
    for (int i = 1; i <= n; i++) {
        s += a[i] + '+' + to_string(n - i + 1);
        if (i < n)
            s = '(' + s + ')';
    }
    cout << s << '\n';
    return 0;
}
