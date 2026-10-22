#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> nums;
    stack<int> st;
    int n,value;
    cout<<"enter number of elements: "<<endl;
    cin>>n;
    if(n<=0)
    {
        cout<<"invalid"<<endl;
        return 0;
    }
    cout<<"enter the elements: "<<endl;
    for(int i=0;i<n;++i)
    {
        cin>>value;
        nums.push_back(value);
    }
    int maxArea = 0;
    for (int i=0; i<=n; ++i)
    {
        int currentHeight = (i == n) ? 0 : nums[i];

        while (!st.empty() && currentHeight< nums[st.top()])
        {

            int index=st.top();
            st.pop();

            int height=nums[index];
            int width;

            if (st.empty())
            {
                width = i;
            }
            else
            {
                width = i-st.top()-1;
            }

            int area = height*width;
            maxArea = max(maxArea, area);
        }

        st.push(i);
    }

    cout <<"answer: "<<maxArea<<endl;

    return 0;
}
