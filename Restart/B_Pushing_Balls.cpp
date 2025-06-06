//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
#define Y cout << "YES" << endl;
#define N cout << "NO" << endl;
using namespace std;

//----------------------------------------- IO simplifier begins -----------------------------------------
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
//----------------------------------------- IO simplifier ends -------------------------------------------

//---------------------------- Modular Arithematic Implementation begins ---------------------------------
int mod_pow(int a, int n, int m)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = ((res % m) * (a % m)) % m;
            n--;
        }
        a = ((a % m) * (a % m)) % m;
        n /= 2;
    }
    return res;
}
int mod_mul(int a, int b, int m)
{
    return ((a % m) * (b % m)) % m;
}
int mod_add(int a, int b, int m)
{
    return ((a % m) + (b % m)) % m;
}
int mod_sub(int a, int b, int m)
{
    return ((a % m) - (b % m) + m) % m;
}
int mod_div(int a, int b, int m)
{
    int mod_inv = mod_pow(b, m - 2, m);
    return mod_mul(a, mod_inv, m);
}
//--------------------------- Modular Arithematic Implementation ends ---------------------------

//------------------------------- GCD Implementation begins -------------------------------------
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//------------------------------- GCD Implementation ends ----------------------------------------

//------------------------------- Seive Implementation begins -------------------------------------
vector<bool> isPrime(1e6 + 1, 1);
void calculatePrime()
{
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 1e6; i++)
        if (isPrime[i])
            for (int j = i * i; j <= 1e6; j += i)
                isPrime[j] = 0;
}
//------------------------------- Seive Implementation ends ---------------------------------------

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m, 0));

    for (auto &it : v)
    {
        cin >> it;
    }

    for (auto &it : v)
    {
        for (auto &i : it)
        {
            i -= '0';
        }
    }

    vector<vector<int>> poss(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                break;
            }
            if (v[i][j] == 1)
                found = 1;
            if (found)
                poss[i][j] = 1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int found = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j][i] == 0)
            {
                break;
            }
            if (v[j][i] == 1)
                found = 1;
            if (found)
                poss[j][i] = 1;
        }
    }

    bool f = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!poss[i][j] && v[i][j])
            {
                f = 0;
                break;
            }
        }
    }
    if (f)
    {
        Y;
    }
    else
    {
        N;
    }
}
int32_t main()
{
    int tc = 1;
    cin >> tc;
    //   calculatePrime();
    while (tc--)
    {
        solve();
    }
    return 0;
}