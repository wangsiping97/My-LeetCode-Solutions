#include <vector> 
#include <deque> 
using namespace std; 

class Solution {
public:
    int N;
    int getRow(int num) {
        int aa = num / N;
        if (num % N == 0) aa--;
        return N - 1 - aa;
    }
    int getCol(int num) {
        int aa = num / N;
        if (num % N == 0) aa--;
        int bb = num % N; 
        if (aa % 2 == 0) return bb == 0 ? N - 1 : bb - 1;
        else return bb == 0 ? 0 : N - bb;
    }
    int snakesAndLadders(vector< vector<int> >& board) {
        N = board.size();
        int level[N * N + 1];
        for (int i = 0; i < N * N + 1; ++i) {
            level[i] = N * N + 1;
        }
        level[1] = 0;
        deque<int> q;
        if (board[N - 1][0] == -1) q.push_back(1);
        else {
            q.push_back(board[N - 1][0]);
            level[board[N - 1][0]] = 0;
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop_front();
            for (int i = 1; i <= 6; ++i) {
                if (front + i > N * N) continue;
                int x = getRow(front + i);
                int y = getCol(front + i);
                if (level[front + i] < N * N + 1 && board[x][y] == -1) continue;
                if (board[x][y] == -1) {
                    q.push_back(front + i);
                    level[front + i] = level[front] + 1;
                }
                else {
                    if (level[board[x][y]] <= level[front] + 1) continue;
                    q.push_back(board[x][y]);
                    level[front + i] = level[front] + 1;
                    level[board[x][y]] = level[front] + 1;
                }
            }
        }
        if (level[N * N] == N * N + 1) return -1;
        return level[N * N];
    }
};