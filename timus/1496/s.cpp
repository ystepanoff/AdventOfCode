#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<string,int> cnt;
    vector<string> result;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (cnt[s] == 1) {
            result.push_back(s);
        }
        cnt[s]++;
    }
    for (string s : result) {
        cout << s << '\n';
    }
    return 0;
}
