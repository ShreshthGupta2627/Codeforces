//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    int N = sqrt(n);

    if (N * N != n)
    {
        cout << "No" << endl;
        return;
    }

    vector<vector<char>> v(N, vector<char>(N, '.'));

    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            v[i][j] = s[idx];
            idx++;
        }
    }

    bool ans = 1;
    for (int i = 0; i < N; i++)
    {
        if (v[0][i] == '0')
        {
            ans = 0;
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (v[N - 1][i] == '0')
        {
            ans = 0;
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (v[i][0] == '0')
        {
            ans = 0;
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (v[i][N - 1] == '0')
        {
            ans = 0;
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
            {
                continue;
            }
            else
            {
                if (v[i][j] == '1')
                {
                    ans = 0;
                    break;
                }
            }
        }
    }

    if (ans)
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