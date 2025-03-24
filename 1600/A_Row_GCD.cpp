//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;

//------------------------ GCD Implementation begins -------------------------
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//------------------------ GCD Implementation ends ---------------------------

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (auto &it : a)
    {
        cin >> it;
    }
    for (auto &it : b)
    {
        cin >> it;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = gcd(ans, abs(a[0] - a[i]));
    }

    for (int i = 0; i < m; i++)
    {
        cout << gcd(b[i] + a[0], ans) << " ";
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