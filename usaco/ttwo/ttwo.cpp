/*
ID: dr.yste1
TASK: ttwo
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "ttwo"

void out(vector<string> &grid) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++)
            cout << grid[i][j];
        cout << '\n';
    }
}

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    vector<string> grid(12, string(12, '*'));
    for (int i = 1; i <= 10; i++) {
        string s;
        fin >> s;
        for (int j = 1; j <= 10; j++) {
            grid[i][j] = s[j - 1];
        }
    }
    int xc, yc, xf, yf;
    int dirc = 0, dirf = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (grid[i][j] == 'C') {
                xc = i, yc = j;
            } else if (grid[i][j] == 'F') {
                xf = i, yf = j;
            }
        }
    }
    for (int steps = 1; ; steps++) {
        bool rotc = false, rotf = false;
        if (grid[xc + dx[dirc]][yc + dy[dirc]] == '*') {
            dirc = (dirc + 1) % 4;
            rotc = true;
        }
        if (grid[xf + dx[dirf]][yf + dy[dirf]] == '*') {
            dirf = (dirf + 1) % 4;
            rotf = true;
        }
        if (!rotc) {
            grid[xc][yc] = '.';
            xc += dx[dirc], yc += dy[dirc];
            grid[xc][yc] = 'C';
        }
        if (!rotf) {
            grid[xf][yf] = '.';
            xf += dx[dirf], yf += dy[dirf];
            grid[xf][yf] = 'F';
        }
        //out(grid);
        //cout << "------------------------\n";
        //cout << "step " << steps << '\n';
        //cout << "------------------------\n";
        if (xc == xf && yc == yf) {
            fout << steps << '\n';
            break;
        }
        if (steps > 100000) {
            fout << "0\n";
            break;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
