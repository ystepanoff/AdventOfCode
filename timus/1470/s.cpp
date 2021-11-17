#include <bits/stdc++.h>
using namespace std;

const int N = 150;
long long t[N][N][N];

void update(int x, int y, int z, int v) {
    for (int i = x; i < N; i += i & -i)
        for (int j = y; j < N; j += j & -j)
            for (int k = z; k < N; k += k & -k)
                t[i][j][k] += v;
}

long long sum(int x, int y, int z) {
    long long s = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            for (int k = z; k > 0; k -= k & -k)
                s += t[i][j][k];
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin >> n;
    while (1) {
        int m;
        cin >> m;
        if (m == 1) {
            int x, y, z, k;
            cin >> x >> y >> z >> k;
            x++, y++, z++;
            update(x, y, z, k);
        } else if (m == 2) {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            x1++, y1++, z1++;
            x2++, y2++, z2++;
            int s = sum(x2, y2, z2);
            s -= sum(x1 - 1, y2, z2);
            s -= sum(x2, y1 - 1, z2);
            s += sum(x1 - 1, y1 - 1, z2);
            s -= sum(x2, y2, z1 - 1);
            s += sum(x1 - 1, y2, z1 - 1);
            s += sum(x2, y1 - 1, z1 - 1);
            s -= sum(x1 - 1, y1 - 1, z1 - 1);
            cout << s << '\n';
        } else {
            break;
        }
    }
    return 0;
}
