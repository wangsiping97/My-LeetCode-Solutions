#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int kase;
    cin >> kase;
    vector<string> DNAs;
    unordered_map<char, int> count_map;
    const char DNA[] = {'T', 'G', 'C', 'A'};
    for (int i = 0; i < kase; ++i)
    {
        int m, n;
        cin >> m >> n;
        DNAs.clear();
        for (int j = 0; j < m; ++j)
        {
            string in;
            cin >> in;
            DNAs.push_back(in);
        }
        string ans;
        int hamming = 0;
        for (int j = 0; j < n; ++j)
        {
            count_map.clear();
            for (int k = 0; k < m; ++k)
            {
                count_map[DNAs[k][j]]++;
            }
            int max = count_map[DNA[0]];
            char temp_ans = DNA[0];
            for (int k = 1; k < 4; ++k)
            {
                if (count_map[DNA[k]] >= max)
                {
                    max = count_map[DNA[k]];
                    temp_ans = DNA[k];
                }
            }
            ans.push_back(temp_ans);
            hamming += (m - max);
        }
        printf("%s\n%d\n", ans.c_str(), hamming);
    }
}