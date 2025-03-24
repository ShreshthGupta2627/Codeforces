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

    // if (is_sorted(a.begin(), a.end()))
    // {
    //     cout << "YES" << endl;
    //     return;
    // }
    a[n - 1] = max(a[n - 1], b[0] - a[n - 1]);
    a[0] = min(a[0], b[0] - a[0]);
    for (int i = n - 2; i >= 1; i--)
    {
        int maxi = max(b[0] - a[i], a[i]);
        int mini = min(b[0] - a[i], a[i]);
        if (maxi >= a[i - 1] && maxi <= a[i + 1])
        {
            a[i] = maxi;
        }
        else
        {
            a[i] = mini;
        }
    }
    // for (auto &it : a)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    if (is_sorted(a.begin(), a.end()))
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