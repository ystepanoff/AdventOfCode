#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int l, r;
    cin >> l >> r;
    vector<int> sumd(r + 1);
    for (int i = 1; i <= r; i++)
        for (int j = i; j <= r; j += i)
            sumd[j] += i;
    int best = l;
    double bestv = sumd[best] * 1.0 / best;
    for (int i = l; i <= r; i++) {
        double curr = sumd[i] * 1.0 / i;
        if (curr < bestv) {
            best = i;
            bestv = curr;
        }
    }
    cout << best << '\n';
    return 0;
}
