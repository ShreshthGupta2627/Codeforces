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

    vector<int> mp(n * m + 1, 0);
    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i != n - 1)
            {
                if (v[i][j] == v[i + 1][j])
                {
                    mp[v[i][j]] = 2;
                }
            }

            if (j != m - 1)
            {
                if (v[i][j + 1] == v[i][j])
                {
                    mp[v[i][j]] = 2;
                }
            }

            freq[v[i][j]]++;
        }
    }
    int ans = 0;

    int maxi = 0, idx = 0;
    for (auto &it : freq)
    {
        if (it.second > maxi)
        {
            maxi = it.second;
            idx = it.first;
        }
    }

    bool f = 0;
    for (auto &it : freq)
    {
        if (mp[it.first] == 2)
        {
            ans += 2;
            f = 1;
        }
        else
        {
            ans += 1;
        }
    }

    f ? cout << ans - 2 << endl : cout << ans - 1 << endl;
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