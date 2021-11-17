#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > g;
vector<bool> u, dp;

void dfs(int v)
{
    u[v] = true;
    bool win = false;
    for (int i : g[v])
        if (!u[i])
        {
            dfs(i);
            win |= !dp[i];
        }
    dp[v] = win;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    g.resize(n + 1);
    u.resize(n + 1, false);
    dp.resize(n + 1, false);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(k);

    if (dp[k])
    {
        int x = -1;
        for (int u : g[k])
            if (!dp[u] && (x == -1 || u < x))
                x = u;
        cout << "First player wins flying to airport " << x << '\n';
    } else
    {
        cout << "First player loses\n";
    }

    return 0;
}
