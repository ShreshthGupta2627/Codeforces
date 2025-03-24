#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
    vector<int> tree, lazy;
    int size;

public:
    SegmentTree(int n)
    {
        size = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    void propagate(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
            tree[node] += lazy[node];
            if (start != end)
            {
                lazy[node * 2 + 1] += lazy[node];
                lazy[node * 2 + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void updateRange(int l, int r, int value, int node = 0, int start = 0, int end = -1)
    {
        if (end == -1)
            end = size - 1;

        propagate(node, start, end);
        if (start > r || end < l)
            return;

        if (l <= start && end <= r)
        {
            lazy[node] += value;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(l, r, value, node * 2 + 1, start, mid);
        updateRange(l, r, value, node * 2 + 2, mid + 1, end);
        tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
    int queryMax(int l, int r, int node = 0, int start = 0, int end = -1)
    {
        if (end == -1)
            end = size - 1;
        propagate(node, start, end);
        if (start > r || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        int left = queryMax(l, r, node * 2 + 1, start, mid);
        int right = queryMax(l, r, node * 2 + 2, mid + 1, end);
        return max(left, right);
    }
};
vector<int> satelliteCoverage(vector<pair<int, int>> &arr, vector<pair<int, int>> &queries)
{
    set<int> points;
    for (auto &[start, end] : arr)
    {
        points.insert(start);
        points.insert(end + 1);
    }
    for (auto &[q_start, q_end] : queries)
    {
        points.insert(q_start);
        points.insert(q_end + 1);
    }

    vector<int> sorted_points(points.begin(), points.end());
    map<int, int> coord_map;
    for (int i = 0; i < sorted_points.size(); ++i)
    {
        coord_map[sorted_points[i]] = i;
    }

    int size = sorted_points.size();

    SegmentTree segTree(size);

    for (auto &[start, end] : arr)
    {
        segTree.updateRange(coord_map[start], coord_map[end + 1] - 1, 1);
    }

    vector<int> coverage(size, 0);
    for (int i = 0; i < size - 1; ++i)
    {
        int point_coverage = segTree.queryMax(i, i);
        coverage[point_coverage] += sorted_points[i + 1] - sorted_points[i];
    }

    vector<int> results;
    for (auto &[q_start, q_end] : queries)
    {
        int max_P = 0;
        for (int x = q_start; x <= q_end; ++x)
        {
            if (x < coverage.size())
            {
                max_P = max(max_P, coverage[x]);
            }
        }
        results.push_back(max_P);
    }

    return results;
}

// int main()
// {
//     vector<pair<int, int>> arr = {{2, 3}, {3, 4}, {5, 5}, {3, 4}};
//     vector<pair<int, int>> queries = {{1, 2}, {3, 4}};

//     vector<int> results = solveSatelliteProblem(arr, queries);

//     for (int res : results)
//     {
//         cout << res << endl;
//     }

//     return 0;
// }
