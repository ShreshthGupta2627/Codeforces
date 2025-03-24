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
    int n;
    cin >> n;

    bool f = 0;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
        if (it)
            f = 1;
    }

    cout << ((f == 1) ? "HARD" : "EASY") << endl;
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