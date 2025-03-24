//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m, 0));
    for (auto &it : v)
    {
        for (auto &i : it)
        {
            cin >> i;
        }
    }

    for (auto &it : v)
    {
        sort(it.begin(), it.end());
    }

    bool f = 1;
    vector<int> p(n, -1);
    for (int j = 0; j < v.size(); j++)
    {
        for (int i = 1; i < v[j].size(); i++)
        {
            if (v[j][i] - v[j][i - 1] != n)
            {
                cout << -1 << endl;
                return;
            }
        }
        p[v[j][0]] = j + 1;
    }

    for (auto &it : p)
    {
        cout << it << " ";
    }
    cout << endl;
}
int32_t main()
{
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}