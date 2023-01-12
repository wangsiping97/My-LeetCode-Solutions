#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<char, double> mass;
    mass['C'] = 12.01;
    mass['H'] = 1.008;
    mass['O'] = 16.00;
    mass['N'] = 14.01;
    unordered_map<char, int> count;
    int kase;
    scanf("%d", &kase);
    char s[100];
    for (int i = 0; i < kase; ++i)
    {
        scanf("%s", s);
        char cur = ' ';
        int cur_count = 0;
        for (int i = 0; i < strlen(s); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                cur_count *= 10;
                cur_count += s[i] - '0';
            }
            else
            {
                if (cur_count > 0)
                {
                    count[cur] += cur_count - 1;
                    cur_count = 0;
                }
                cur = s[i];
                count[cur]++;
            }
        }
        if (cur_count > 0)
        {
            count[cur] += cur_count - 1;
        }
        double ans = 0.0;
        ans += count['C'] * mass['C'];
        ans += count['H'] * mass['H'];
        ans += count['N'] * mass['N'];
        ans += count['O'] * mass['O'];
        printf("%.3lf\n", ans);
        count.clear();
    }
}