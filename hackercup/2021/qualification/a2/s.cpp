#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>> &g, vector<bool> &u, vector<int> &d, char v) {
    vector<char> q;
    q.push_back(v);
    u[v] = true;
    for (int i = 0; i < q.size(); i++)
        for (int x : g[q[i]])
            if (!u[x]) {
                q.push_back(x);
                u[x] = true;
                d[x] = d[q[i]] + 1;
            }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int _t = 1; _t <= tt; _t++) {
        string s;
        cin >> s;
        int n = s.length();
        int k;
        cin >> k;
        vector<vector<char>> g(256);
        for (int i = 0; i < k; i++) {
            string t;
            cin >> t;
            g[t[0]].push_back(t[1]);
        }
        vector<vector<bool>> vis(256, vector<bool>(256, false));
        vector<vector<int>> dist(256, vector<int>(256, false));
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            bfs(g, vis[ch], dist[ch], ch);
        }
        int best = -1;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            int curr = 0;
            for (int i = 0; i < n; i++)
                if (s[i] != ch) {
                    if (vis[s[i]][ch]) {
                        curr += dist[s[i]][ch];
                    } else {
                        curr = -1;
                        break;
                    }
                }
            if (curr != -1 && (best == -1 || curr < best))
                best = curr;
        }
        cout << "Case #" << _t << ": " << best << '\n';
    }
    return 0;
}
