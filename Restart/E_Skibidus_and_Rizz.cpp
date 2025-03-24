//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    if (max(n, m) < k || abs(n - m) > k)
    {
        cout << -1 << endl;
        return;
    }

    string ans;
    if (n > m)
    {
        ans = string(k, '0');
        n -= k;

        while (m > n)
        {
            ans.push_back('1');
            m--;
        }

        while (n--)
        {
            if (ans.back() == '1')
            {
                ans += "01";
            }
            else
            {
                ans += "10";
            }
        }
    }
    else
    {
        ans = string(k, '1');
        m -= k;

        while (n > m)
        {
            ans.push_back('0');
            n--;
        }

        while (n--)
        {
            if (ans.back() == '1')
            {
                ans += "01";
            }
            else
            {
                ans += "10";
            }
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