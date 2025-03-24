//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
using namespace std;
void solve()
{
    int a, b;
    cin >> a >> b;

    // vector<int> v;

    // int cnt = 1;

    // while (a <= b)
    // {
    //     v.push_back(a);
    //     a += cnt;
    //     cnt++;
    // }

    cout << floor((-1 + sqrt(1 + 8 * (b - a))) / 2) + 1 << endl;
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