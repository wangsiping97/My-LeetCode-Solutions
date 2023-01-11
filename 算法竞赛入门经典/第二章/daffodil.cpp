#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for (int n = 100; n <= 999; ++n)
    {
        int a = n / 100;
        int b = n / 10 % 10;
        int c = n % 10;
        if (n == pow(a, 3) + pow(b, 3) + pow(c, 3))
        {
            printf("%d\n", n);
        }
    }
}