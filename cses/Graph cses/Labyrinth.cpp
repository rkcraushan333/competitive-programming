#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{
    int n, m;
    cin >> n >> m;
    int sr = 0, sc = 0;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
            {
                sr = i;
                sc = j;
            }
        }
    }
    // using bfs
    string res = "";
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            par[i][j] = {i, j};

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    char dir[] = {'R', 'L', 'D', 'U'};
    map<pair<int, int>, char> mp;
    for (int i = 0; i < 4; i++)
    {
        mp[{dx[i], dy[i]}] = dir[i];
    }
    queue<pair<int, int>> q;
    q.push({sr, sc});
    v[sr][sc] = '#';
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || b < 0 || a > n - 1 || b > m - 1 || v[a][b] == '#')
                continue;
            if (v[a][b] == 'B')
            {
                res.push_back(mp[{a - x, b - y}]);
                while (1)
                {
                    if ((par[x][y].first == x) && (par[x][y].second == y))
                        break;
                    res.push_back(mp[{x - par[x][y].first, y - par[x][y].second}]);
                    int x1 = x, y1 = y;
                    x = par[x1][y1].first;
                    y = par[x1][y1].second;
                }
                cout << "YES" << endl;
                cout << res.size() << endl;
                reverse(res.begin(), res.end());
                cout << res << endl;
                return 0;
            }
            v[a][b] = '#';
            q.push({a, b});
            par[a][b] = {x, y};
        }
    }
    cout << "NO" << endl;
    return 0;
}