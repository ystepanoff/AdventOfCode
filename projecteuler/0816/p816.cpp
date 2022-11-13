#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

const int N = 2000000;

vector< pair<int,int> > gen_points() {
    vector< pair<int,int> > points;
    long long s = 290797, t = 0;
    for (int i = 0; i < 2 * N - 1; i++) {
        t = (s * s) % 50515093;
        if (!(i & 1)) points.push_back(make_pair(s, t));
        s = t;
    }
    return points;
}

double solve_naive(vector< pair<int,int> > &points) {
    double best = 1e9;
    for (int i = 0; i < points.size(); i++)
        for (int j = i + 1; j < points.size(); j++) {
            double x = points[i].first - points[j].first;
            double y = points[i].second - points[j].second;
            best = min(best, sqrt(x * x + y * y));
        }
    sort(points.begin(), points.end(), [](auto &a, auto &b) {
        return  a.second < b.second;
    });
    return best;
}

vector< pair<int,int> > merge(vector< pair<int,int> > &a, vector< pair<int,int> > &b) {
    vector< pair<int,int> > c;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i].second < b[j].second) {
            c.push_back(a[i++]);
        } else {
            c.push_back(b[j++]);
        }
    }
    while (i < a.size()) c.push_back(a[i++]);
    while (j < b.size()) c.push_back(b[j++]);
    return c;
}

double closest_pair_distance(vector< pair<int,int> > &points) {
    if (points.size() <= 5) return solve_naive(points);
    int m = points.size() >> 1;
    auto left = vector< pair<int,int> >(points.begin(), points.begin() + m);
    auto right = vector< pair<int,int> >(points.begin() + m , points.end());
    double l = (right[0].first + left[left.size() - 1].first) * 0.5;
    double d1 = closest_pair_distance(left);
    double d2 = closest_pair_distance(right);
    double d = min(d1, d2);
    auto merged = merge(left, right);
    vector< pair<int,int> > remaining;
    for (auto p : merged) {
        if (abs(p.first - l) < d) remaining.push_back(p);
    }
    for (int i = 0; i < remaining.size(); i++) {
        for (int j = i - 3; j < i + 4; j++) {
            if (j >= 0 && j < remaining.size() && j != i) {
                double x = remaining[i].first - remaining[j].first;
                double y = remaining[i].second - remaining[j].second;
                d = min(d, sqrt(x * x + y * y));
            }
        }
    }
    return d;
}

int main() {
    vector< pair<int,int> > points = gen_points();
    sort(points.begin(), points.end(), [](auto &a, auto &b) {
        return a.first < b.first;
    });
    double d = closest_pair_distance(points);
    cout << fixed << setprecision(9) << d << '\n';
    return 0;
}
