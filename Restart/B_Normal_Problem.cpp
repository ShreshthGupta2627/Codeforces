//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;

    string ans = "";

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == 'w')
        {
            ans += 'w';
        }
        else if (s[i] == 'p')
        {
            ans += 'q';
        }
        else
        {
            ans += 'p';
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