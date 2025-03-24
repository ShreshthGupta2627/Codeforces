//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m, 0));

    for (auto &it : v)
    {
        for (auto &i : it)
        {
            cin >> i;
        }
    }

    priority_queue<pair<int, vector<int>>> pq;

    for (auto &it : v)
    {
        int sum = 0;
        for (auto &i : it)
        {
            sum += i;
        }
        pq.push({sum, it});
    }

    vector<int> f;

    while (!pq.empty())
    {
        auto it = pq.top().second;
        pq.pop();

        for (auto &i : it)
        {
            f.push_back(i);
        }
    }

    int pre = 0;
    int ans = 0;
    for (auto &it : f)
    {
        pre = pre + it;
        ans += pre;
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