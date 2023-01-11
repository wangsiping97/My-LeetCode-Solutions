#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int cur = 2 * n - 1;
    for (int i = 0; i < n; ++i, cur -= 2)
    {
        for (int k = 0; k < i; ++k)
        {
            printf(" ");
        }
        for (int k = 0; k < cur; ++k)
        {
            printf("#");
            if (k < cur - 1)
            {
                printf(" ");
            }
        }
        for (int k = 0; k < i; ++k)
        {
            printf(" ");
        }
        printf("\n");
    }
}