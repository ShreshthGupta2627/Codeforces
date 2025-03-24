//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;
void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);

    map<int, int> mp;
    set<int> st;
    for (auto &it : v)
    {
        cin >> it;
        mp[it]++;
    }

    for (auto &it : mp)
    {
        if (it.second >= 2)
        {
            cout << 1 << endl;
            cout << it.first << endl;
            return;
        }
    }

    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n - 2; i++)
    {
        if (v[i + 1] * 2 == v[i] + v[i + 2])
        {
            cout << 2 << endl;
            cout << v[i] << " " << v[i + 2] << endl;
            return;
        }
    }
    cout << -1 << endl;
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