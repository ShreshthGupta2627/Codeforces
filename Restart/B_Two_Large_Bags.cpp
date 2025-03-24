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

    vector<int> v(n);
    vector<int> a(n + 1, 0);
    for (auto &it : v)
    {
        cin >> it;
        a[it]++;
    }

    int i = 0, m = a.size();

    while (i < m)
    {
        if (a[i] % 2 == 0)
        {
            if (i < m - 1 && a[i] >= 2)
            {
                a[i + 1] += a[i] - 2;
                a[i] = 2;
            }
        }
        else
        {
            if (i < m - 1 && a[i] >= 2)
            {
                a[i + 1] += a[i] - 2;
                a[i] = 2;
            }
            else
            {
                cout << "No" << endl;
                return;
            }
        }
        i++;
    }

    int k = m - 1;
    while (k >= 0 && a[k] != 0)
    {
        k--;
    }

    if (a[m - 1] % 2 == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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