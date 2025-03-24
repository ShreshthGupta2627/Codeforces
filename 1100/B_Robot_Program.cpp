//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;
void solve()
{
    int n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    int curr = x, idx{0};

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            curr++;
        }
        else
        {
            curr--;
        }

        if (curr == 0)
        {
            idx = i + 1;
            break;
        }
    }

    int ans = 0;
    if (!curr)
    {
        ans++;
        k -= idx;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R')
            {
                curr++;
            }
            else
            {
                curr--;
            }

            if (curr == 0)
            {
                idx = i + 1;
                break;
            }
        }

        if (!curr)
            ans += k / idx;
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