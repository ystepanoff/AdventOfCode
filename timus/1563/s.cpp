#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    int total = 0;
    map<string,bool> mp;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        if (mp[s]) {
            total++;
        } else {
            mp[s] = true;
        }
    }
    cout << total << '\n';
    return 0;
}
