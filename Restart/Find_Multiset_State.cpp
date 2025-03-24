//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    multiset<int> st;
    for (auto &it : v)
    {
        cin >> it;
        st.insert(it);
    }

    while (k--)
    {
        auto it1 = st.begin();
        auto it2 = st.end();
        it2 = prev(it2);

        int val = (*it1) + (*it2);

        st.erase(it1);
        st.erase(it2);

        st.insert(val);
    }

    for (auto &it : st)
    {
        cout << it << " ";
    }
    cout << endl;
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