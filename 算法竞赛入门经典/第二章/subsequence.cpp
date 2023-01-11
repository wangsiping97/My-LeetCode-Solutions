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
    int n, m;
    int kase = 0;
    while (fscanf(fin, "%d %d", &n, &m) == 2 && (n > 0 && m > 0))
    {
        double ans = 0;
        for (long long i = n; i <= m; ++i)
        {
            ans += (double)1 / (i * i);
        }
        fprintf(fout, "Case %d: %.5f", ++kase, ans);
    }
}