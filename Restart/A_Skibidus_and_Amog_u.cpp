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

    int n = s.length();

    if (n < 2)
    {
        cout << s.substr(0, n - 1) + "us" << endl;
    }
    else if (s[n - 1] == 's' && s[n - 2] == 'u')
    {
        cout << s.substr(0, n - 2) + "i" << endl;
    }
    else
    {
        cout << s.substr(0, n - 1) + "us" << endl;
    }
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