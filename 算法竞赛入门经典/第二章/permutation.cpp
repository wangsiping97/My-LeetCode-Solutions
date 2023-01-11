#include <iostream>
using namespace std;

int main()
{
    for (int abc = 100; abc <= 999; ++abc)
    {
        int a = abc / 100, b = abc / 10 % 10, c = abc % 10;
        if ((a == b) || (b == c) || (a == c))
            continue;
        int def = 2 * abc, ghi = 3 * abc;
        if (def > 999 || ghi > 999)
            break;
        int d = def / 100, e = def / 10 % 10, f = def % 10;
        int g = ghi / 100, h = ghi / 10 % 10, i = ghi % 10;
        if (a * b * c * d * e * f * g * h * i == 362880)
        {
            printf("%d %d %d\n", abc, def, ghi);
        }
    }
}