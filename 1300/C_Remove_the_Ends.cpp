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
    for (auto &it : v)
    {
        cin >> it;
    }

    vector<int> pref(n), suff(n);
    pref[0] = v[0] > 0 ? v[0] : 0;
    suff[n - 1] = v[n - 1] < 0 ? v[n - 1] : 0;

    for (int i = 1; i < n; i++)
    {
        if (v[i] > 0)
            pref[i] = pref[i - 1] + v[i];
        else
            pref[i] = pref[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] < 0)
            suff[i] = suff[i + 1] + v[i];
        else
            suff[i] = suff[i + 1];
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, pref[i] + abs(suff[i]));
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