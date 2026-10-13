#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {2, 4, 1, 3, 5};
    int n = a.size();
    vector<int> temp(n);
    long long inv = 0;

    for (int width = 1; width < n; width *= 2)
    {
        for (int left = 0; left < n; left += 2 * width)
        {
            int mid = min(left + width - 1, n - 1);
            int right = min(left + 2 * width - 1, n - 1);

            if (mid >= right) continue;

            int i = left;
            int j = mid + 1;
            int k = left;

            while (i <= mid && j <= right)
            {
                if (a[i] <= a[j])
                {
                    temp[k++] = a[i++];
                }
                else
                {
                    temp[k++] = a[j++];
                    inv += mid - i + 1;
                }
            }
            while (i <= mid)
            {
                temp[k++] = a[i++];
            }
            while (j <= right)
            {
                temp[k++] = a[j++];
            }
            for (int p = left; p <= right; p++)
            {
                a[p] = temp[p];
            }
        }
    }

    cout <<inv<< endl;

    return 0;
}
