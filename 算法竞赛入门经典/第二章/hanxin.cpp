#include <iostream>
using namespace std;

int main()
{
    FILE *fin, *fout;
#ifdef LOCAL
    fin = stdin;
    fout = stdout;
#else
    fin = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");
#endif
    int a, b, c;
    int kase = 0;
    while (fscanf(fin, "%d %d %d", &a, &b, &c) == 3)
    {
        int ans = 10;
        for (ans = 10; ans <= 100; ++ans)
        {
            if (ans % 3 == a && ans % 5 == b && ans % 7 == c)
            {
                break;
            }
        }
        if (ans == 101)
        {
            fprintf(fout, "Case %d: No answer\n", ++kase);
        }
        else
        {
            fprintf(fout, "Case %d: %d\n", ++kase, ans);
        }
    }
}