#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<bool> used;
vector<int> curr;
long long x, y, k, b;
int n;
long long total = 0;

long long pow(long long a, int b) {
    long long r = 1;
    while (b > 0) {
        if (b & 1) r *= a, b--;
        a *= a, b >>= 1;
    }
    return r;
}

void generate(int depth, int last) {
    if (depth == k) {
        long long r = 0;
        for (int t : curr) {
            r += pow(b, t);
        }
        if (r >= x && r <= y) {
            total++;
        }
        return;
    }
    for (int i = last; i <= n; i++) {
        if (!used[i]) {
            curr[depth] = i;
            used[i] = true;
            generate(depth + 1, i);
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> y >> k >> b;
    n = (int)(log(y) / log(b));
    used.assign(n + 1, false);
    curr.assign(k, 0);
    generate(0, 0);
    cout << total << '\n';
    return 0;
}
