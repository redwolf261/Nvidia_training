#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a = {2, -1, 2, -1, 2, 3};
    int K = 5;
    int n = a.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + a[i];
    }
    deque<int> dq;
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++)
    {
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= K)
        {
            ans = min(ans, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefix[i] <= prefix[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    if (ans == INT_MAX)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
    return 0;
}
