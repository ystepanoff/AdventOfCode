#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    double a;
    cin >> n >> a;

    double best = 1e16;
    double l = 0, r = a;
    while (r - l > eps)
    {
        double m = (l + r) / 2;
        bool good = true;
        vector<double> h;
        h.push_back(a);
        h.push_back(m);
        for (int i = 2; i < n; i++)
        {
            h.push_back(2.0 + 2 * h[i-1] - h[i-2]);
            if (h[i] < 0.0)
                good = false;
        }
        if (good && h[n-1] < best)
            best = h[n-1];
        if (good)
            r = m;
        else
            l = m;
    }

    cout << fixed << setprecision(2);
    cout << best << '\n';

    return 0;
}
