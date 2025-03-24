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

    vector<int> a(n);
    for (auto &it : a)
    {
        cin >> it;
    }

    vector<int> b(m);
    for (auto &it : b)
    {
        cin >> it;
    }

    vector<int> v;
    v.push_back(-1e18);
    for (auto &it : a)
    {
        v.push_back(it);
    }

    sort(b.begin(), b.end());

    for (int i = 1; i <= n; i++)
    {
        int lb = lower_bound(b.begin(), b.end(), v[i] + v[i - 1]) - b.begin();

        if (lb == b.size())
        {
            continue;
        }

        int minn = min(b[lb] - v[i], v[i]);
        int maxi = max(b[lb] - v[i], v[i]);

        if (minn >= v[i - 1])
        {
            v[i] = minn;
        }
        else
        {
            v[i] = maxi;
        }
    }

    // for (auto &it : a)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    if (is_sorted(v.begin(), v.end()))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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