// A string can be abbreviated by replacing any number of non-adjacent
// substrings with their lengths. For example, a string such as "substitution"
// could be abbreviated as (but not limited to):

// "s10n" ("s ubstitutio n")
// "sub4u4" ("sub stit u tion")
// "12" ("substitution")
// "su3i1u2on" ("su bst i t u ti on")
// "substitution" (no substrings replaced)
// Note that "s55n" ("s ubsti tutio n") is not a valid abbreviation of
// "substitution" because the replaced substrings are adjacent.

// The length of an abbreviation is the number of letters that were not replaced
// plus the number of substrings that were replaced. For example, the
// abbreviation "s10n" has a length of 3 (2 letters + 1 substring) and
// "su3i1u2on" has a length of 9 (6 letters + 3 substrings).

// Given a target string target and an array of strings dictionary, return an
// abbreviation of target with the shortest possible length such that it is not
// an abbreviation of any string in dictionary. If there are multiple shortest
// abbreviations, return any of them.

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int min_length = 22;
  string ans;
  vector<int> tmp_ans;  // which idxes of target are kept
  int get_length(string& target) {
    if (tmp_ans.empty()) return 1;
    int count = 0;
    int last = -1;
    for (int idx : tmp_ans) {
      if (idx - last > 1) count++;
      last = idx;
    }
    if (last < target.size() - 1) count++;
    count += tmp_ans.size();
    return count;
  }
  string build_ans(string& target) {
    string ans;
    int last = -1;
    for (int idx : tmp_ans) {
      if (idx - last > 1) {
        ans += to_string(idx - last - 1);
      }
      ans.push_back(target[idx]);
      last = idx;
    }
    if (last < target.length() - 1) {
      ans += to_string(target.length() - last - 1);
    }
    return ans;
  }
  void dfs(string& target, int idx, vector<string>& dict, bool new_tmp) {
    if (new_tmp) {
      // count tmp_ans length
      int l = get_length(target);
      if (l >= min_length) {
        return;
      }
      bool all_valid = true;
      for (string word : dict) {
        bool valid = false;
        for (int i : tmp_ans) {
          if (word[i] != target[i]) {
            valid = true;
            break;
          }
        }
        if (!valid) {
          // tmp_ans is invalid
          all_valid = false;
          break;
        }
      }
      if (all_valid) {
        min_length = l;
        // build new ans
        ans = build_ans(target);
        return;
      }
    }
    if (idx == target.length()) {
      return;
    }
    // not keep
    dfs(target, idx + 1, dict, false);
    // keep
    tmp_ans.push_back(idx);
    dfs(target, idx + 1, dict, true);
    tmp_ans.pop_back();
  }
  string minAbbreviation(string target, vector<string>& dictionary) {
    vector<string> dict;
    int l = target.length();
    for (string word : dictionary) {
      if (word.length() == l) {
        dict.push_back(word);
      }
    }
    if (dict.empty()) {
      return to_string(l);
    }
    dfs(target, 0, dict, false);
    return ans;
  }
};