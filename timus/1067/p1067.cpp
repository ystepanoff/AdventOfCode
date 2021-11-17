#include <bits/stdc++.h>
using namespace std;

struct dir {
    string name;
    vector<dir> children;

    dir(string name) {
        this->name = name;
        this->children = { };
    }

    bool operator<(dir &d) {
        return this->name < d.name;
    }
};

dir root("*");

void process(dir &curr, string &path) {
    auto it = find(path.begin(), path.end(), '\\');
    if (it == path.end()) {
        for (dir d : curr.children)
            if (!path.compare(d.name))
                return;
        dir next(path);
        curr.children.push_back(next);
    } else {
        string level = path.substr(0, (int)(it - path.begin()));
        path = path.substr((int)(it - path.begin()) + 1);
        for (int i = 0; i < curr.children.size(); i++)
            if (!level.compare(curr.children[i].name)) {
                process(curr.children[i], path);
                return;
            }
        dir next(level);
        curr.children.push_back(next);
        process(curr.children.back(), path);
    }
}

void walk(dir curr, string prefix) {
    sort(curr.children.begin(), curr.children.end());
    for (dir d : curr.children) {
        cout << prefix << d.name << '\n';
        walk(d, prefix + ' ');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        process(root, s);
    }

    walk(root, "");

    return 0;
}
