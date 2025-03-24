//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;

    map<int, int> mp;
    int ans = 0, maxx = 0, cnt = n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[b]++;
        cnt--;

        ans -= (mp[b] - 1) * (mp[b] - 2) / 2;
        ans += (mp[b]) * (mp[b] - 1) / 2;

        if (mp[b] > maxx)
        {
            maxx = mp[b];
        }

        int tmp = ans;
        tmp -= (maxx) * (maxx - 1) / 2;
        tmp += (cnt + maxx) * (cnt + maxx - 1) / 2;

        cout << tmp << " ";
    }

    cout << endl;
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