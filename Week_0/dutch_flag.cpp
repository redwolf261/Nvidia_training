#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> nums;
    int n,value,temp;
    cout<<"enter number of elements in array: "<<endl;
    cin>>n;
    if(n<=0)
    {
        cout<<"invalid";
        return 0;
    }
    cout<<"enter the elements: "<<endl;
    for(int i=0;i<n;++i)
    {
        cin>>value;
        nums.push_back(value);
    }
    int low = 0,mid = 0,high= nums.size() - 1;
    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid],nums[high]);
            high--;
        }
    }
    cout<<"answer is: "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<nums[i]<<endl;
    }

    return 0;
}
