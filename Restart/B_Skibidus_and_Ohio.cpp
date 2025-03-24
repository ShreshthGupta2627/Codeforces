//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;
void solve()
{
    string s;
    cin >> s;

    int cnt = 0, i = 1;
    bool f = 0;
    while (i < s.length())
    {
        if (s[i] == s[i - 1])
        {
            f = 1;
            break;
        }
        i++;
    }
    if (f)
        cout << 1 << endl;
    else
        cout << s.length() << endl;
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