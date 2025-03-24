//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
using namespace std;

int dfs(int i, vector<vector<int>> &adj, vector<int> &f, vector<int> &vis, string &s)
{
    vis[i] = 1;

    int ans = 0;
    for (auto &it : adj[i])
    {
        if (!vis[it])
        {
            if (s[it] == '0')
            {
                ans += dfs(it, adj, f, vis, s) + 1;
            }
            else
            {
                ans += dfs(it, adj, f, vis, s);
            }
        }
        else
        {
            ans += f[it];
        }
    }
    return f[i] = ans;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }

    string s;
    cin >> s;

    vector<vector<int>> adj(n + 1);
    vector<int> f(n, 0), vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (v[i] == i + 1 && s[i] == '0')
        {
            vis[i] = 1;
            f[i] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(v[i] - 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, f, vis, s);
        }
    }

    for (auto &it : f)
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