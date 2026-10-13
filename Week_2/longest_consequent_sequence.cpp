#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> red;
    int n,value;
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
        red.push_back(value);
    }
    sort(red.begin(),red.end());
    int maximum=1,counter=1,indexer;
    for(int i=1;i<red.size();++i)
    {
        if(red[i]-red[i-1]==1)
        {
            counter++;
            if(counter>maximum)
            {
                maximum = counter;
                indexer = i;
            }
        }
        else
        {
            counter = 1;
        }
    }
    cout<<"the length is: "<<maximum<<endl;
    for(int i=indexer-maximum+1;i<indexer+1;++i)
    {
        cout<<red[i]<<endl;
    }

    return 0;
}
