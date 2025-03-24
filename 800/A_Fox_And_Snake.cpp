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

    vector<vector<char>> ans(n, vector<char>(m, '.'));

    bool f = 1;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            if (f)
            {
                ans[i][m - 1] = '#';
            }
            else
            {
                ans[i][0] = '#';
            }
            f = !f;
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = '#';
            }
        }
    }

    for (auto &it : ans)
    {
        for (auto &i : it)
        {
            cout << i;
        }
        cout << endl;
    }
    cout << endl;
}
int32_t main()
{
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}