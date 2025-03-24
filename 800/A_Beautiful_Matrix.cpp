//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;
void solve()
{
    int i{0}, j{0};

    for (int k = 0; k < 5; k++)
    {
        for (int l = 0; l < 5; l++)
        {
            int t;
            cin >> t;

            if (t)
            {
                i = k, j = l;
            }
        }
    }

    cout << abs(i - 2) + abs(j - 2) << endl;
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