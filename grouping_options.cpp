#include <iostream>
using namespace std;

long memo[201][201][201];

long dfs(int people, int groups, int last, long memo[][201][201]) {
    if (groups == 0) {
        if (people == 0) {
            memo[last][people][groups]++;
        }
        return memo[last][people][groups];
    }
    int max = people / groups;
    for (int cur = last; cur <= max; ++cur) {
        if (memo[cur][people - cur][groups - 1] == 0){
            memo[cur][people - cur][groups - 1] = dfs(people - cur, groups - 1, cur, memo);
        } 
        memo[last][people][groups] += memo[cur][people - cur][groups - 1];
    }
    return memo[last][people][groups];
}

long countOptions(int people, int groups) {
    if (people * groups == 0) return 0;
    for (int i = 0; i < 201; ++i) {
        for (int j = 0; j < 201; ++j) 
            memset(memo[i][j], 0, 201 * sizeof(long));
    }
    long ans = 0;
    int max = people / groups;
    
    for (int cur = 1; cur <= max; ++cur){
        ans += dfs(people - cur, groups - 1, cur, memo);
    }
    return ans;
}


int main() {
    cout << countOptions(8, 4) << endl;
    cout << countOptions(100, 4) << endl;
    cout << countOptions(50, 4) << endl;
    cout << countOptions(200, 100) << endl;
}