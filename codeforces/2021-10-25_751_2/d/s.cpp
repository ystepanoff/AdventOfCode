#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<int> dp(n + 1, 0);
    vector<bool> u(n + 1, false);
    vector<int> p(n + 1, -1);
    vector<int> q;
    for (int i = 1; i <= n; i++) {
        if (i - a[i] <= 0) {
           dp[i] = 1;
           q.push_back(i);
           u[i] = true;
           p[i] = 0;
        }
    }
    for (int x = 0; x < q.size(); x++) {
        for (int i = 1; i <= n; i++) {
            if (i + b[i] == q[x]) {
                for (int j = i; j <= i + a[j]; j++) {
                    if (!u[j]) {
                        dp[j] = dp[q[x]] + 1;
                        q.push_back(j);
                        u[j] = true;
                        p[j] = i;
                    }
                }
            }
        }
    }
    if (!u[n]) {
        cout << "-1\n";
        return 0;
    }
    cout << dp[n] <<  '\n';
    vector<int> res;
    int curr = p[n];
    for (int i = 0; i < dp[n] - 1; i++) {
        cout << curr << ' ';
        curr = p[curr] + b[curr];
    }
    cout << "0\n";
    return 0;
}
