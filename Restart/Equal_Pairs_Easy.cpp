//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> mp;
    int maxi = 0, var1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;

        if (maxi <= mp[v[i]] && v[i])
        {
            maxi = mp[v[i]];
            var1 = v[i];
        }
    }

    int cnt = mp[0] + maxi;

    int ans = (cnt * (cnt - 1)) / 2;

    for (auto &it : mp)
    {
        if (it.first != 0 && it.first != var1 && it.second)
        {
            ans += it.second * (it.second - 1) / 2;
        }
    }

    cout << ans << endl;
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