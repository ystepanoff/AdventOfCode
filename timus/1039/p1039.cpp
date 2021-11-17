#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, u, dp1, dp2;
vector< vector<int> > tree;

void dfs(int v)
{
    if (u[v])
        return;
    u[v] = 1;
    dp1[v] = a[v];
    dp2[v] = 0;
    for (int u : tree[v])
    {
        dfs(u);
        dp1[v] += dp2[u];
        dp2[v] += max(dp1[u], dp2[u]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.resize(n + 1, 0);
    u.resize(n + 1, 0);
    dp1.resize(n + 1, 0);
    dp2.resize(n + 1, 0);
    tree.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (1)
    {
        int u, v;
        cin >> u >> v;
        if (!u)
            break;
        tree[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        if (!u[i])
            dfs(i);

    int best = max(dp1[1], dp2[1]);
    for (int i = 2; i <= n; i++)
        best = max(best, max(dp1[i], dp2[i]));

    cout << best << '\n';

    return 0;
}
