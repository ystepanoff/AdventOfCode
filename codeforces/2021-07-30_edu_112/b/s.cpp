#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int W, H, w, h;
        int x1, y1, x2, y2;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        /*if (w + x2 - x1 > W && h + y2 - y1 > H) {
            cout << "-1\n";
            continue;
        }*/
        double best = 1e9;
        {
            double need_x = max(0, w - x1);
            double need_y = max(0, h - y1);
            if (need_x * need_y > 0) {
                if (w + x2 - x1 <= W) best = min(best, need_x);
                if (h + y2 - y1 <= H) best = min(best, need_y);
            } else {
                best = 0;
            }
        }
        {
            double need_x = max(0, w - x1);
            double need_y = max(0, y2 - (H - h));
            if (need_x * need_y > 0) {
                if (w + x2 - x1 <= W) best = min(best, need_x);
                if (h + y2 - y1 <= H) best = min(best, need_y);
            } else {
                best = 0;
            }
        }
        {
            double need_x = max(0, x2 - (W - w));
            double need_y = max(0, h - y1);
            if (need_x * need_y > 0) {
                if (w + x2 - x1 <= W) best = min(best, need_x);
                if (h + y2 - y1 <= H) best = min(best, need_y);
            } else {
                best = 0;
            }
        }
        {
            double need_x = max(0, x2 - (W - w));
            double need_y = max(0, y2 - (H - h));
            if (need_x * need_y > 0) {
                if (w + x2 - x1 <= W) best = min(best, need_x);
                if (h + y2 - y1 <= H) best = min(best, need_y);
            } else {
                best = 0;
            }
        }
        if (best > 1e8 + 1) {
            cout << "-1\n";
            continue;
        }
        cout << fixed << setprecision(6) << best << '\n';
    }
    return 0;
}
