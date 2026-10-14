#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
vector<pair<int, int>> nums, temp;

void mergeSort(int left, int right)
{
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    int i = left, j = mid + 1, k = left;
    int smaller = 0;

    while (i <= mid && j <= right)
    {
        if (nums[j].first < nums[i].first)
        {
            temp[k++] = nums[j++];
            smaller++;
        }
        else
        {
            ans[nums[i].second] += smaller;
            temp[k++] = nums[i++];
        }
    }

    while (i <= mid) {
        ans[nums[i].second] += smaller;
        temp[k++] = nums[i++];
    }

    while (j <= right)
    {
        temp[k++] = nums[j++];
    }

    for (int p = left; p <= right; p++)
        nums[p] = temp[p];
}

int main() {
    vector<int> a = {5, 2, 6, 1, 2};
    int n = a.size();

    ans.assign(n, 0);
    nums.resize(n);
    temp.resize(n);

    for (int i = 0; i < n; i++)
        nums[i] = {a[i], i};

    if (n > 0)
        mergeSort(0, n - 1);

    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i];
        if (i < n - 1)
        {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}

