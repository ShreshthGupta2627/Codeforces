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

    string s = to_string(n);

    int m = s.length();
    int cnt = 0;
    for (auto &it : s)
    {
        if (it != '0')
            cnt++;
    }

    cout << cnt << endl;
    for (int i = 0; i < m; i++)
    {
        if (s[i] != '0')
            cout << (s[i] - '0') * pow(10, m - i - 1) << " ";
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