#include <bits/stdc++.h>
using namespace std;

string s, t;
int n;
vector<int> cnt(256, 0);
vector<string> result;

void gen(int depth) {
    if (depth == n) {
        result.push_back(t);
        return;
    }
    for (char c = 'a'; c <= 'z'; c++)
        if (cnt[c] > 0) {
            t[depth] = c;
            cnt[c]--;
            gen(depth + 1);
            cnt[c]++;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    t = s;
    for (char c : s)
        cnt[c]++;
    gen(0);
    cout << result.size() << '\n';
    for (string s : result)
        cout << s << '\n';
    return 0;
}
