#include <iostream>
#include <string>
#include <vector>
using namespace std;

void invalid()
{
    cout << "This puzzle has no final configuration." << endl;
}

void solve(vector<string> &grid, string &moves, int kase)
{
    int pos_y = -1, pos_x = -1;
    for (int y = 0; y < 5; ++y)
    {
        for (int x = 0; x < 5; ++x)
        {
            if (grid[y][x] == ' ')
            {
                pos_y = y;
                pos_x = x;
                break;
            }
        }
    }
    if (pos_y == -1 || pos_x == -1)
    {
        invalid();
        return;
    }
    for (char c : moves)
    {
        int target_y;
        int target_x;
        if (c == 'A')
        {
            target_y = pos_y - 1;
            target_x = pos_x;
        }
        else if (c == 'B')
        {
            target_y = pos_y + 1;
            target_x = pos_x;
        }
        else if (c == 'L')
        {
            target_y = pos_y;
            target_x = pos_x - 1;
        }
        else if (c == 'R')
        {
            target_y = pos_y;
            target_x = pos_x + 1;
        }
        else
        {
            invalid();
            return;
        }
        if (target_y < 0 || target_y >= 5 || target_x < 0 || target_x >= 5)
        {
            invalid();
            return;
        }
        grid[pos_y][pos_x] = grid[target_y][target_x];
        grid[target_y][target_x] = ' ';
        pos_y = target_y;
        pos_x = target_x;
    }
    // output result
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (j == 0)
                printf("%c", grid[i][j]);
            else
                printf(" %c", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    string in;
    vector<string> grid;
    int count = 0;
    int kase = 0;
    while (getline(cin, in) && in != "Z")
    {
        count++;
        if (count == 6)
        {
            kase++;
            if (kase > 1)
                printf("\n");
            printf("Puzzle #%d:\n", kase);
            string append;
            while (in.back() != '0')
            {
                getline(cin, append);
                in = in + append;
            }
            in.pop_back();
            solve(grid, in, kase);
            count = 0;
            grid.clear();
        }
        else
        {
            grid.push_back(in);
        }
    }
}