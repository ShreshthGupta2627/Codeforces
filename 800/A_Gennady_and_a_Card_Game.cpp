//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
using namespace std;

//------------------------- IO simplifier begins -------------------------------
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) { return in >> p.first >> p.second; }
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) { return out << p.first << ' ' << p.second; }
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &x : v)
        out << x << ' ';
    return out;
}
//------------------------- IO simplifier ends ----------------------------------

//------------------------ GCD Implementation begins -------------------------
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//------------------------ GCD Implementation ends ---------------------------

//------------------------ Seive Implementation begins ------------------------
vector<bool> isPrime(1e6 + 1, 1);
void calculatePrime()
{
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 1e6; i++)
        if (isPrime[i])
            for (int j = i * i; j <= 1e6; j += i)
                isPrime[j] = 0;
}
//------------------------ Seive Implementation ends --------------------------

void solve()
{
    string s;
    cin >> s;

    vector<string> v(5);
    cin >> v;

    for (auto &it : v)
    {
        if (it[0] == s[0] || it[1] == s[1])
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int32_t main()
{
    int tc = 1;
    // cin >> tc;
    //   calculatePrime();
    while (tc--)
    {
        solve();
    }
    return 0;
}