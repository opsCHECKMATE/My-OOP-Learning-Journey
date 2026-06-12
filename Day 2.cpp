#include <bits/stdc++.h>

class container {
private:
    std::vector<std::vector<char>> g;
    std::vector<std::vector<bool>> vis;
    std::vector<std::pair<int, int>> dir = {
        {-1, +0},
        {+1, +0},
        {+0, -1},
        {+0, +1}
    };
    int n, m;
public:
    void __in() {
        std::cin >> n >> m;
        g.assign(n, std::vector<char>(m));
        for (auto &i : g) {
            for (auto &j : i) {
                std::cin >> j;
            }
        }
        vis.assign(n, std::vector<bool>(m, false));
    }
    bool in__side(int r, int c) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }
    bool found(int a, int b, int c, int d) {
        vis.assign(n, std::vector<bool>(m, false));
        if (!in__side(a, b) || !in__side(c, d)) {
            return false;
        }
        if (g[a][b] == '#' || g[c][d] == '#') {
            return false;
        }
        std::queue<std::pair<int, int>> q;
        q.push({a, b});
        vis[a][b] = true;
        while (!q.empty()) {
            auto [__r, __c] = q.front();
            q.pop();
            if (__r == c && __c == d) {
                return true;
            }
            for (auto [dr, dc] : dir) {
                int new__r = __r + dr;
                int new__c = __c + dc;
                if (in__side(new__r, new__c) && !vis[new__r][new__c] && g[new__r][new__c] != '#') {
                    vis[new__r][new__c] = true;
                    q.push({new__r, new__c});
                }
            }
        }
        return false;
    }
};

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    container fun;
    fun.__in();
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << (fun.found(a, b, c, d) ? "found" : "not found") << '\n';
    return 0;
}
