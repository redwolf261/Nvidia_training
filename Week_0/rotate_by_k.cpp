#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> number;
    int n,value,k;
    cout<<"enter number of elements in array: "<<endl;
    cin>>n;
    cout<<"enter value of k: "<<endl;
    cin>>k;
    if(k>n)
    {
        cout<<"invalid";
        return 0;
    }
    cout<<"enter the elements: "<<endl;
    for(int i=0;i<n;++i)
    {
        cin>>value;
        number.push_back(value);
    }
    reverse(number.begin(),number.end());
    reverse(number.begin(),number.begin()+k);
    reverse(number.begin()+k,number.end());
    cout<<"answer is: "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<number[i]<<endl;
    }
    return 0;
}
