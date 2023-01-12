#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int kase;
    scanf("%d", &kase);
    for (int i = 0; i < kase; ++i)
    {
        char s[100];
        scanf("%s", s);
        int l = strlen(s);
        int k = 1;
        for (; k < l; ++k)
        {
            if (l % k != 0)
                continue;
            bool flag = true;
            for (int j = 0; j < l - k; ++j)
            {
                if (s[j] != s[j + k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                printf("%d\n", k);
                break;
            }
        }
        if (k == l)
        {
            printf("%d\n", k);
        }
        if (i < kase - 1)
            printf("\n");
    }
}