//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int minn = min({a, b, c});
    int maxi = max({a, b, c});
    int left = a + b + c - maxi - minn;

    cout << maxi - left + left - minn << endl;
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