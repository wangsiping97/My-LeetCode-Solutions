#include <iostream>
#include <cmath>
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
    while (fscanf(fin, "%d %d %d", &a, &b, &c) == 3 && (a > 0 && b > 0 && c > 0))
    {

        fprintf(fout, "Case %d: %.*f", ++kase, c, (double)a / b);
    }
}