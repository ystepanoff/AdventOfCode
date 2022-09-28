#include <bits/stdc++.h>
using namespace std;

const int N = 70;

map<vector<int>,long long> cache;

long long count(int arcs_left, int pos, int l, int r, vector<int> cnt) {
    if (arcs_left == 0) {
        return cnt[0] == cnt[1] &&
            cnt[1] == cnt[2] &&
            cnt[2] == cnt[3] &&
            cnt[3] == cnt[4] &&
            l % 5 == 0 &&
            r % 5 == 0;
    }
    vector<int> it = { pos, l, r, cnt[0], cnt[1], cnt[2], cnt[3], cnt[4] };
    if (cache.find(it) == cache.end()) {
        cnt[(pos + 1) % 5]++;
        long long cl = count(arcs_left - 1, (pos + 1) % 5, l + 1, r, cnt);
        cnt[(pos + 1) % 5]--;
        cnt[(pos + 4) % 5]++;
        long long cr = count(arcs_left - 1, (pos + 4) % 5, l, r + 1, cnt);
        cnt[(pos + 4) % 5]--;
        cache[it] = cl + cr;
    }
    return cache[it];
}

int main() {
    vector<int> cnt(5, 0);
    cout << count(N, 0, 0, 0, cnt) << '\n';
    return 0;
}
