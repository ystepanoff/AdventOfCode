#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
        while (1) {
            int v;
            cin >> v;
            if (!v)
                break;
            g[v].push_back(i);
            g[i].push_back(v);
        }

    vector<int> col(n + 1, 0);
    vector<int> result;
    for (int j = 1; j <= n; j++)
        if (!col[j]) {
            vector<int> q;
            col[j] = 1;
            q.push_back(j);
            for (int i = 0; i < q.size(); i++)
                for (int v : g[q[i]])
                    if (!col[v]) {
                        col[v] = 1 + (col[q[i]] % 2);
                        if (col[v] == 2)
                            result.push_back(v);
                        q.push_back(v);
                    }
        }
    cout << result.size() << '\n';
    for (int r : result)
        cout << r << ' ';
    cout << '\n';

    return 0;
}
