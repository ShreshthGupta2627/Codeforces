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
    int a, b;
    cin >> a >> b;

    int l = 1, h = 1e6;

    while (l < h)
    {
        int m = (l + h) / 2;
        if (a / (b * 1.0) > powf(2 / 3.0, m))
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << h << endl;
}
int32_t main()
{
    int tc = 1;
    // cin >> tc;
    // calculatePrime();
    while (tc--)
    {
        solve();
    }
    return 0;
}