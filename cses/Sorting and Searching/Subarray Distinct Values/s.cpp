#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long total = 0;
    int l = 0, m = 0;
    unordered_map<int,int,custom_hash> cnt;
    for (int r = 0; r < n; r++) {
        if (cnt[a[r]] == 0) m++;
        cnt[a[r]]++;
        while (m > k) {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0) m--;
            l++;
        }
        total += r - l + 1;
    }
    cout << total << '\n';
    return 0;
}
