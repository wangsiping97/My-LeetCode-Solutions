#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void solve(vector<string> &grid, int row, int col)
{
    // find definitions
    vector<vector<int>> indices;
    int index = 1;
    for (int i = 0; i < row + 1; ++i)
    {
        vector<int> temp_vec;
        if (i < row)
            for (int j = 0; j < col + 1; ++j)
            {
                if (j == col)
                    temp_vec.push_back(-1);
                else if (grid[i][j] == '*')
                    temp_vec.push_back(-1);
                else if (i == 0 || j == 0)
                {
                    temp_vec.push_back(index);
                    index++;
                }
                else if (grid[i - 1][j] == '*' || grid[i][j - 1] == '*')
                {
                    temp_vec.push_back(index);
                    index++;
                }
                else
                {
                    temp_vec.push_back(0);
                }
            }
        else
            for (int j = 0; j < col + 1; ++j)
                temp_vec.push_back(-1);
        indices.push_back(temp_vec);
    }
    printf("Across\n");
    for (int i = 0; i < row; ++i)
    {
        int start_pos = 0, end_pos = 0;
        while (start_pos < col)
        {
            while ((start_pos < col) && (indices[i][start_pos] <= 0))
                start_pos++;
            if (start_pos == col)
                break;
            end_pos = start_pos + 1;
            while ((end_pos < col + 1) && (indices[i][end_pos] >= 0))
                end_pos++;
            printf("%3d.", indices[i][start_pos]);
            for (int k = start_pos; k < end_pos; ++k)
            {
                printf("%c", grid[i][k]);
            }
            printf("\n");
            start_pos = end_pos + 1;
        }
    }
    printf("Down\n");
    map<int, string> ans_map;
    for (int j = 0; j < col; ++j)
    {
        int start_pos = 0, end_pos = 0;
        while (start_pos < row)
        {
            while (start_pos < row && indices[start_pos][j] <= 0)
                start_pos++;
            if (start_pos == row)
                break;
            end_pos = start_pos + 1;
            while (end_pos < row + 1 && indices[end_pos][j] >= 0)
                end_pos++;
            string ans;
            for (int k = start_pos; k < end_pos; ++k)
                ans.push_back(grid[k][j]);
            ans_map[indices[start_pos][j]] = ans;
            start_pos = end_pos + 1;
        }
    }
    map<int, string>::iterator iter = ans_map.begin();
    for (; iter != ans_map.end(); iter++)
        printf("%3d.%s\n", iter->first, iter->second.c_str());
}

int main()
{
    int kase = 0;
    int row, col;
    vector<string> grid;
    while (cin >> row && row != 0)
    {
        kase++;
        cin >> col;
        string in;
        grid.clear();
        for (int i = 0; i < row; ++i)
        {
            cin >> in;
            grid.push_back(in);
        }
        if (kase > 1)
            printf("\n");
        printf("puzzle #%d:\n", kase);
        solve(grid, row, col);
    }
}