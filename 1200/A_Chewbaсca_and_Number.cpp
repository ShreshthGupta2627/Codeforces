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
    bool f = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] >= '5')
        {

            s[i] = (9 - (s[i] - '0')) + '0';
        }
    }

    if (s[0] >= '5' && s[0] < '9')
    {
        s[0] = (9 - (s[0] - '0')) + '0';
    }

    cout << s << endl;
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