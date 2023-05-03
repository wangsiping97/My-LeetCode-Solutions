// Given an equation, represented by words on the left side and the result on
// the right side.

// You need to check if the equation is solvable under the following rules:

// Each character is decoded as one digit (0 - 9).
// No two characters can map to the same digit.
// Each words[i] and result are decoded as one number without leading zeros.
// Sum of numbers on the left side (words) will equal to the number on the right
// side (result). Return true if the equation is solvable, otherwise return
// false.

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int solution[256];
  bool used[10];
  int x_limit, y_limit;

  bool dfs(vector<string> &words, string &result, int x, int y, int delta) {
    if (x == x_limit) {
      return true;
    }
    if (y == y_limit - 1) {
      int sum = delta;
      for (string word : words) {
        if (x >= word.length()) continue;
        sum += solution[word[word.length() - 1 - x]];
      }
      char s = result[result.length() - 1 - x];
      delta = sum / 10;
      sum %= 10;
      if (x == x_limit - 1) {
        if (delta > 0) return false;
        if (sum == 0) return false;
      }
      if (solution[s] == -1 && used[sum] == false) {
        used[sum] = true;
        solution[s] = sum;
        if (dfs(words, result, x + 1, 0, delta)) return true;
        solution[s] = -1;
        used[sum] = false;
      } else if (solution[s] == sum) {
        return dfs(words, result, x + 1, 0, delta);
      } else {
        return false;
      }
    } else {
      string word = words[y];
      if (x >= word.length()) return dfs(words, result, x, y + 1, delta);
      char s = word[word.length() - 1 - x];
      int start = 0;
      if (x == word.length() - 1 && x > 0) {
        if (solution[s] == 0) return false;
        start = 1;
      }
      if (solution[s] != -1) return dfs(words, result, x, y + 1, delta);
      for (int i = start; i <= 9; ++i) {
        if (used[i] == false) {
          used[i] = true;
          solution[s] = i;
          if (dfs(words, result, x, y + 1, delta)) return true;
          solution[s] = -1;
          used[i] = false;
        }
      }
    }
    return false;
  }

  bool isSolvable(vector<string> &words, string result) {
    int max_len = 0, count = 0;
    for (string word : words) {
      for (char c : word) {
        if (solution[c] != -1) {
          solution[c] = -1;
          count++;
        }
      }
      max_len = max(max_len, int(word.length()));
    }
    for (char c : result) {
      if (solution[c] != -1) {
        solution[c] = -1;
        count++;
      }
    }

    if (count > 10 || max_len > result.length()) return false;

    for (int i = 0; i <= 9; ++i) used[i] = false;

    x_limit = result.length();
    y_limit = words.size() + 1;
    return dfs(words, result, 0, 0, 0);
  }
};

// Solution
// 二维 dfs 以竖式计算的方式