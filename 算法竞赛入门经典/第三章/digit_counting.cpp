#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    int kase;
    cin >> kase;
    unordered_map<int, int> ans;
    for (int i = 0; i < kase; ++i)
    {
        int n;
        cin >> n;
        ans.clear();
        for (int j = 1; j <= n; ++j)
        {
            string s = to_string(j);
            for (char c : s)
            {
                ans[c - '0']++;
            }
        }
        for (int j = 0; j <= 9; ++j)
        {
            if (j == 0)
            {
                cout << ans[j];
            }
            else
            {
                cout << " " << ans[j];
            }
        }
        cout << endl;
    }
}