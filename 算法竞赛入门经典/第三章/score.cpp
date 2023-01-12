#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int kase;
    scanf("%d", &kase);
    char s[100];
    for (int i = 0; i < kase; ++i)
    {
        int score = 0;
        int o_count = 0;
        scanf("%s", s);
        for (int i = 0; i < strlen(s); ++i)
        {
            if (s[i] == 'X')
            {
                o_count = 0;
            }
            else if (s[i] == 'O')
            {
                o_count++;
                score += o_count;
            }
        }
        printf("%d\n", score);
    }
}