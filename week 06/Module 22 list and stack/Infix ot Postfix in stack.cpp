#include <bits/stdc++.h>
using namespace std;

int prec(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 0;
    }
    return 1;
}

int main()
{
    string s;
    cin >> s;
    string ans = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char now = s[i];
        if (now >= 'a' && now <= 'z')
        {
            cout << ans << endl;
            ans += now;
        }
        else
        {
            while (st.size() && prec(st.top()) >= prec(now))
            {
                ans += st.top();
                cout << ans << endl;
                st.pop();
            }
            st.push(now);
        }
    }
    while (st.size())
    {
        ans += st.top();
        st.pop();
    }
    cout << ans << endl;
}

