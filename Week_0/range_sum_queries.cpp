#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> number,prefix;
    int n,value,k,sum=0,left,right;
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
        number.push_back(value);
        sum+=value;
        prefix.push_back(sum);
    }
    cout<<"enter left and right element of query: "<<endl;
    cin>>left>>right;
    if(left<0 || right > prefix.size() - 1 || right < left)
    {
        cout<<"invalid";
        return 0;
    }
    if(left == 0)
    {
        cout<<"answer is: "<<prefix[right];
        return 0;
    }
    else
    {
        cout<<"answer is: "<<prefix[right] - prefix[left-1]<<endl;
        return 0;
    }

    return 0;
}
