//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;

bool containDig7(int num)
{
    while (num)
    {
        if (num % 10 == 7)
        {
            return 1;
        }
        num /= 10;
    }
    return 0;
}

int rec(int i, int k, int n, vector<int> &v, map<tuple<int, int, int>, int> &dp)
{
    if (containDig7(n))
    {
        return 0;
    }

    if (dp.find({i, k, n}) != dp.end())
    {
        return dp[{i, k, n}];
    }

    int mini = 1e9;

    if (k < 10)
    {
        mini = min(mini, 1 + rec(i, k + 1, n + v[i], v, dp));
    }

    if (i != v.size() - 1)
        mini = min(mini, rec(i + 1, 0, n, v, dp));

    return dp[{i, k, n}] = mini;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> v = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};

    map<tuple<int, int, int>, int> dp;

    cout << rec(0, 0, n, v, dp) << endl;
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