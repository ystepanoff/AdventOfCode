#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int k;
    cin >> s >> k;
    sort(s.begin(), s.end());
    k--;
    while (k--)
        next_permutation(s.begin(), s.end());
    cout << s << '\n';
    return 0;
}
