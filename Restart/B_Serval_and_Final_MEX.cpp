//                                        ॐ हनुमंते नमः
#include <bits/stdc++.h>
#define int long long int
#define countOnBit __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
#define Y cout << 'YES' << endl;
#define N cout << 'NO' << endl;
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
    int n;
    cin >> n;

    vector<int> v(n);
    cin >> v;

    int z = 0, idx = -1, idx1 = -1;

    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            z++;
            if (idx != -1)
            {
                idx1 = i;
            }
            idx = i;
        }
    }
    if (z == 0)
    {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
    }
    else if (z == 1)
    {
        if (idx == 0)
        {
            cout << 2 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 2 << " " << n << endl;
        }
        else if (idx == n - 1)
        {
            cout << 3 << endl;
            cout << n - 1 << " " << n << endl;
            cout << 1 << " " << n - 2 << endl;
            cout << 1 << " " << 2 << endl;
        }
        else
        {
            cout << 3 << endl;
            cout << idx << " " << idx + 1 << endl;
            cout << 2 << " " << n - 1 << endl;
            cout << 1 << " " << 2 << endl;
        }
    }
    else if (z == n)
    {
        cout << 3 << endl;
        cout << 1 << " " << (z + 1) / 2 << endl;
        cout << (z + 1) / 2 + 1 << " " << n << endl;
        cout << 1 << " " << 2 << endl;
    }
    else
    {
        vector<pair<int, int>> ans;

        for (int i = 0; i < n; i++)
        {
            int s = i;
            int j = i;

            while (j < n && v[j] == 0)
            {
                j++;
            }

            if (j < n)
            {
                ans.push_back({i + 1, j});
            }
            else
            {
                ans.push_back({i + 1, j + 1});
            }
            i = j;
        }

        cout << ans.size() + 1 << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
        cout << 1 << " " << n - z + ans.size() + 1 << endl;
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