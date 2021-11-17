#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<string,int> cnt, price;
    vector<string> all;
    for (int i = 0; i < 6; i++) {
        string s, t;
        int p;
        cin >> t >> s >> p;
        if (cnt[s] == 0) {
            cnt[s] = 1;
            price[s] = p;
        } else {
            cnt[s]++;
            price[s] = min(price[s], p);
        }
        all.push_back(s);
    }
    string best = all[0];
    for (string &s : all) {
        if (cnt[s] > cnt[best] || (cnt[s] == cnt[best] && price[s] < price[best])) {
            best = s;
        }
    }
    cout << best << '\n';
    return 0;
}
