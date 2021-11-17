#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<int,bool> list;
    int n;
    cin >> n;
    while (n--) {
        int v;
        cin >> v;
        list[v] = true;
    }
    int m, c = 0;
    cin >> m;
    while (m--) {
        int v;
        cin >> v;
        if (list[v])
            c++;
    }
    cout << c << '\n';
    return 0;
}
