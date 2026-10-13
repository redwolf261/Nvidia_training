#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num, st;
    int k;
    cout<<"enter string and k: "<<endl;
    cin>>num>>k;
    for (int i = 0; i < num.length(); i++)
    {
        while (st.length() > 0 && k > 0 && st.back() > num[i])
        {
            st.pop_back();
            k--;
        }
        st.push_back(num[i]);
    }
    while (k > 0 && st.length() > 0)
    {
        st.pop_back();
        k--;
    }
    int i = 0;
    while (i < st.length() && st[i] == '0')
    {
        i++;
    }
    if (i == st.length())
    {
        cout << "0";
    }
    else
    {
        cout << st.substr(i);
    }
    return 0;
}
