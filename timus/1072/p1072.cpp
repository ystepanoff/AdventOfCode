#include <bits/stdc++.h>
using namespace std;

long long s2i(string s) {
    vector<long long> values;
    for (int i = 0; i < 4; i++) {
        auto it = find(s.begin(), s.end(), '.');
        string t;
        if (it != s.end()) {
            t = s.substr(0, (int)(it - s.begin()));
            s = s.substr((int)(it - s.begin()) + 1);
        } else {
            t = s;
        }
        values.push_back(stoi(t));
    }
    long long result = 0, p = 1;
    for (int i = 3; i >= 0; i--) {
        result += values[i] * p;
        p <<= 8;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<long long,long long>>> net(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            string ip, mask;
            cin >> ip >> mask;
            net[i].push_back(make_pair(s2i(ip), s2i(mask)));
        }
    }
    int u, v;
    cin >> u >> v;
    vector<bool> visited(n + 1, false);
    vector<int> prev(n + 1, 0);
    vector<int> q;
    q.push_back(u);
    visited[u] = true;
    for (int i = 0; i < q.size(); i++)
        for (int j = 1; j <= n; j++)
            if (!visited[j])
                for (auto p1 : net[q[i]])
                    for (auto p2 : net[j])
                        if ((p1.first & p1.second) == (p2.first & p2.second)) {
                            q.push_back(j);
                            visited[j] = true;
                            prev[j] = q[i];
                        }
    if (visited[v]) {
        cout << "Yes\n";
        vector<int> path;
        while (u != v) {
            path.push_back(v);
            v = prev[v];
        }
        path.push_back(u);
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << ' ';
        cout << '\n';
    } else {
        cout << "No\n";
    }
    return 0;
}
