// Given a string num that contains only digits and an integer target, return
// all possibilities to insert the binary operators '+', '-', and/or '*' between
// the digits of num so that the resultant expression evaluates to the target
// value.

// Note that operands in the returned expressions should not contain leading
// zeros.

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> ans;
  int t;
  bool valid(vector<char>& str) {
    int l = str.size();
    for (int i = -1; i < l - 2; ++i) {
      if (i <= 0 || str[i] == '+' || str[i] == '-' || str[i] == '*') {
        if (str[i + 1] == '0' && str[i + 2] >= '0' && str[i + 2] <= '9')
          return false;
      }
    }
    return true;
  }
  void dfs(string& num, int idx, long long sum, long long mul, long long cur,
           string& expr) {
    if (idx == num.length()) {
      sum += mul * cur;
      if (sum == t) {
        ans.push_back(expr);
      }
      return;
    }
    int v = num[idx] - '0';
    cur *= 10;
    cur += v;
    expr.push_back(num[idx]);
    // check valid
    if (expr.length() == 2) {
      if (expr[0] == '0' && expr[1] >= '0' && expr[1] <= '9') {
        expr.pop_back();
        return;
      }
    }
    if (expr.length() > 2) {
      if (expr[expr.length() - 2] == '0' &&
          (expr[expr.length() - 3] < '0' || expr[expr.length() - 3] > '9')) {
        expr.pop_back();
        return;
      }
    }
    // if no op
    dfs(num, idx + 1, sum, mul, cur, expr);
    if (idx < num.length() - 1) {
      // if +
      expr.push_back('+');
      dfs(num, idx + 1, sum + mul * cur, 1, 0, expr);
      expr.pop_back();
      // if -
      expr.push_back('-');
      dfs(num, idx + 1, sum + mul * cur, -1, 0, expr);
      expr.pop_back();
      // if *
      expr.push_back('*');
      dfs(num, idx + 1, sum, mul * cur, 0, expr);
      expr.pop_back();
    }
    expr.pop_back();
  }
  vector<string> addOperators(string num, int target) {
    t = target;
    int l = num.length();
    if (l == 0) return ans;
    string expr;
    dfs(num, 0, 0, 1, 0, expr);
    return ans;
  }
};

// Solution: dfs with fast eval()
// Fast eval: sum  |  mul  |  cur
// When '+': sum += mul * cur; mul = 1; cur = 0;
// When '-': sum += mul * cur; mul = -1; cur = 0;
// When '*': mul *= cur; cur = 0;
// When end: sum += mul * cur;
// Other: cur *= 10; cur += c - '0'