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

    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }

    int idxM = max_element(v.begin(), v.end()) - v.begin();
    int idxm = n - (min_element(v.rbegin(), v.rend()) - v.rbegin()) - 1;

    // cout << idxM << " " << idxm << endl;

    if (idxM < idxm)
    {
        cout << idxM + n - 1 - idxm << endl;
    }
    else
    {
        cout << idxM + n - 1 - idxm - 1 << endl;
    }
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