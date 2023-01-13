#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        string s, t;
        cin >> s >> t;
        int m = s.length(), n = t.length();
        int idx = 0;
        bool flag = true;
        for (int i = 0; i < m; ++i)
        {
            char c = s[i];
            while (idx < n && t[idx] != s[i])
                idx++;
            if (idx >= n)
            {
                flag = false;
                break;
            }
            idx++;
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}