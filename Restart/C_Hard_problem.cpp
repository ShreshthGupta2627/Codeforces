//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
using namespace std;
void solve()
{
    int m, a, b, c;
    cin >> m >> a >> b >> c;

    int ans = min(a, m) + min(b, m);
    ans = max(ans, ans + min(2 * m - ans, c));
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