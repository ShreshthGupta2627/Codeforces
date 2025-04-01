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
vector<bool> isPrime(1e7 + 1, 1);
vector<int> primes;
void calculatePrime()
{
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= 1e7 + 1; i++)
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= 1e7 + 1; j += i)
                isPrime[j] = 0;
        }
}
//------------------------------- Seive Implementation ends ---------------------------------------

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    cin >> v;

    vector<int> row(n, 1), col(m, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!v[i][j])
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    vector<vector<int>> c(n, vector<int>(m, 1));

    for (int i = 0; i < n; i++)
    {
        if (!row[i])
        {
            for (int j = 0; j < m; j++)
            {
                c[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (!col[i])
        {
            for (int j = 0; j < n; j++)
            {
                c[j][i] = 0;
            }
        }
    }

    vector<vector<int>> ans = c;

    vector<int> r1(n, 0), c1(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i][j])
            {
                r1[i] = 1;
                c1[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (r1[i])
        {
            for (int j = 0; j < m; j++)
            {
                c[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (c1[i])
        {
            for (int j = 0; j < n; j++)
            {
                c[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i][j] != v[i][j])
            {
                N;
                return;
            }
        }
    }

    Y;
    for (auto &it : ans)
    {
        cout << it << endl;
    }
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