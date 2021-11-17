#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> divs(N, 0);
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            ++divs[j];
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        cout << divs[n] << '\n';
    }
    return 0;
}
