#include <bits/stdc++.h>
using namespace std;

vector< vector<char> > grid(11, vector<char> (11, 0));
vector< vector<char> > visited(11, vector<char> (11, 0));
vector<int> dx = { 1, 0, -1, 0 };
vector<int> dy = { 0, 1, 0, -1 };
vector<char> dir = { 'R', 'T', 'L', 'B' };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);

    auto it = find(s.begin(), s.end(), ' ');
    if (it != s.end())
    {
        int x = stoi(s.substr(0, (int)(it - s.begin())));
        int y = stoi(s.substr((int)(it - s.begin())));
        queue<pair<int,int>> q;
        q.push(make_pair(x, y));
        int n = 0;
        while (!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            grid[x][y] = 1;
            n++;
            cin >> s;
            for (char c : s)
                if (c != ',' && c != '.')
                {
                    if (c == 'R') q.push(make_pair(x + 1, y));
                    if (c == 'T') q.push(make_pair(x, y + 1));
                    if (c == 'L') q.push(make_pair(x - 1, y));
                    if (c == 'B') q.push(make_pair(x, y - 1));
                }
        }
        cout << n << '\n';
        for (int x = 0; x < 11; x++)
            for (int y = 0; y < 11; y++)
                if (grid[x][y])
                    cout << x << ' ' << y << '\n';
    } else
    {
        int n = stoi(s);
        int first_x = -1, first_y = -1;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (first_x == -1)
                first_x = x, first_y = y;
            grid[x][y] = 1;
        }
        cout << first_x << ' ' << first_y << '\n';
        queue<pair<int,int>> q;
        visited[first_x][first_y] = 1;
        q.push(make_pair(first_x, first_y));
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            string s = "";
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx > 0 && xx < 11 && yy > 0 && yy < 11 && grid[xx][yy] && !visited[xx][yy])
                {
                    q.push(make_pair(xx, yy));
                    visited[xx][yy] = 1;
                    s += dir[i];
                }
            }
            cout << s;
            cout << (q.empty() ? '.' : ',') << '\n';
        }
    }

    return 0;
}
