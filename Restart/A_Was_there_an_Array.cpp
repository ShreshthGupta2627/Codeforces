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
    vector<int> v(n - 2);

    for (auto &it : v)
    {
        cin >> it;
    }

    for (int i = 0; i < n - 4; i++)
    {
        if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 1)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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