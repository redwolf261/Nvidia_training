#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    vector<int> nums;
    int n,value,k;
    cout<<"enter number of elements in array: "<<endl;
    cin>>n;
    if(n<=0)
    {
        cout<<"invalid";
        return 0;
    }
    cout<<"enter value of k: "<<endl;
    cin>>k;
    cout<<"enter the elements: "<<endl;
    for(int i=0;i<n;++i)
    {
        cin>>value;
        nums.push_back(value);
    }
    unordered_map<int,int> freq;
    freq[0] =1;
    int prefixsum = 0,counter =0;
    for(int i=0;i<n;++i)
    {
        prefixsum += nums[i];
        counter += freq[prefixsum-k];
        freq[prefixsum]++;
    }
    cout<<"the count is: "<<counter<<endl;

    return 0;
}
