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

    int ans{0};
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s[0] == 'I')
            ans += 20;
        else if (s[0] == 'C')
            ans += 6;
        else if (s[0] == 'T')
            ans += 4;
        else if (s[0] == 'D')
            ans += 12;
        else
            ans += 8;
    }

    cout << ans << endl;
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