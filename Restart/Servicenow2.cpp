#include <bits/stdc++.h>
using namespace std;

bool canConstruct(int size, vector<vector<int>> &shops, int m, int k)
{
    long long n = shops.size();
    long long minCost = INT64_MAX;

    for (long long i = 0; i < n; i++)
    {
        for (long long j = i; j < n; j++)
        {
            long long currentCost = 0;

            for (long long t = 0; t < m; t++)
            {
                long long cost1 = ceil((double)size / shops[i][t]);
                long long cost2 = (i == j) ? cost1 : ceil((double)size / shops[j][t]);
                currentCost += min(cost1, cost2);
            }

            if (currentCost <= k)
            {
                minCost = min(minCost, currentCost);
                return true;
            }
        }
    }

    return false;
}

int maxSize(int n, int m, vector<vector<int>> &shops, int k)
{
    long long low = 1, high = 1e8 + 7;
    long long result = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (canConstruct(mid, shops, m, k))
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return result;
}

int main()
{
    long long n = 3, m = 3, k = 11;
    vector<vector<long long>> shops = {{3, 1, 5}, {1, 1, 2}, {2, 2, 2}};

    cout << maxSize(n, m, shops, k) << endl;

    return 0;
}