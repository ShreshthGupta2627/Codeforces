//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;

bool toReplace(int j, vector<int> &a, const vector<int> &minn)
{
    int m = minn.size();
    for (int i = 0; i < m; i++)
    {
        if (a[j + i] < minn[i])
            return false;
        if (a[j + i] > minn[i])
            return true;
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (auto &it : a)
        cin >> it;
    for (auto &it : b)
        cin >> it;

    int mini = *min_element(b.begin(), b.end());

    vector<int> minn;
    for (int i = 0; i < m; i++)
    {
        if (b[i] == mini)
        {
            for (int j = 0; j < m; j++)
            {
                minn.push_back(b[(i + j) % m]);
            }
            break;
        }
    }

    int idx = -1;

    for (int i = 0; i < n - m + 1; i++)
    {
        if (a[i] > minn[0])
        {
            idx = i;
            break;
        }

        if (a[i] == minn[0])
        {
            if (toReplace(i, a, minn))
            {
                idx = i;
                break;
            }
        }
    }

    if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = min(a[i], minn[0]);
        }
    }
    else if (idx != -1)
    {
        for (int i = idx; i < n; i++)
        {
            a[i] = minn[0];
        }

        int j = n - 1;
        for (int i = m - 1; i > 0; i--)
        {
            a[j] = minn[i];
            j--;
        }
    }

    for (auto &it : a)
        cout << it << " ";
    cout << endl;
}

int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}
