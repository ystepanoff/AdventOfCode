#include <bits/stdc++.h>
using namespace std;

string alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s = "", t;
    while (cin >> t)
        s += t + '*';
    int n = s.length();
    int bestk = 0, bestc = 0;
    for (int k = 2; k <= 36; k++) {
        string alpha_k = alpha.substr(0, k);
        string w = "";
        int c = 0;
        for (int i = 0; i < n; i++)
            if (find(alpha_k.begin(), alpha_k.end(), s[i]) != alpha_k.end()) {
                w += s[i];
            } else {
                if (w.length() > 0) {
                    c++;
                    w = "";
                }
            }
        if (bestk == 0 || c > bestc) {
            bestk = k;
            bestc = c;
        }
    }
    cout << bestk << ' ';
    cout << bestc << '\n';
    return 0;
}
